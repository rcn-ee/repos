DEB_BUILD_OPTIONS="parallel=$(nproc) nocheck" git buildpackage -us -uc -B "$@"
