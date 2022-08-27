#! /bin/bash
set -e

unset CDPATH

# At all time, this variable must be set to either:
# "y" if the changes to the Linux tree are specific to the kernel version;
# "n" otherwise.
patch_kernelversion_specific="n"

# At all time, this variable must be set to either:
# "y" if the changes to the Linux tree are specific to the architecture;
# "n" otherwise.
patch_architecture_specific="n"

# At all time, this variable must be set to either:
# "y": ignore kernel-version-specific changes;
# "n": ignore non-kernel-version-specific changes;
# "b": don't filter according to the kernel version.
patch_kernelversion_filter="b"

# At all time, this variable must be set to either:
# "y": ignore architecture-specific changes;
# "n": ignore non-architecture-specific changes;
# "b": don't filter according to the architecture.
patch_architecture_filter="b"

# Default path to kernel tree
linux_tree=.

patch_copytempfile() {
    file="$1"
    if ! test -f "$temp_tree/$file"; then
        subdir=`dirname "$file"`
        mkdir -p "$temp_tree/$subdir"
        cp "$linux_tree/$file" "$temp_tree/$file"
    fi
}

check_filter() {
    if test "$patch_kernelversion_specific" != "$patch_kernelversion_filter" \
        -a "$patch_architecture_specific" != "$patch_architecture_filter"; then
        echo ok
    elif test -e "$temp_tree/$1"; then
        echo "$me: inconsistent multiple changes to $1 in Linux kernel tree" >&2
	echo error
    else
        echo ignore
    fi
}

patch_append() {
    file="$1"
    if test "x$output_patch" = "x"; then
	if test -L "$linux_tree/$file" ; then
	    mv "$linux_tree/$file" "$linux_tree/$file.orig"
	    cp "$linux_tree/$file.orig" "$linux_tree/$file"
	fi
	chmod +w "$linux_tree/$file"
        cat >> "$linux_tree/$file"
    else
        if test `check_filter $file` = "ok"; then
            patch_copytempfile "$file"
            cat >> "$temp_tree/$file"
        fi
    fi
}

patch_ed() {
    file="$1"
    if test "x$output_patch" = "x"; then
        ed -s "$linux_tree/$file" > /dev/null
    else
        if test `check_filter $file` = "ok"; then
            patch_copytempfile "$file"
            ed -s "$temp_tree/$file" > /dev/null
        fi
    fi
}

patch_link() {
    recursive="$1"         # "r" or "n"
    link_file="$2"         # "m", "n" or some file (basename) from $target_dir
    target_dir="$3"
    link_dir="$4"

    (
        if test \! \( x$link_file = xm -o x$link_file = xn \); then
	   find_clean_opt="-name $link_file"
	   find_link_opt=$find_clean_opt
	else
           link_makefiles_opt=""
           if test x$link_file = xm; then
              link_makefiles_opt="-name Makefile -o"
           fi
           if test x$recursive = xr; then
	       recursive_opts="-mindepth 1"
	       dir_opt="-type d -o"
           else
	       recursive_opt="-maxdepth 1"
	       dir_opt=""
           fi
	   find_clean_opt="$recursive_opt \( $dir_opt $link_makefiles_opt -name Kconfig -o -name '*.[chS]' -o -name '*.sh' \)"
	   find_link_opt="$recursive_opt \( $link_makefiles_opt -name Kconfig -o -name '*.[chS]' -o -name '*.sh' \)"
	fi

        if test "x$output_patch" = "x" -a -e $linux_tree/$link_dir; then
            cd $linux_tree/$link_dir &&
	    eval find . $find_clean_opt |
	    while read f; do
                if test -L $f -a ! -e $xenomai_root/$target_dir/$f; then rm -Rf $f; fi
            done
        fi

        cd $xenomai_root/$target_dir &&
        eval find . $find_link_opt |
        while read f; do
            f=`echo $f | cut -d/ -f2-`
            d=`dirname $f`
            if test "x$output_patch" = "x"; then
                mkdir -p $linux_tree/$link_dir/$d
                if test x$forcelink = x1 -o \
		   ! $xenomai_root/$target_dir/$f -ef $linux_tree/$link_dir/$f;
		then
                    ln -sf $xenomai_root/$target_dir/$f $linux_tree/$link_dir/$f
                fi
            else
                if test `check_filter $link_dir/$f` = "ok"; then
                    mkdir -p $temp_tree/$link_dir/$d
                    cp $xenomai_root/$target_dir/$f $temp_tree/$link_dir/$f
                fi
            fi
        done
    )
}

generate_patch() {
    (
    cd "$temp_tree"
    find . -type f |
    while read f; do
        diff -Naurd "$linux_tree/$f" "$f" |
        sed -e "s,^--- ${linux_tree}/\.\(/.*\)$,--- linux\1," \
            -e "s,^+++ \.\(/.*\)$,+++ linux-patched\1,"
    done
    )
}


usage='usage: prepare-kernel --linux=<linux-tree> --ipipe=<ipipe-patch> [--arch=<arch>] [--outpatch=<file> [--filterkvers=y|n] [--filterarch=y|n]] [--forcelink] [--default] [--verbose]'
me=`basename $0`

while test $# -gt 0; do
    case "$1" in
    --linux=*)
	linux_tree=`echo $1|sed -e 's,^--linux=\\(.*\\)$,\\1,g'`
	linux_tree=`eval "echo $linux_tree"`
	;;
    --adeos=*)
	ipipe_patch=`echo $1|sed -e 's,^--adeos=\\(.*\\)$,\\1,g'`
	ipipe_patch=`eval "echo $ipipe_patch"`
	;;
    --ipipe=*)
	ipipe_patch=`echo $1|sed -e 's,^--ipipe=\\(.*\\)$,\\1,g'`
	ipipe_patch=`eval "echo $ipipe_patch"`
	;;
    --arch=*)
	linux_arch=`echo $1|sed -e 's,^--arch=\\(.*\\)$,\\1,g'`
	;;
    --outpatch=*)
	output_patch=`echo $1|sed -e 's,^--outpatch=\\(.*\\)$,\\1,g'`
	;;
    --filterkvers=*)
        patch_kernelversion_filter=`echo $1|sed -e 's,^--filterkvers=\\(.*\\)$,\\1,g'`
        ;;
    --filterarch=*)
        patch_architecture_filter=`echo $1|sed -e 's,^--filterarch=\\(.*\\)$,\\1,g'`
        ;;
    --forcelink)
        forcelink=1
        ;;
    --default)
        usedefault=1
        ;;
    --verbose)
	verbose=1
	;;
    --help)
	echo "$usage"
	exit 0
	;;
    *)
	echo "$me: unknown flag: $1" >&2
	echo "$usage" >&2
	exit 1
	;;
    esac
    shift
done

# Infere the location of the Xenomai source tree from
# the path of the current script.

script_path=`type -p $0`
xenomai_root=`dirname $script_path`/..
xenomai_root=`cd $xenomai_root && pwd`

# Check the Linux tree

default_linux_tree=/lib/modules/`uname -r`/source

while test x$linux_tree = x; do
   if test x$usedefault = x; then
      echo -n "Linux tree [default $default_linux_tree]: "
      read linux_tree
   fi
   if test x$linux_tree = x; then
      linux_tree=$default_linux_tree
   fi
   if test \! -x "$linux_tree"; then
      echo "$me: cannot access Linux tree in $linux_tree"
      linux_tree=
      usedefault=
      default_linux_tree=/usr/src
   else
      break
   fi
done

linux_tree=`cd $linux_tree && pwd`
linux_out=$linux_tree

if test \! -r $linux_tree/Makefile; then
   echo "$me: $linux_tree is not a valid Linux kernel tree" >&2
   exit 2
fi

# Create an empty output patch file, and initialize the temporary tree.
if test "x$output_patch" != "x"; then

    temp_tree=`mktemp -d prepare-kernel-XXX --tmpdir`
    if [ $? -ne 0 ]; then
	echo Temporary directory could not be created.
	exit 1
    fi

    patchdir=`dirname $output_patch`
    patchdir=`cd $patchdir && pwd`
    output_patch=$patchdir/`basename $output_patch`
    echo > "$output_patch"

fi

# Infer the default architecture if unspecified.

if test x$linux_arch = x; then
   build_arch=`$xenomai_root/config/config.guess`
   default_linux_arch=`echo $build_arch|cut -f1 -d-`
fi

while : ; do
   if test x$linux_arch = x; then
      if test x$usedefault = x; then
         echo -n "Target architecture [default $default_linux_arch]: "
         read linux_arch
      fi
      if test "x$linux_arch" = x; then
         linux_arch=$default_linux_arch
      fi
   fi
   case "$linux_arch" in
   x86*|i*86|amd*)
      linux_arch=x86
      ;;
   powerpc*|ppc*)
      linux_arch=powerpc
      ;;
   bfin*|blackfin)
      linux_arch=blackfin
      ;;
   nios2)
      linux_arch=nios2
      ;;
   arm)
      linux_arch=arm
      ;;
   sh|sh4)
      linux_arch=sh
      ;;
   *)
      echo "$me: unsupported architecture: $linux_arch" >&2
      linux_arch=
      usedefault=
      ;;
   esac
   if test \! x$linux_arch = x; then
      break
   fi
done

foo=`grep '^KERNELSRC    := ' $linux_tree/Makefile | cut -d= -f2`
if [ ! -z $foo ] ; then
    linux_tree=$foo
fi
unset foo

eval linux_`grep '^EXTRAVERSION =' $linux_tree/Makefile | sed -e 's, ,,g'`
eval linux_`grep '^PATCHLEVEL =' $linux_tree/Makefile | sed -e 's, ,,g'`
eval linux_`grep '^SUBLEVEL =' $linux_tree/Makefile | sed -e 's, ,,g'`
eval linux_`grep '^VERSION =' $linux_tree/Makefile | sed -e 's, ,,g'`

linux_version="$linux_VERSION.$linux_PATCHLEVEL.$linux_SUBLEVEL"

if test x$verbose = x1; then
echo "Preparing kernel $linux_version$linux_EXTRAVERSION in $linux_tree..."
fi

if test -r $linux_tree/include/linux/ipipe.h; then
    if test x$verbose = x1; then
       echo "I-pipe found - bypassing patch."
    fi
else
   if test x$verbose = x1; then
      echo "$me: no I-pipe support found." >&2
   fi
   while test x$ipipe_patch = x; do
      echo -n "I-pipe patch: "
      read ipipe_patch
      if test \! -r "$ipipe_patch" -o x$ipipe_patch = x; then
         echo "$me: cannot read I-pipe patch from $ipipe_patch" >&2
         ipipe_patch=
      fi
   done
   patchdir=`dirname $ipipe_patch`; 
   patchdir=`cd $patchdir && pwd`
   ipipe_patch=$patchdir/`basename $ipipe_patch`
   curdir=$PWD
   cd $linux_tree && patch --dry-run -p1 -f < $ipipe_patch || { 
        cd $curdir;
        echo "$me: Unable to patch kernel $linux_version$linux_EXTRAVERSION with `basename $ipipe_patch`." >&2
        exit 2;
   }
   patch -p1 -f -s < $ipipe_patch
   cd $curdir
fi

if test \! -r $linux_tree/arch/$linux_arch/include/asm/ipipe.h; then
   echo "$me: $linux_tree has no I-pipe support for $linux_arch" >&2
   exit 2
fi

ipipe_core=`grep '^#define.*IPIPE_CORE_RELEASE.*' $linux_tree/arch/$linux_arch/include/asm/ipipe.h 2>/dev/null|head -n1|sed -e 's,[^0-9]*\([0-9]*\)$,\1,'`
if test "x$ipipe_core" = x; then
    echo "$me: $linux_tree has no I-pipe support for $linux_arch" >&2
    exit 2
fi
if test x$verbose = x1; then
   echo "I-pipe core/$linux_arch #$ipipe_core installed."
fi

patch_kernelversion_specific="y"

case $linux_VERSION.$linux_PATCHLEVEL in

    2.*)

    echo "$me: Unsupported kernel version $linux_VERSION.$linux_PATCHLEVEL.x" >&2
    exit 2
    ;;

    *)

    patch_architecture_specific="y"

    if ! grep -q XENOMAI $linux_tree/init/Kconfig; then
	version_stamp=`cat $xenomai_root/config/version-code`
	version_major=`expr $version_stamp : '\([[0-9]]*\)' || true`
	version_minor=`expr $version_stamp : '[[0-9]]*\.\([[0-9]*]*\)' || true`
	revision_level=`expr $version_stamp : '[[0-9]]*\.[[0-9]*]*\.\([[0-9]*]*\)' || true`
	version_string=`cat $xenomai_root/config/version-label`
	sed -e "s,@VERSION_MAJOR@,$version_major,g" \
	    -e "s,@VERSION_MINOR@,$version_minor,g" \
	    -e "s,@REVISION_LEVEL@,$revision_level,g" \
	    -e "s,@VERSION_STRING@,$version_string,g" \
	    $xenomai_root/scripts/Kconfig.frag |
            patch_append init/Kconfig
    fi

test "x$CONFIG_XENO_REVISION_LEVEL" = "x" && CONFIG_XENO_REVISION_LEVEL=0

    if ! grep -q CONFIG_XENOMAI $linux_tree/arch/$linux_arch/Makefile; then
	p="KBUILD_CFLAGS += -Iarch/\$(SRCARCH)/xenomai/include -Iinclude/xenomai"
	(echo; echo $p) | patch_append arch/$linux_arch/Makefile
	p="core-\$(CONFIG_XENOMAI)	+= arch/$linux_arch/xenomai/"
	echo $p | patch_append arch/$linux_arch/Makefile
    fi

    patch_architecture_specific="n"

    if ! grep -q CONFIG_XENOMAI $linux_tree/drivers/Makefile; then
	p="obj-\$(CONFIG_XENOMAI)		+= xenomai/"
	( echo ; echo $p ) | patch_append drivers/Makefile
    fi

    if ! grep -q CONFIG_XENOMAI $linux_tree/kernel/Makefile; then
	p="obj-\$(CONFIG_XENOMAI)		+= xenomai/"
	( echo ; echo $p ) | patch_append kernel/Makefile
    fi
    ;;

esac

# Create local directories then symlink to the source files from
# there, so that we don't pollute the Xenomai source tree with
# compilation files.

patch_kernelversion_specific="n"
patch_architecture_specific="y"
patch_link r m kernel/cobalt/arch/$linux_arch arch/$linux_arch/xenomai
patch_link n n kernel/cobalt/include/ipipe arch/$linux_arch/include/ipipe
patch_architecture_specific="n"
patch_link n m kernel/cobalt kernel/xenomai
patch_link n cobalt-core.h kernel/cobalt/trace include/trace/events
patch_link n cobalt-rtdm.h kernel/cobalt/trace include/trace/events
patch_link n cobalt-posix.h kernel/cobalt/trace include/trace/events
patch_link r n kernel/cobalt/include/asm-generic/xenomai include/asm-generic/xenomai
patch_link r n kernel/cobalt/include/linux/xenomai include/linux/xenomai
patch_link n m kernel/cobalt/posix kernel/xenomai/posix
patch_link n m kernel/cobalt/rtdm kernel/xenomai/rtdm
patch_link r m kernel/drivers drivers/xenomai
patch_link n n include/cobalt/kernel include/xenomai/cobalt/kernel
patch_link r n include/cobalt/kernel/rtdm include/xenomai/rtdm
patch_link r n include/cobalt/uapi include/xenomai/cobalt/uapi
patch_link r n include/rtdm/uapi include/xenomai/rtdm/uapi
patch_link n version.h include/xenomai include/xenomai

if test "x$output_patch" != "x"; then
    if test x$verbose = x1; then
    echo 'Generating patch.'
    fi
    generate_patch > "$output_patch"
    rm -rf $temp_tree
fi

if test x$verbose = x1; then
echo 'Links installed.'
echo 'Build system ready.'
fi

exit 0

