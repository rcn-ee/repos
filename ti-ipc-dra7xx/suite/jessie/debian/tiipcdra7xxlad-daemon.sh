#! /bin/sh

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

