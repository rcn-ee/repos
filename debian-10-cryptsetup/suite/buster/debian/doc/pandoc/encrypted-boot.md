% Full disk encryption, including `/boot`: Unlocking LUKS devices from GRUB

Introduction
============

So called “full disk encryption” is often a misnomer, because there is
typically a separate plaintext partition holding `/boot`.  For instance
the Debian Installer does this in its “encrypted LVM” partitioning method.
Since not all bootloaders are able to unlock _LUKS_ devices, a plaintext
`/boot` is the only solution that works for all of them.

Since Jessie GRUB2 has been able to unlock LUKS devices with a new
[`cryptomount`](https://www.gnu.org/software/grub/manual/grub/html_node/cryptomount.html)
command, hence enabling encryption of the `/boot` partition as well.
(As unlocking happens before booting the kernel, that feature is not
compatible with remote unlocking.)

Enabling unlocking LUKS devices from GRUB [isn't exposed to the d-i
interface](https://bugs.debian.org/814798) (as of Buster), hence people
have come up with various custom work-arounds.  But since the Buster
release [`cryptsetup`(8)] defaults to a new [LUKS header format
version](https://gitlab.com/cryptsetup/LUKS2-docs), which isn't
supported by GRUB as of 2.04.
(There is a [ticket open](https://savannah.gnu.org/bugs/?55093) in
GRUB's upstream bug tracker.)  _Hence the old custom work-around won't
work anymore_.  Until LUKS _version 2_ support is added to GRUB2, the
devices holding `/boot` need to be in _LUKS version 1_ to be unlocked
from the boot loader.

This document describes a generic way to unlock LUKS devices from GRUB
for Debian Buster.


Encrypting the device holding `/boot`
=====================================

There are two alternatives here:

  * Either format an existing `/boot` partition to LUKS1; or
  * Move `/boot` to the root file system.  The root device(s) needs to
    use LUKS version 1, but existing LUKS2 devices can be converted
    (in-place) to LUKS1 if desired.

These two alternatives are described in the two following sub-sections.


Formatting the existing `/boot` partition to LUKS1
--------------------------------------------------

Since the installer creates a separate (cleartext) `/boot` partition by
default in its “encrypted LVM” partitioning method, the simplest solution
is arguably to re-format it as LUKS1.

That way other partitions, including the one holding the root file
system, can remain in LUKS2 format and benefit from the stronger
security guaranties of the newer version: more secure (memory-hard) Key
Derivation Function, backup header, ability to offload the volume key
offload to the kernel keyring (thus preventing access from userspace),
custom sector size, persistent flags, unattended unlocking via kernel
keyring tokens, etc.

Furthermore every command in this sub-section can be run in the main
system, no need to run anything from a live CD or an initramfs shell.

Before copying content of the `/boot` directory, remount it read-only to
make sure data is not modified while it's being copied:

    root@debian:~$ mount -oremount,ro /boot

Then archive the directory elsewhere (on another device), and unmount it
afterwards:

    root@debian:~$ install -m0600 /dev/null /tmp/boot.tar
    root@debian:~$ tar -C /boot --acls --xattrs -cf /tmp/boot.tar .
    root@debian:~$ umount /boot

Optionally, wipe out the underlying block device (assumed to be
`/dev/sda1` in the rest of this sub-section):

    root@debian:~$ dd if=/dev/urandom of=/dev/sda1 bs=1M
    dd: error writing '/dev/sda1': No space left on device
    244+0 records in
    243+0 records out
    254803968 bytes (255 MB, 243 MiB) copied, 1.70967 s, 149 MB/s

Format the underlying block device to LUKS1 (note the `--type luks1`
in the command below, as Buster's [`cryptsetup`(8)] defaults to LUKS2):

    root@debian:~$ cryptsetup luksFormat --type luks1 /dev/sda1

    WARNING!
    ========
    This will overwrite data on /dev/sda1 irrevocably.

    Are you sure? (Type uppercase yes): YES
    Enter passphrase for /dev/sda1:
    Verify passphrase:

Add a corresponding entry to [`crypttab`(5)] with mapped device name
`boot_crypt`, and open it afterwards:

    root@debian:~$ uuid="$(blkid -o value -s UUID /dev/sda1)"
    root@debian:~$ echo "boot_crypt UUID=$uuid none luks" | tee -a /etc/crypttab
    root@debian:~$ cryptdisks_start boot_crypt
    Starting crypto disk...boot_crypt (starting)...
    Please unlock disk boot_crypt:  ********
    boot_crypt (started)...done.

Now create a file system on the mapped device.  Assuming source device
for `/boot` is specified by its UUID in the [`fstab`(5)] -- which the
Debian Installer does by default -- reusing the old UUID avoids editing
the file.

    root@debian:~$ grep /boot /etc/fstab
    # /boot was on /dev/sda1 during installation
    UUID=c104749f-a0fa-406c-9e9a-3fc01f8e2f78 /boot           ext2    defaults        0       2
    root@debian:~$ mkfs.ext2 -m0 -U c104749f-a0fa-406c-9e9a-3fc01f8e2f78 /dev/mapper/boot_crypt
    mke2fs 1.44.5 (15-Dec-2018)
    Creating filesystem with 246784 1k blocks and 61752 inodes
    Filesystem UUID: c104749f-a0fa-406c-9e9a-3fc01f8e2f78
    […]

Finally, mount `/boot` again from [`fstab`(5)], and copy the saved tarball
to the new (and now encrypted) file system.

    root@debian:~$ mount -v /boot
    mount: /dev/mapper/boot_crypt mounted on /boot.
    root@debian:~$ tar -C /boot -xf /tmp/boot.tar

You can skip the next sub-section and go directly to [Enabling
`cryptomount` in GRUB2].


Moving `/boot` to the root file system
--------------------------------------

The [above sub-section][Formatting the existing `/boot` partition to LUKS1]
described how to to re-format the `/boot` partition as LUKS1.
Alternatively, it can be moved to the root file system, assuming the
latter is not held by any LUKS2 device.  (As shown below, LUKS2 devices
created with default parameters can be “downgraded” to LUKS1.)

The advantage of this method is that the original `/boot` partition can
be preserved and used in case of disaster recovery (if for some reason
the GRUB image is lacking the `cryptodisk` module and the original
plaintext `/boot` partition is lost, you'd need to boot from a live CD
to recover).  Moreover increasing the number of partitions increases
usage pattern visibility: a separate `/boot` partitions, although
encrypted, will likely leak the fact that a kernel update took place to
an attacker with access to pre- and post-update snapshots.

On the other hand, the inconvenient of that method is that the root file
system can't benefit from the nice LUKS2 improvements over LUKS1, as
listed above.  Another minor inconvenient is that space that was
occupied by the former `/boot` partition becomes unused and can't easily
be reclaimed by the root file system.

### Downgrading LUKS2 to LUKS1 ###

Check the LUKS format version on the root device (assumed to be
`/dev/sda3` in the rest of this sub-section):

    root@debian:~$ cryptsetup luksDump /dev/sda3 | grep -A1 "^LUKS"
    LUKS header information
    Version:        2

Here the LUKS format version is 2, so the device needs to be converted
to LUKS _version 1_ to be able to unlock from GRUB.  Unlike the remaining
of this document, the conversion can't be done on an open device, so
you'll need to use a live CD, or append `break` to the kernel
command-line to break to an initramfs shell.

Run `cryptsetup convert --type luks1 DEVICE` to downgrade.  However if
the device was created with the default parameters the in-place
conversion will fail:

    root@debian:~$ cryptsetup convert --type luks1 /dev/sda3

    WARNING!
    ========
    This operation will convert /dev/sda3 to LUKS1 format.


    Are you sure? (Type uppercase yes): YES
    Cannot convert to LUKS1 format - keyslot 0 is not LUKS1 compatible.

This is because its first key slot uses Argon2 as Password-Based Key
Derivation Function (PBKDF) algorithm:

    root@debian:~$ cryptsetup luksDump /dev/sda3 | grep PBKDF:
            PBKDF:      argon2i

Argon2 is a memory-hard function that was selected as the winner of the
Password-Hashing Competition; LUKS2 devices use it by default, but
LUKS1's only supported PBKDF algorithm is PKBDF2.  Hence the key slot
has to be converted to PKBDF2 prior to LUKS format version downgrade.

    root@debian:~$ cryptsetup luksChangeKey --key-slot 0 --pbkdf pbkdf2 /dev/sda3
    Enter passphrase to be changed:
    Enter new passphrase:
    Verify passphrase:

(You can reuse the existing passphrase in the above prompts.)  Now that
all keyslots use the PBKDF2 algorithm, the device shouldn't have any
remaining LUKS2-only features, and can be converted to LUKS1.

    root@debian:~$ cryptsetup luksDump /dev/sda3 | grep PBKDF:
            PBKDF:      pbkdf2
    root@debian:~$ cryptsetup convert --type luks1 /dev/sda3

    WARNING!
    ========
    This operation will convert /dev/sda3 to LUKS1 format.


    Are you sure? (Type uppercase yes): YES
    root@debian:~$ cryptsetup luksDump /dev/sda3 | grep -A1 ^LUKS
    LUKS header information

### Moving `/boot` to the root file system ###

(The moving itself can be done from the normal system, no need to use a
live CD or an initramfs shell.)

To ensure data is not modified while it's being copied, remount `/boot`
read-only:

    root@debian:~$ mount -oremount,ro /boot

Then recursively copy the directory to the root file system, and replace
the old `/boot` mountpoint with the new directory.

    root@debian:~$ cp -aT /boot /boot.tmp
    root@debian:~$ umount /boot
    root@debian:~$ rmdir /boot
    root@debian:~$ mv -T /boot.tmp /boot

Comment out the fstab(5) entry for the `/boot` mountpoint, otherwise
at reboot `init`(1) will mount it hence shadow data in the new `/boot`
directory with data from the plaintext partition.

    root@debian:~$ grep /boot /etc/fstab
    ## /boot was on /dev/sda1 during installation
    #UUID=c104749f-a0fa-406c-9e9a-3fc01f8e2f78 /boot           ext2    defaults        0       2


Enabling `cryptomount` in GRUB2
===============================

Enable the feature and update the GRUB image:

    root@debian:~$ echo "GRUB_ENABLE_CRYPTODISK=y" >>/etc/default/grub
    root@debian:~$ echo "GRUB_PRELOAD_MODULES=\"luks cryptodisk\"" >>/etc/default/grub
    root@debian:~$ update-grub
    root@debian:~$ grub-install /dev/sda

If everything went well, `/boot/grub/grub.cfg` should contain `insmod
cryptodisk` (and also `insmod lvm` if `/boot` is on a Logical Volume).


Avoiding the extra password prompt
==================================

The device holding the kernel (and the initramfs image) is unlocked by
GRUB, but the root device needs to be unlocked again at initramfs stage,
regardless whether it's the same device or not.  This is because GRUB
boots with the given `vmlinuz` and initramfs images, but there currently
is no way to securely pass cryptographic material (or Device Mapper
information) to the kernel.  Hence the Device Mapper table is initially
empty at initramfs stage; in other words, all devices are locked, and
the root device needs to be unlocked again.

To avoid extra passphrase prompts at initramfs stage, a work around is
to unlock via key files stored into the initramfs image.  Since the
initramfs image itself now resides on an encrypted device, this still
provides protection for data at rest.  With LUKS1 the volume key can
already be found by userspace in the Device Mapper table, so including
key files to the initramfs image -- created with restrictive permissions --
doesn't change the threat model.  (However for LUKS2 the volume key is
offloaded to the kernel keyring by default, thus no longer accessible to
userspace, and having keyfiles readable by root slightly changes the
threat model.)

To enable unlocking via key files for the root file system, first
generate the shared secret (here with 512 bits of entropy as it's also
the size of the volume key) inside a new file:

    root@debian:~$ mkdir -m0700 /etc/keys
    root@debian:~$ ( umask 0077 && dd if=/dev/urandom bs=1 count=64 of=/etc/keys/root.key )
    64+0 records in
    64+0 records out
    64 bytes copied, 0.000698363 s, 91.6 kB/s

Now create a new key slot with that key file:

    root@debian:~$ cryptsetup luksAddKey /dev/sda3 /etc/keys/root.key
    Enter any existing passphrase:

    root@debian:~$ cryptsetup luksDump /dev/sda3 | grep "^Key Slot"
    Key Slot 0: ENABLED
    Key Slot 1: ENABLED
    Key Slot 2: DISABLED
    Key Slot 3: DISABLED
    Key Slot 4: DISABLED
    Key Slot 5: DISABLED
    Key Slot 6: DISABLED
    Key Slot 7: DISABLED

Edit the [`crypttab`(5)] and set the third column to the key file path for
the root device entry:

    root@debian:~$ cat /etc/crypttab
    root_crypt UUID=… /etc/keys/root.key luks,discard,key-slot=1

(The unlock logic normally runs the PBKDF algorithm through each keyslot
sequentially until a match is found.  Since the key file is explicitly
targeting the second key slot, its index can be specified with
`key-slot=1` in the [`crypttab`(5)] to save some expensive PBKDF
computations and reduce boot time.)

In `/etc/cryptsetup-initramfs/conf-hook`, set `KEYFILE_PATTERN` to a
`glob`(7) expanding to the key files to include to the initramfs image.

    root@debian:~$ echo "KEYFILE_PATTERN=\"/etc/keys/*.key\"" >>/etc/cryptsetup-initramfs/conf-hook

In `/etc/initramfs-tools/initramfs.conf`, set `UMASK` to a restrictive
value to avoid leaking key material.  See [`initramfs.conf`(5)] for
details.

    root@debian:~$ echo UMASK=0077 >>/etc/initramfs-tools/initramfs.conf

Finally re-generate the initramfs image, and double-check that it has
restrictive permissions and includes the key.

    root@debian:~$ update-initramfs -u
    update-initramfs: Generating /boot/initrd.img-4.19.0-4-amd64
    root@debian:~$ stat -L -c "%A  %n" /initrd.img
    -rw-------  /initrd.img
    root@debian:~$ lsinitramfs /initrd.img | grep "^cryptroot/keyfiles/"
    cryptroot/keyfiles/root_crypt.key

(`cryptsetup-initramfs` normalises and renames key files inside the
initramfs, hence the new keyfile name.)

Should be safe to reboot now :-)  If all went well you should see a
single passphrase prompt.

[`cryptsetup`(8)]: https://manpages.debian.org/cryptsetup.8.en.html
[`crypttab`(5)]: https://manpages.debian.org/crypttab.5.en.html
[`fstab`(5)]: https://manpages.debian.org/fstab.5.en.html
[`initramfs.conf`(5)]: https://manpages.debian.org/initramfs.conf.5.en.html

 -- Guilhem Moulin <guilhem@debian.org>, Mon, 09 Jun 2019 16:35:20 +0200
