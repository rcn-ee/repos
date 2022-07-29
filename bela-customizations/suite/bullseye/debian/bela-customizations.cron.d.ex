#
# Regular cron jobs for the bela-customizations package
#
0 4	* * *	root	[ -x /usr/bin/bela-customizations_maintenance ] && /usr/bin/bela-customizations_maintenance
