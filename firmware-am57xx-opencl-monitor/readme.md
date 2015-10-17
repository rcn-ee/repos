#debian...

sudo dpkg --add-architecture i386 ; \
sudo apt-get update ; \
sudo apt-get install libc6:i386 libstdc++6:i386 libncurses5:i386 zlib1g:i386 \
git build-essential diffstat texinfo gawk chrpath dos2unix \
gcc-multilib doxygen

sudo dpkg-reconfigure dash
(Select "no" when prompted)

mkdir -p ti-sdk-02.00.00.00 ; \
cd ./ti-sdk-02.00.00.00 ; \
wget http://releases.linaro.org/15.05/components/toolchain/binaries/arm-linux-gnueabihf/gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf.tar.xz  ; \
tar xf gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf.tar.xz

export PATH=`pwd`/gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf/bin:$PATH

git clone git://arago-project.org/git/projects/oe-layersetup.git tisdk ; \
cd tisdk  ; \
./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-02.00.00.00-config.txt

cd build
. conf/setenv
MACHINE=am57xx-evm bitbake opencl-monitor
