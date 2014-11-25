#! /bin/sh

builddir=$1

echo $$ > buildwatch.pid

maxwait=$(expr 180 \* 60)
wait=$maxwait
ival=$(expr 30 \* 60)
#ival=3

while [ $wait -gt 0 ]; do
    sleep $ival
    wait=$(expr $wait - $ival)
    state=
    if ps x | grep -v grep | egrep -qs '/cc1|jar|java|gij'; then
	state="compiler/java/jar running ..."
	wait=$maxwait
    fi

    new_quiet=$(ls -l $builddir/openjdk*/build/*/tmp/rt-orig.jar $builddir/openjdk*/build/*/lib/tools.jar $builddir/openjdk*/build/*/lib/ct.sym 2>&1 | md5sum)
    if [ "$old_quiet" != "$new_quiet" ]; then
	state="assembling jar file ..."
	wait=$maxwait
    fi
    old_quiet=$new_quiet

    new_noisy=$(ls -l $builddir/mauve-*/mauve_output* jtreg_output-* 2>&1 | md5sum)
    if [ "$old_noisy" != "$new_noisy" ]; then
	wait=$maxwait
    elif [ -n "$state" ]; then
	echo $state
    fi
    old_noisy=$new_noisy

    if [ ! -f buildwatch.pid ]; then
	echo "buildwatch exit"
	exit 0
    fi
done
