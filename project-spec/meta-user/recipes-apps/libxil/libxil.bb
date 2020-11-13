#
# This file is the libxil recipe.
# aasdsadsa

SUMMARY = "Simple libxil application"
SECTION = "libs"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://libxil.a \
	       file://*.h \
		  "

S = "${WORKDIR}"

PROVIDES = " xil"

do_install() {
	     install -d ${D}${libdir}
	     install -m 0655 ${S}/libxil.a ${D}${libdir}
		 install -d -m 0655 ${D}/${includedir}
 		 install -m 0644 ${S}/*.h ${D}/${includedir}
}

INSANE_SKIP_${PN} = "ldflags"
INSANE_SKIP_${PN} = "already-stripped"

FILES_${PN} = "${libdir}/*.so.* ${includedir}/*"
FILES_${PN}-dev = "${libdir}/*.so"