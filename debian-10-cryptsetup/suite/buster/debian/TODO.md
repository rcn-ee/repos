# TODO list

* luksSuspend integration
  * https://www.freedesktop.org/wiki/Software/systemd/inhibit/ might give a cleaner interface
  * https://lwn.net/Articles/582648/ (flag is now `SUSPEND_SKIP_SYNC`)
  * https://guilhem.org/tmp/suspend
  * implementations for other distros:
    * https://github.com/jonasmalacofilho/ubuntu-luks-suspend
    * https://github.com/vianney/arch-luks-suspend
    * https://github.com/zhongfu/ubuntu-luks-suspend
    * https://github.com/Microcentillion/ubuntu-lukssuspend/
    * https://askubuntu.com/questions/348196/how-do-i-enable-ubuntu-using-full-disk-encryption-to-call-lukssupend-before-sl#675540
    * https://superuser.com/questions/648333/how-to-make-suspend-to-ram-secure-on-ubuntu-with-full-disk-encryption-lvm-on-to#676531
  * clearly document the limits: data in memory is never protected
  * suspend/resume
    * root@debian:~# systemctl suspend
    * root@debian:~# (qemu) info status
      * VM status: paused (suspended)
      * (qemu) sendkey x
      * (qemu) info status
      * VM status: running

* luks nuke feature
  * https://www.kali.org/tutorials/nuke-kali-linux-luks/
  * https://pkg.kali.org/pkg/cryptsetup
  * https://github.com/offensive-security/cryptsetup-nuke-keys
  * TODO:
    * review and improve original patch to address upstream's concerns
      * http://article.gmane.org/gmane.linux.kernel.device-mapper.dm-crypt/7184
    * patch luks2 functions to support it as well
    * documentation in manpage (and README.Debian?)
    * bash completion

* systemd integration and future of cryptscripts
  * patch cryptsetup.c in systemd to support cryptscripts?
  * try the patches
    * https://github.com/systemd/systemd/pull/3007#pullrequestreview-39358162
    * https://lists.freedesktop.org/archives/systemd-devel/2012-June/005693.html
  * or completely remove cryptscripts feature from cryptsetup in Debian?

* ephemeral swap encryption

* improve test suite

* cryptroot hook script:
  - We should add parent device detection for ZFS (#820888) so users
    don't have to manually add the 'initramfs' option to the crypttab.
* cryptroot local-top script:
  - Find a solution to run 'lvm vgchange' only after all lvm parent devices
    are unlocked. At the moment, ugly errors and warnings are shown in case
    of several encrypted parent devices.


## Old list

* Would a fallback make sense? like when using any keyscript, try passphrase
  in the case that it fails. if we implement that at all, never make it the
  default, and warn about security issues in README.Debian. even explain that
  backup passphrase keyslots thwart the extra security of keyfiles/keyscripts.
  (#438481, #471729)

* Implement something like 'ignore-if-no-device' to mount (/etc/fstab), and
  thus support several situations where cryptsetup fails to setup a device:
  -> the device is not attached at all
  -> wrong passphrase/no keyfile available
  -> timeouts arise
  (#474120)
  * seems like the fstab flag alread does exists: nofail. so reimplement
    timeout?

* Reimplement timeout support in a cleaner way?
