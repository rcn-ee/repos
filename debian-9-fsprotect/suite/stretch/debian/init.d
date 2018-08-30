#! /bin/bash
### BEGIN INIT INFO
# Provides:          fsprotect
# Required-Start:    $local_fs
# Required-Stop:
# Default-Start:     S
# Default-Stop:
# Short-Description: Lock/protect filesystems
# Description:       Lock/protect filesystems that are defined in /etc/default/fsprotect
### END INIT INFO

# Author: Stefanos Harhalakis <v13@v13.gr>

# Do NOT "set -e"

# PATH should only include /usr/* if it runs after the mountnfs.sh script
PATH=/sbin:/bin:/lib/fsprotect
DESC="Filesystem protection"
NAME=fsprotect
SCRIPTNAME=/etc/init.d/$NAME

# Read configuration variable file if it is present
[ -r /etc/default/$NAME ] && . /etc/default/$NAME

# Load the VERBOSE setting and other rcS variables
. /lib/init/vars.sh

# Define LSB log_* functions.
# Depend on lsb-base (>= 3.0-6) to ensure that this file is present.
. /lib/lsb/init-functions

# Check whether fsprotect should be enabled
is_enabled()
{
	T=$(grep '\<fsprotect\>' /proc/cmdline)

	[ -z "$T" ] && return 1

	return 0
}

# Load module
load_module()
{
	T=$(grep "\<aufs\>" /proc/filesystems)

	if [ -z "$T" ] ; then
		if ! modprobe aufs ; then
			log_failure_msg "aufs is not available"
			return 1
		fi
	fi

	return 0
}

# Lock filesystems
do_start()
{
	is_enabled || return 0

	[ -z "$PROTECT" ] && return 0

	load_module || return 1
	
	# 
	# VERBOSE="yes"

	STATUS=0

	if [ "$VERBOSE" = "no" ] ; then
		log_daemon_msg "Protecting filesystems"
	else
		log_action_begin_msg "Protecting filesystems"
	fi

	for f in $PROTECT ; do
		if [ -z "$(echo "$f" | grep =)" ] ; then
			f="$f=512M"
		fi

		# We can't use "cut" here because it exists in /usr/sbin.
		# Use sed from /bin instead
		T1=$(echo "$f" | sed 's/=.*//')
		T2=$(echo "$f" | sed 's/.*=//')

		[ "$VERBOSE" != "no" ] && log_progress_msg "$T1"

		if fsprotect-protect "$T1" "$T2" > /dev/null ; then
			[ "$VERBOSE" != "no" ] && log_progress_msg "(OK)"
		else
			[ "$VERBOSE" != "no" ] && log_progress_msg "(Failed)"
			STATUS=1
		fi
	done

	if [ "$VERBOSE" = "no" ] ; then
		log_end_msg $STATUS
	else
		log_action_end_msg $STATUS
	fi

	return 0
}

# No unlocking for now. Do we ever need this?
do_stop()
{
	is_enabled || return 0

	# Nothing for now. TODO?
	return 0
}

case "$1" in
  start)
	do_start
	;;
  restart|reload|force-reload)
  	echo "Error: argument '$1' not supported" >&2
	exit 3
	;;
  stop)
	do_stop
	;;
  *)
	echo "Usage: $SCRIPTNAME {start|stop}" >&2
	exit 3
	;;
esac

:

