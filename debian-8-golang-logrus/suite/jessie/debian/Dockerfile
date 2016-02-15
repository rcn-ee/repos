FROM tianon/debian-devel

# start by adding just "debian/control" so we can get mk-build-deps with maximum caching
ADD control /usr/src/golang-logrus/debian/
WORKDIR /usr/src/golang-logrus

# get all the build deps of _this_ package in a nice repeatable way
RUN apt-get update && mk-build-deps -irt'apt-get --no-install-recommends -yq' debian/control

# need our debian/ directory to compile _this_ package
ADD . /usr/src/golang-logrus/debian

# go download and unpack our upstream source
RUN uscan --force-download --verbose --download-current-version
RUN origtargz --unpack

# tianon is _really_ lazy, and likes a preseeded bash history
RUN echo 'origtargz --unpack && dpkg-buildpackage -us -uc && lintian -EvIL+pedantic' >> "$HOME/.bash_history"
