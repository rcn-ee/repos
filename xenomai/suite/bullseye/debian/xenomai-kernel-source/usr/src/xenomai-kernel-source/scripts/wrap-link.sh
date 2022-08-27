#! /bin/sh
# To build static applications for the Cobalt core, we need to split
# link-edit into two stages, to avoid wrapping symbols from system
# libs.

set -e

usage() {
    cat <<EOF
$1 [options] command-line

Split command-line in two parts for linking static applications with
the Xenomai POSIX/Cobalt interface in two stages, so that symbols
from the system libraries are not wrapped.

Options:
-q be quiet
-v be verbose (print each command before running it)
-n dry run (print all commands but don't run any)

Example:
$1 -v gcc -o foo foo.o -Wl,@/usr/xenomai/lib/cobalt.wrappers -L/usr/xenomai/lib -lcobalt -lmodechk -lpthread -lrt
will print and run:
+ gcc -o foo.tmp -Wl,-Ur -nostdlib foo.o -Wl,@/usr/xenomai/lib/cobalt.wrappers -Wl,@/usr/xenomai/lib/modechk.wrappers -L/usr/xenomai/lib
+ gcc -o foo foo.tmp -L/usr/xenomai/lib -lcobalt -lmodechk -lpthread -lrt
+ rm foo.tmp
EOF
}

add_2stages() {
    stage1_args="$stage1_args $@"
    stage2_args="$stage2_args $@"
}   

add_linker_flag() {
    if $next_is_wrapped_symbol; then
	stage1_args="$stage1_args -Wl,--wrap $@"
	next_is_wrapped_symbol=false
    else
	case "$@" in
	*--as-needed*)
		stage2_args="$stage2_args $@"
		;;
	*)
		add_2stages "$@"
		;;
	esac
    fi
}

add_linker_obj() {
    if $stage2; then
	stage2_args="$stage2_args $@"
    else
	stage1_args="$stage1_args $@"
    fi
}

if test -n "$V" && test $V -gt 0; then
    verbose=:
else
    verbose=false
fi
dryrun=
progname="$0"

if test $# -eq 0; then
    usage "$progname"
    exit 0
fi

while test $# -gt 0; do
    arg="$1"
    shift
    case "$arg" in
	-v) 
	    verbose=:
	    ;;

	-q) 
	    verbose=false
	    ;;

	-n) 
	    dryrun="echo # "
	    ;;

	-*)
	    cc="$cc $arg"
	    ;;

	*gcc*|*g++*)
	    cc="$cc $arg"
	    break
	    ;;

	*ld)
	    usage "$progname"
	    /bin/echo -e "\nlinker must be gcc or g++, not ld"
	    exit 1
	    ;;

	*)
	    cc="$cc $arg"
	    ;;
    esac
done

test -z "$dryrun" || verbose=false
next_is_wrapped_symbol=false

onestage_args="$@"
stage1_args=""
stage2_args=""
stage2=false
while test $# -gt 0; do
    arg="$1"
    shift
    case "$arg" in
	-Xlinker)
	    arg="$1"
	    shift
	    case "$arg" in
		--wrap)
		    next_is_wrapped_symbol=:
		    ;;
		@*.wrappers)
		    stage1_args="$stage1_args -Xlinker $arg"
		    ;;

		*) 
		    add_linker_flag -Xlinker "$arg"
		    ;;
	    esac
	    ;;

	-Wl,--wrap)
	    next_is_wrapped_symbol=:
	    ;;

	-Wl,--wrap,main|-Wl,--wrap=main|-Wl,--dynamic-list=*)
	    # special case so that we can interpose on the main()
	    # routine. For this we need this wrapping to take place in
	    # the second stage.
	    stage2_args="$stage2_args $arg"
	    ;;

	-Wl,@*.wrappers|-Wl,--wrap,*|-Wl,--wrap=*)
	    stage1_args="$stage1_args $arg"
	    ;;

	-Wl,*)
	    add_linker_flag "$arg"
	    ;;

	*libcobalt.so*|*libcobalt.a|-lcobalt)
	    # linker directives might contain this pattern as well, so
	    # match it later in the test sequence.
	    stage2_args="$stage2_args $arg"
	    stage2=:
	    ;;

	-o)
	    output="$1"
	    shift
	    ;;

	-o*)
	    output=`expr "$arg" : '-o\(.*\)'`
	    ;;
	
	-l) 
	    arg="$1"
	    shift
	    add_linker_obj -l $arg
	    ;;

	-l*) #a library
	    add_linker_obj $arg
	    ;;

	*.so)
	    stage2_args="$stage2_args $arg"
	    ;;

	*.o)
	    # Force .o to stage1 regardless of its position
	    stage1_args="$stage1_args $arg"
	    ;;

	-pie)
	    stage2_args="$stage2_args $arg"
	    ;;

	*) 
	    if test -e "$arg"; then
		add_linker_obj $arg
	    else
		add_2stages "$arg"
	    fi
	   ;;
    esac
done

if $stage2; then
    $verbose && set -x
    $dryrun $cc -o "$output.tmp" -r -nostdlib $stage1_args
    $dryrun $cc -o "$output" "$output.tmp" $stage2_args
    $dryrun rm -f $output.tmp
else
    $verbose && set -x
    $dryrun $cc $onestage_args
fi
