#debian...

```
sudo dpkg --add-architecture i386 ; \
sudo apt-get update ; \
sudo apt-get install libc6:i386 libstdc++6:i386 libncurses5:i386 zlib1g:i386 \
git build-essential diffstat texinfo gawk chrpath dos2unix \
wget unzip g++-multilib socat libsdl1.2-dev xterm doxygen \
gcc-multilib
```

```
sudo dpkg-reconfigure dash
(Select "no" when prompted)
```

```
mkdir -p ti-sdk-03.02.00.05 ; \
cd ./ti-sdk-03.02.00.05 ; \
wget https://releases.linaro.org/components/toolchain/binaries/5.3-2016.02/arm-linux-gnueabihf/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz ;\
tar xf gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf.tar.xz
```

```
export PATH=`pwd`/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf/bin:$PATH
```

```
git clone git://arago-project.org/git/projects/oe-layersetup.git tisdk ; \
cd tisdk ; \
./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-03.02.00.05-config.txt ; \
mkdir downloads ; \
cp -v ../../dl/CCS6.1.3.00034_linux.tar.gz downloads/ ; \
touch downloads/CCS6.1.3.00034_linux.tar.gz.done
```

```
cd build
. conf/setenv
MACHINE=am57xx-evm bitbake ipumm-fw
```
