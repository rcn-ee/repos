#! /bin/sh -e

### BEGIN INIT INFO
# Provides:          tiipcdra7xxlad_daemon.sh
# Required-Start:    $local_fs
# Required-Stop:     $local_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Start daemon at boot time
# Description:       Enable service provided by daemon.
### END INIT INFO

tiipclad_daemon=/usr/bin/lad_dra7xx
tiipclad_params="-g -l lad.txt"

test -x "$tiipclad_daemon" || exit 0

case "$1" in
  start)
    echo -n "Starting tiipclad daemon"
    start-stop-daemon --start --quiet \
        --exec $tiipclad_daemon -- $tiipclad_params
    echo "."
    ;;
reload|force-reload|restart)
    echo -n "Stopping tiipclad daemon"
    start-stop-daemon --stop --quiet --pidfile /var/run/tiipclad.pid
    echo "."
    echo -n "Starting tiipclad daemon"
    start-stop-daemon --start --quiet \
        --exec $tiipclad_daemon -- $tiipclad_params
    echo "."
    ;;
  stop)
    echo -n "Stopping tiipclad daemon"
    start-stop-daemon --stop --quiet --pidfile /var/run/tiipclad.pid
    echo "."
    ;;
  *)
    echo "Usage: /etc/init.d/tiipclad-daemon.sh {start|stop}"
    exit 1
esac

exit 0

