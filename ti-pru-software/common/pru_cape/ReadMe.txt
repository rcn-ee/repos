Programmable Real-time Unit (PRU) Software Support Package
------------------------------------------------------------
============================================================
   PRU_CAPE
============================================================

DESCRIPTION

   This directory includes demo software that is intended to run on the
   BeagleBone / BeagleBone Black PRU Cape.

   CCS/StarterWare
   -----------
   Pre-built CCS/StarterWare binaries that can be run from an SD card or through
   CCS are available in the "bin/app/", "bin/CCS/", and "bin/MLO/" directories.

   The "pru_demo/StarterWare/" directory includes AM335x StarterWare-based ARM
   code to load and run the PRU firmware demos.  This code provides an example
   of how to enable the PRU using a non-Linux OS.  However, Linux or CCS can
   also be used to run the PRU demos.

   Linux
   -----
   The "pru_demo/Linux/" directory inludes a script (pru_demo.sh) that can be
   copied to the BeagleBone or BeagleBone Black and be used to run the PRU demos
   that are in the "pru_fw" directory.

   The "bin/Linux" directory contains everything that you need to copy over to
   the BeagleBone or BeagleBone Black in order to run the console demo while
   running Linux as the host operating system (you will still need to update
   the dtb file using the provided .dtsi files).

   PRU Firmwares
   -------------
   The "pru_fw" directory includes the PRU demo firmwares.

   For more details about the PRU Cape and the demos included in this package,
   visit:

        http://www.ti.com/tool/PRUCAPE



ADDITIONAL RESOURCES

   For more information about the PRU, visit:

	PRU-ICSS Wiki            - http://processors.wiki.ti.com/index.php/PRU-ICSS
	PRU Training Slides      - http://www.ti.com/sitarabootcamp
	PRU Evaluation Hardware  - http://www.ti.com/tool/PRUCAPE
        Support                  - http://e2e.ti.com

