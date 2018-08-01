#!/bin/sh

DEB_PKGS_LIST="libopencv-calib3d@V.install libopencv-contrib@V.install libopencv-core@V.install
	libopencv-features2d@V.install libopencv-flann@V.install libopencv-gpu@V.install  
	libopencv-highgui@V.install libopencv-imgcodecs@V.install libopencv-imgproc@V.install 
	libopencv-ml@V.install libopencv-objdetect@V.install libopencv-ocl@V.install 
	libopencv-photo@V.install libopencv-shape@V.install libopencv-stitching@V.install 
	libopencv-superres@V.install libopencv-ts@V.install libopencv-video@V.install 
	libopencv-videoio@V.install libopencv-videostab@V.install libopencv-viz@V.install 
	libopencv@V-java.install libopencv@V-jni.install
	libopencv-contrib@V.lintian-overrides libopencv@V-jni.lintian-overrides
	libopencv@V-java.links"
# opencv-data opencv-doc.install python-opencv.install python3-opencv.install

cd debian

for d in $DEB_PKGS_LIST; do
	F=`echo $d | sed -e "s/@V/$1/g"`	
	T=`echo $d | sed -e "s/@V/$2/g"`	
	mv ${F} ${T}
done

DEB_JAVAVER_LIST="libopencv@V-java.links libopencv@V-java.install libopencv@V-jni.install"
for d in $DEB_JAVAVER_LIST; do
	T=`echo $d | sed -e "s/@V/$2/g"`
	O=`echo $1 | sed -e "s/\.//g"`
	N=`echo $2 | sed -e "s/\.//g"`

	sed -i -e "s/${O}/${N}/g" ${T}
done
