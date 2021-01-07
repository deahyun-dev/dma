#
# This file is the 2-dma-vitis-kernel recipe.
#

SUMMARY = "Simple 2-dma-vitis-kernel application"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://2-dma-vitis-kernel.c \
	   file://Makefile \
		  "

S = "${WORKDIR}"

do_compile() {
	     oe_runmake
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 2-dma-vitis-kernel ${D}${bindir}
}
