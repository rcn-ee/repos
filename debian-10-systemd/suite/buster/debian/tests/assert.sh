# utility functions for shell tests

assert_true() {
    if ! $1; then
        echo "FAIL: command '$1' failed with exit code $?" >&2
        exit 1
    fi
}


assert_eq() {
    if [ "$1" != "$2" ]; then
        echo "FAIL: expected: '$2' actual: '$1'" >&2
        exit 1
    fi
}

assert_in() {
    if ! echo "$2" | grep -q "$1"; then
        echo "FAIL: '$1' not found in:" >&2
        echo "$2" >&2
        exit 1
    fi
}

assert_rc() {
    local exp=$1
    shift
    set +e
    $@
    RC=$?
    set -e
    assert_eq $RC $exp
}
