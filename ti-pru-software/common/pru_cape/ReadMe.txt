Programmable Real-time Unit (PRU) Software Support Package
------------------------------------------------------------
============================================================
   PRU_CAPE
============================================================

DESCRIPTION

   This directory includes demo software that is intended to run on the
   BeagleBone / BeagleBone Black PRU Cape. The demo software in this folder
   is no longer tested on a regular basis. Any bugs can be reported on the
   TI forums, e2e.ti.com.


   Pinmux Settings
   ---------------
   The PRU will not be able to communicate with the PRU Cape unless the AM335x
   pinmux is set appropriately.

   LINUX:
   AM335x running Linux on the ARM core performs pinmuxing based on settings in
   the Linux device tree. The am335x-xxx-prucape.dtsi files may be included in
   the am335x-boneblack.dts and am335x-bone.dts device tree files (depending on
   whether BeagleBone Black board or BeagleBone board is used). Make sure that
   the prucape.dtsi files are placed BELOW the other #include
   statements in the am335x-boneblack.dts/am335x-bone.dts.dts file. This ensures
   that the prucape.dtsi files correctly overwrite the settings in the
   other .dtsi files.

   CCS:
   CCS connected directly to the PRU cores performs pinmuxing based on gel
   scripts. Reference the PRU Hands-on Labs, Lab 1 for steps to set pinmuxing
   with the PRU_CAPE.gel file.


   PRU Firmwares
   -------------
   The "pru_fw" directory includes firmware demos specifically designed for
   use with the PRU Cape. Additional PRU firmware projects can be found in
   the examples/ and the labs/ folders.

   For more details about the PRU Cape and the demos included in this package,
   visit:

        http://www.ti.com/tool/PRUCAPE



ADDITIONAL RESOURCES

   For more information about the PRU, visit:

	PRU-ICSS Wiki            - http://processors.wiki.ti.com/index.php/PRU-ICSS
	PRU Training Slides      - http://www.ti.com/sitarabootcamp
	PRU Evaluation Hardware  - http://www.ti.com/tool/PRUCAPE
        Support                  - http://e2e.ti.com

