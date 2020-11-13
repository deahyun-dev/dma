#
# This file is the dma-test-0 recipe.
#

SUMMARY = "Simple dma-test-0 application"
SECTION = "PETALINUX/apps"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://*.c \
		   file://*.h \
	   file://Makefile \
		  "

S = "${WORKDIR}"

DEPENDS = " xil"


do_compile() {
	     oe_runmake
}

do_install() {
	     install -d ${D}${bindir}
	     install -m 0755 dma-test-0 ${D}${bindir}
}
