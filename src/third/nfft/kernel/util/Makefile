# Makefile.in generated by automake 1.11.3 from Makefile.am.
# kernel/util/Makefile.  Generated from Makefile.in by configure.

# Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
# 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011 Free Software
# Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.




pkgdatadir = $(datadir)/nfft
pkgincludedir = $(includedir)/nfft
pkglibdir = $(libdir)/nfft
pkglibexecdir = $(libexecdir)/nfft
am__cd = CDPATH="$${ZSH_VERSION+.}$(PATH_SEPARATOR)" && cd
install_sh_DATA = $(install_sh) -c -m 644
install_sh_PROGRAM = $(install_sh) -c
install_sh_SCRIPT = $(install_sh) -c
INSTALL_HEADER = $(INSTALL_DATA)
transform = $(program_transform_name)
NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_triplet = x86_64-unknown-linux-gnu
host_triplet = x86_64-unknown-linux-gnu
subdir = kernel/util
DIST_COMMON = $(srcdir)/Makefile.am $(srcdir)/Makefile.in
ACLOCAL_M4 = $(top_srcdir)/aclocal.m4
am__aclocal_m4_deps = $(top_srcdir)/m4/ax_apple_gcc_archflag.m4 \
	$(top_srcdir)/m4/ax_cc_maxopt.m4 \
	$(top_srcdir)/m4/ax_check_compiler_flags.m4 \
	$(top_srcdir)/m4/ax_check_dir.m4 \
	$(top_srcdir)/m4/ax_compiler_vendor.m4 \
	$(top_srcdir)/m4/ax_cunit.m4 \
	$(top_srcdir)/m4/ax_gcc_archflag.m4 \
	$(top_srcdir)/m4/ax_gcc_x86_cpuid.m4 \
	$(top_srcdir)/m4/ax_lib_fftw3.m4 \
	$(top_srcdir)/m4/ax_nfft_module.m4 \
	$(top_srcdir)/m4/ax_openmp.m4 \
	$(top_srcdir)/m4/ax_prog_doxygen.m4 \
	$(top_srcdir)/m4/ax_prog_matlab.m4 $(top_srcdir)/m4/libtool.m4 \
	$(top_srcdir)/m4/ltoptions.m4 $(top_srcdir)/m4/ltsugar.m4 \
	$(top_srcdir)/m4/ltversion.m4 $(top_srcdir)/m4/lt~obsolete.m4 \
	$(top_srcdir)/configure.ac
am__configure_deps = $(am__aclocal_m4_deps) $(CONFIGURE_DEPENDENCIES) \
	$(ACLOCAL_M4)
mkinstalldirs = $(install_sh) -d
CONFIG_HEADER = $(top_builddir)/include/config.h
CONFIG_CLEAN_FILES =
CONFIG_CLEAN_VPATH_FILES =
LTLIBRARIES = $(noinst_LTLIBRARIES)
libutil_la_LIBADD =
am_libutil_la_OBJECTS = malloc.lo sinc.lo lambda.lo bessel_i0.lo \
	float.lo int.lo error.lo bspline.lo assert.lo sort.lo rand.lo \
	vector1.lo vector2.lo vector3.lo print.lo voronoi.lo damp.lo \
	thread.lo time.lo window.lo version.lo
libutil_la_OBJECTS = $(am_libutil_la_OBJECTS)
libutil_threads_la_LIBADD =
am__libutil_threads_la_SOURCES_DIST = malloc.c sinc.c lambda.c \
	bessel_i0.c float.c int.c error.c bspline.c assert.c sort.c \
	rand.c vector1.c vector2.c vector3.c print.c voronoi.c damp.c \
	thread.c time.c window.c version.c
am__objects_1 = libutil_threads_la-malloc.lo \
	libutil_threads_la-sinc.lo libutil_threads_la-lambda.lo \
	libutil_threads_la-bessel_i0.lo libutil_threads_la-float.lo \
	libutil_threads_la-int.lo libutil_threads_la-error.lo \
	libutil_threads_la-bspline.lo libutil_threads_la-assert.lo \
	libutil_threads_la-sort.lo libutil_threads_la-rand.lo \
	libutil_threads_la-vector1.lo libutil_threads_la-vector2.lo \
	libutil_threads_la-vector3.lo libutil_threads_la-print.lo \
	libutil_threads_la-voronoi.lo libutil_threads_la-damp.lo \
	libutil_threads_la-thread.lo libutil_threads_la-time.lo \
	libutil_threads_la-window.lo libutil_threads_la-version.lo
#am_libutil_threads_la_OBJECTS = $(am__objects_1)
libutil_threads_la_OBJECTS = $(am_libutil_threads_la_OBJECTS)
libutil_threads_la_LINK = $(LIBTOOL) --tag=CC $(AM_LIBTOOLFLAGS) \
	$(LIBTOOLFLAGS) --mode=link $(CCLD) \
	$(libutil_threads_la_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) \
	$(LDFLAGS) -o $@
#am_libutil_threads_la_rpath =
DEFAULT_INCLUDES = -I. -I$(top_builddir)/include
depcomp = $(SHELL) $(top_srcdir)/config/depcomp
am__depfiles_maybe = depfiles
am__mv = mv -f
COMPILE = $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	$(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LTCOMPILE = $(LIBTOOL) --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) \
	$(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(LIBTOOL) --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) \
	--mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(AM_LDFLAGS) \
	$(LDFLAGS) -o $@
SOURCES = $(libutil_la_SOURCES) $(libutil_threads_la_SOURCES)
DIST_SOURCES = $(libutil_la_SOURCES) \
	$(am__libutil_threads_la_SOURCES_DIST)
ETAGS = etags
CTAGS = ctags
DISTFILES = $(DIST_COMMON) $(DIST_SOURCES) $(TEXINFOS) $(EXTRA_DIST)
ACLOCAL = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/missing --run aclocal-1.11
ALLOCA = 
AMTAR = $${TAR-tar}
AR = ar
AS = as
AUTOCONF = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/missing --run autoconf
AUTOHEADER = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/missing --run autoheader
AUTOMAKE = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/missing --run automake-1.11
AWK = gawk
CC = gcc
CCAS = gcc
CCASDEPMODE = depmode=gcc3
CCASFLAGS = -g -O2
CCDEPMODE = depmode=gcc3
CFLAGS = -O3 -fomit-frame-pointer -malign-double -fstrict-aliasing -ffast-math -march=native -std=gnu99
CPP = gcc -E
CPPFLAGS =  
CYGPATH_W = echo
DEFS = -DHAVE_CONFIG_H
DEPDIR = .deps
DLLTOOL = false
DOXYGEN_PAPER_SIZE = 
DSYMUTIL = 
DUMPBIN = 
DX_CONFIG = doxygen/doxygen.Doxyfile
DX_DOCDIR = doc
DX_DOT = 
DX_DOXYGEN = 
DX_DVIPS = 
DX_EGREP = 
DX_ENV =  SRCDIR='.' PROJECT='NFFT' DOCDIR='doc' VERSION='3.3.1' HAVE_DOT='NO' GENERATE_MAN='NO' GENERATE_RTF='NO' GENERATE_XML='NO' GENERATE_HTMLHELP='NO' GENERATE_CHI='NO' GENERATE_HTML='NO' GENERATE_LATEX='NO'
DX_FLAG_chi = 0
DX_FLAG_chm = 0
DX_FLAG_doc = 0
DX_FLAG_dot = 0
DX_FLAG_html = 0
DX_FLAG_man = 0
DX_FLAG_pdf = 0
DX_FLAG_ps = 0
DX_FLAG_rtf = 0
DX_FLAG_xml = 0
DX_HHC = 
DX_LATEX = 
DX_MAKEINDEX = 
DX_PDFLATEX = 
DX_PERL = /usr/bin/perl
DX_PROJECT = NFFT
ECHO_C = 
ECHO_N = -n
ECHO_T = 
EGREP = /bin/grep -E
EXEEXT = 
FGREP = /bin/grep -F
GREP = /bin/grep
HAVE_FPT = #undef HAVE_FPT
HAVE_MRI = #undef HAVE_MRI
HAVE_NFCT = #undef HAVE_NFCT
HAVE_NFSFT = #undef HAVE_NFSFT
HAVE_NFSOFT = #undef HAVE_NFSOFT
HAVE_NFST = #undef HAVE_NFST
HAVE_NNFFT = #undef HAVE_NNFFT
HAVE_NSFFT = #undef HAVE_NSFFT
INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_STRIP_PROGRAM = $(install_sh) -c -s
LD = /usr/bin/ld -m elf_x86_64
LDFLAGS = 
LIBOBJS = 
LIBS = 
LIBTOOL = $(SHELL) $(top_builddir)/libtool
LIBTOOL_DEPS = config/ltmain.sh
LIPO = 
LN_S = ln -s
LTLIBOBJS = 
MAINT = #
MAKEINFO = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/missing --run makeinfo
MANIFEST_TOOL = :
MKDIR_P = /bin/mkdir -p
NFFT_PRECISION_MACRO = NFFT_PRECISION_DOUBLE
NM = /usr/bin/nm -B
NMEDIT = 
OBJDUMP = objdump
OBJEXT = o
OPENMP_CFLAGS = -fopenmp
OTOOL = 
OTOOL64 = 
PACKAGE = nfft
PACKAGE_BUGREPORT = mail@nfft.org
PACKAGE_NAME = NFFT
PACKAGE_STRING = NFFT 3.3.1
PACKAGE_TARNAME = nfft
PACKAGE_URL = 
PACKAGE_VERSION = 3.3.1
PATH_SEPARATOR = :
POW_LIB = 
PRECISION = d
PREC_SUFFIX = 
PRTDIAG = 
RANLIB = ranlib
SED = /bin/sed
SET_MAKE = 
SHARED_VERSION_INFO = 2:0:0
SHELL = /bin/bash
STRIP = strip
TICKS_PER_SECOND = 1696391858.0
VERSION = 3.3.1
abs_builddir = /data/Work/pbmoma/src/third/nfft/kernel/util
abs_srcdir = /data/Work/pbmoma/src/third/nfft/kernel/util
abs_top_builddir = /data/Work/pbmoma/src/third/nfft
abs_top_srcdir = /data/Work/pbmoma/src/third/nfft
ac_ct_AR = ar
ac_ct_CC = gcc
ac_ct_DUMPBIN = 
am__include = include
am__leading_dot = .
am__quote = 
am__tar = $${TAR-tar} chof - "$$tardir"
am__untar = $${TAR-tar} xf -
ax_cv_cunit = no
bindir = ${exec_prefix}/bin
build = x86_64-unknown-linux-gnu
build_alias = 
build_cpu = x86_64
build_os = linux-gnu
build_vendor = unknown
builddir = .
datadir = ${datarootdir}
datarootdir = ${prefix}/share
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
dvidir = ${docdir}
exec_prefix = ${prefix}
fftw3_LDFLAGS = 
fftw3_LIBS = -lfftw3 -lm
fftw3_threads_LIBS = 
host = x86_64-unknown-linux-gnu
host_alias = 
host_cpu = x86_64
host_os = linux-gnu
host_vendor = unknown
htmldir = ${docdir}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
install_sh = ${SHELL} /data/Work/pbmoma/src/third/nfft/config/install-sh
libdir = ${exec_prefix}/lib
libexecdir = ${exec_prefix}/libexec
localedir = ${datarootdir}/locale
localstatedir = ${prefix}/var
mandir = ${datarootdir}/man
matlab_CPPFLAGS = 
matlab_LDFLAGS = 
matlab_LIBS = 
matlab_fftw3_LDFLAGS = 
matlab_fftw3_LIBS = 
matlab_mexext = 
matlab_prog_mexext = 
mkdir_p = /bin/mkdir -p
oldincludedir = /usr/include
pdfdir = ${docdir}
prefix = /usr/local
program_transform_name = s,x,x,
psdir = ${docdir}
sbindir = ${exec_prefix}/sbin
sharedstatedir = ${prefix}/com
srcdir = .
sysconfdir = ${prefix}/etc
target_alias = 
top_build_prefix = ../../
top_builddir = ../..
top_srcdir = ../..
AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/3rdparty/cstripack
LIBUTIL_THREADS_LA = 
#LIBUTIL_THREADS_LA = libutil_threads.la
noinst_LTLIBRARIES = libutil.la $(LIBUTIL_THREADS_LA)
libutil_la_SOURCES = malloc.c sinc.c lambda.c bessel_i0.c float.c int.c error.c bspline.c assert.c sort.c rand.c vector1.c vector2.c vector3.c print.c voronoi.c damp.c thread.c time.c window.c version.c
#libutil_threads_la_SOURCES = $(libutil_la_SOURCES)
#libutil_threads_la_CFLAGS = $(OPENMP_CFLAGS)
all: all-am

.SUFFIXES:
.SUFFIXES: .c .lo .o .obj
$(srcdir)/Makefile.in: # $(srcdir)/Makefile.am  $(am__configure_deps)
	@for dep in $?; do \
	  case '$(am__configure_deps)' in \
	    *$$dep*) \
	      ( cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh ) \
	        && { if test -f $@; then exit 0; else break; fi; }; \
	      exit 1;; \
	  esac; \
	done; \
	echo ' cd $(top_srcdir) && $(AUTOMAKE) --gnu kernel/util/Makefile'; \
	$(am__cd) $(top_srcdir) && \
	  $(AUTOMAKE) --gnu kernel/util/Makefile
.PRECIOUS: Makefile
Makefile: $(srcdir)/Makefile.in $(top_builddir)/config.status
	@case '$?' in \
	  *config.status*) \
	    cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh;; \
	  *) \
	    echo ' cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe)'; \
	    cd $(top_builddir) && $(SHELL) ./config.status $(subdir)/$@ $(am__depfiles_maybe);; \
	esac;

$(top_builddir)/config.status: $(top_srcdir)/configure $(CONFIG_STATUS_DEPENDENCIES)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh

$(top_srcdir)/configure: # $(am__configure_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(ACLOCAL_M4): # $(am__aclocal_m4_deps)
	cd $(top_builddir) && $(MAKE) $(AM_MAKEFLAGS) am--refresh
$(am__aclocal_m4_deps):

clean-noinstLTLIBRARIES:
	-test -z "$(noinst_LTLIBRARIES)" || rm -f $(noinst_LTLIBRARIES)
	@list='$(noinst_LTLIBRARIES)'; for p in $$list; do \
	  dir="`echo $$p | sed -e 's|/[^/]*$$||'`"; \
	  test "$$dir" != "$$p" || dir=.; \
	  echo "rm -f \"$${dir}/so_locations\""; \
	  rm -f "$${dir}/so_locations"; \
	done
libutil.la: $(libutil_la_OBJECTS) $(libutil_la_DEPENDENCIES) $(EXTRA_libutil_la_DEPENDENCIES) 
	$(LINK)  $(libutil_la_OBJECTS) $(libutil_la_LIBADD) $(LIBS)
libutil_threads.la: $(libutil_threads_la_OBJECTS) $(libutil_threads_la_DEPENDENCIES) $(EXTRA_libutil_threads_la_DEPENDENCIES) 
	$(libutil_threads_la_LINK) $(am_libutil_threads_la_rpath) $(libutil_threads_la_OBJECTS) $(libutil_threads_la_LIBADD) $(LIBS)

mostlyclean-compile:
	-rm -f *.$(OBJEXT)

distclean-compile:
	-rm -f *.tab.c

include ./$(DEPDIR)/assert.Plo
include ./$(DEPDIR)/bessel_i0.Plo
include ./$(DEPDIR)/bspline.Plo
include ./$(DEPDIR)/damp.Plo
include ./$(DEPDIR)/error.Plo
include ./$(DEPDIR)/float.Plo
include ./$(DEPDIR)/int.Plo
include ./$(DEPDIR)/lambda.Plo
include ./$(DEPDIR)/libutil_threads_la-assert.Plo
include ./$(DEPDIR)/libutil_threads_la-bessel_i0.Plo
include ./$(DEPDIR)/libutil_threads_la-bspline.Plo
include ./$(DEPDIR)/libutil_threads_la-damp.Plo
include ./$(DEPDIR)/libutil_threads_la-error.Plo
include ./$(DEPDIR)/libutil_threads_la-float.Plo
include ./$(DEPDIR)/libutil_threads_la-int.Plo
include ./$(DEPDIR)/libutil_threads_la-lambda.Plo
include ./$(DEPDIR)/libutil_threads_la-malloc.Plo
include ./$(DEPDIR)/libutil_threads_la-print.Plo
include ./$(DEPDIR)/libutil_threads_la-rand.Plo
include ./$(DEPDIR)/libutil_threads_la-sinc.Plo
include ./$(DEPDIR)/libutil_threads_la-sort.Plo
include ./$(DEPDIR)/libutil_threads_la-thread.Plo
include ./$(DEPDIR)/libutil_threads_la-time.Plo
include ./$(DEPDIR)/libutil_threads_la-vector1.Plo
include ./$(DEPDIR)/libutil_threads_la-vector2.Plo
include ./$(DEPDIR)/libutil_threads_la-vector3.Plo
include ./$(DEPDIR)/libutil_threads_la-version.Plo
include ./$(DEPDIR)/libutil_threads_la-voronoi.Plo
include ./$(DEPDIR)/libutil_threads_la-window.Plo
include ./$(DEPDIR)/malloc.Plo
include ./$(DEPDIR)/print.Plo
include ./$(DEPDIR)/rand.Plo
include ./$(DEPDIR)/sinc.Plo
include ./$(DEPDIR)/sort.Plo
include ./$(DEPDIR)/thread.Plo
include ./$(DEPDIR)/time.Plo
include ./$(DEPDIR)/vector1.Plo
include ./$(DEPDIR)/vector2.Plo
include ./$(DEPDIR)/vector3.Plo
include ./$(DEPDIR)/version.Plo
include ./$(DEPDIR)/voronoi.Plo
include ./$(DEPDIR)/window.Plo

.c.o:
	$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(COMPILE) -c $<

.c.obj:
	$(COMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ `$(CYGPATH_W) '$<'`
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po
#	source='$<' object='$@' libtool=no \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(COMPILE) -c `$(CYGPATH_W) '$<'`

.c.lo:
	$(LTCOMPILE) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $<
	$(am__mv) $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Plo
#	source='$<' object='$@' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LTCOMPILE) -c -o $@ $<

libutil_threads_la-malloc.lo: malloc.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-malloc.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-malloc.Tpo -c -o libutil_threads_la-malloc.lo `test -f 'malloc.c' || echo '$(srcdir)/'`malloc.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-malloc.Tpo $(DEPDIR)/libutil_threads_la-malloc.Plo
#	source='malloc.c' object='libutil_threads_la-malloc.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-malloc.lo `test -f 'malloc.c' || echo '$(srcdir)/'`malloc.c

libutil_threads_la-sinc.lo: sinc.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-sinc.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-sinc.Tpo -c -o libutil_threads_la-sinc.lo `test -f 'sinc.c' || echo '$(srcdir)/'`sinc.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-sinc.Tpo $(DEPDIR)/libutil_threads_la-sinc.Plo
#	source='sinc.c' object='libutil_threads_la-sinc.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-sinc.lo `test -f 'sinc.c' || echo '$(srcdir)/'`sinc.c

libutil_threads_la-lambda.lo: lambda.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-lambda.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-lambda.Tpo -c -o libutil_threads_la-lambda.lo `test -f 'lambda.c' || echo '$(srcdir)/'`lambda.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-lambda.Tpo $(DEPDIR)/libutil_threads_la-lambda.Plo
#	source='lambda.c' object='libutil_threads_la-lambda.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-lambda.lo `test -f 'lambda.c' || echo '$(srcdir)/'`lambda.c

libutil_threads_la-bessel_i0.lo: bessel_i0.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-bessel_i0.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-bessel_i0.Tpo -c -o libutil_threads_la-bessel_i0.lo `test -f 'bessel_i0.c' || echo '$(srcdir)/'`bessel_i0.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-bessel_i0.Tpo $(DEPDIR)/libutil_threads_la-bessel_i0.Plo
#	source='bessel_i0.c' object='libutil_threads_la-bessel_i0.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-bessel_i0.lo `test -f 'bessel_i0.c' || echo '$(srcdir)/'`bessel_i0.c

libutil_threads_la-float.lo: float.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-float.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-float.Tpo -c -o libutil_threads_la-float.lo `test -f 'float.c' || echo '$(srcdir)/'`float.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-float.Tpo $(DEPDIR)/libutil_threads_la-float.Plo
#	source='float.c' object='libutil_threads_la-float.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-float.lo `test -f 'float.c' || echo '$(srcdir)/'`float.c

libutil_threads_la-int.lo: int.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-int.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-int.Tpo -c -o libutil_threads_la-int.lo `test -f 'int.c' || echo '$(srcdir)/'`int.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-int.Tpo $(DEPDIR)/libutil_threads_la-int.Plo
#	source='int.c' object='libutil_threads_la-int.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-int.lo `test -f 'int.c' || echo '$(srcdir)/'`int.c

libutil_threads_la-error.lo: error.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-error.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-error.Tpo -c -o libutil_threads_la-error.lo `test -f 'error.c' || echo '$(srcdir)/'`error.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-error.Tpo $(DEPDIR)/libutil_threads_la-error.Plo
#	source='error.c' object='libutil_threads_la-error.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-error.lo `test -f 'error.c' || echo '$(srcdir)/'`error.c

libutil_threads_la-bspline.lo: bspline.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-bspline.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-bspline.Tpo -c -o libutil_threads_la-bspline.lo `test -f 'bspline.c' || echo '$(srcdir)/'`bspline.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-bspline.Tpo $(DEPDIR)/libutil_threads_la-bspline.Plo
#	source='bspline.c' object='libutil_threads_la-bspline.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-bspline.lo `test -f 'bspline.c' || echo '$(srcdir)/'`bspline.c

libutil_threads_la-assert.lo: assert.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-assert.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-assert.Tpo -c -o libutil_threads_la-assert.lo `test -f 'assert.c' || echo '$(srcdir)/'`assert.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-assert.Tpo $(DEPDIR)/libutil_threads_la-assert.Plo
#	source='assert.c' object='libutil_threads_la-assert.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-assert.lo `test -f 'assert.c' || echo '$(srcdir)/'`assert.c

libutil_threads_la-sort.lo: sort.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-sort.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-sort.Tpo -c -o libutil_threads_la-sort.lo `test -f 'sort.c' || echo '$(srcdir)/'`sort.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-sort.Tpo $(DEPDIR)/libutil_threads_la-sort.Plo
#	source='sort.c' object='libutil_threads_la-sort.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-sort.lo `test -f 'sort.c' || echo '$(srcdir)/'`sort.c

libutil_threads_la-rand.lo: rand.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-rand.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-rand.Tpo -c -o libutil_threads_la-rand.lo `test -f 'rand.c' || echo '$(srcdir)/'`rand.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-rand.Tpo $(DEPDIR)/libutil_threads_la-rand.Plo
#	source='rand.c' object='libutil_threads_la-rand.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-rand.lo `test -f 'rand.c' || echo '$(srcdir)/'`rand.c

libutil_threads_la-vector1.lo: vector1.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-vector1.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-vector1.Tpo -c -o libutil_threads_la-vector1.lo `test -f 'vector1.c' || echo '$(srcdir)/'`vector1.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-vector1.Tpo $(DEPDIR)/libutil_threads_la-vector1.Plo
#	source='vector1.c' object='libutil_threads_la-vector1.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-vector1.lo `test -f 'vector1.c' || echo '$(srcdir)/'`vector1.c

libutil_threads_la-vector2.lo: vector2.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-vector2.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-vector2.Tpo -c -o libutil_threads_la-vector2.lo `test -f 'vector2.c' || echo '$(srcdir)/'`vector2.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-vector2.Tpo $(DEPDIR)/libutil_threads_la-vector2.Plo
#	source='vector2.c' object='libutil_threads_la-vector2.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-vector2.lo `test -f 'vector2.c' || echo '$(srcdir)/'`vector2.c

libutil_threads_la-vector3.lo: vector3.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-vector3.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-vector3.Tpo -c -o libutil_threads_la-vector3.lo `test -f 'vector3.c' || echo '$(srcdir)/'`vector3.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-vector3.Tpo $(DEPDIR)/libutil_threads_la-vector3.Plo
#	source='vector3.c' object='libutil_threads_la-vector3.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-vector3.lo `test -f 'vector3.c' || echo '$(srcdir)/'`vector3.c

libutil_threads_la-print.lo: print.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-print.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-print.Tpo -c -o libutil_threads_la-print.lo `test -f 'print.c' || echo '$(srcdir)/'`print.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-print.Tpo $(DEPDIR)/libutil_threads_la-print.Plo
#	source='print.c' object='libutil_threads_la-print.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-print.lo `test -f 'print.c' || echo '$(srcdir)/'`print.c

libutil_threads_la-voronoi.lo: voronoi.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-voronoi.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-voronoi.Tpo -c -o libutil_threads_la-voronoi.lo `test -f 'voronoi.c' || echo '$(srcdir)/'`voronoi.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-voronoi.Tpo $(DEPDIR)/libutil_threads_la-voronoi.Plo
#	source='voronoi.c' object='libutil_threads_la-voronoi.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-voronoi.lo `test -f 'voronoi.c' || echo '$(srcdir)/'`voronoi.c

libutil_threads_la-damp.lo: damp.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-damp.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-damp.Tpo -c -o libutil_threads_la-damp.lo `test -f 'damp.c' || echo '$(srcdir)/'`damp.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-damp.Tpo $(DEPDIR)/libutil_threads_la-damp.Plo
#	source='damp.c' object='libutil_threads_la-damp.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-damp.lo `test -f 'damp.c' || echo '$(srcdir)/'`damp.c

libutil_threads_la-thread.lo: thread.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-thread.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-thread.Tpo -c -o libutil_threads_la-thread.lo `test -f 'thread.c' || echo '$(srcdir)/'`thread.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-thread.Tpo $(DEPDIR)/libutil_threads_la-thread.Plo
#	source='thread.c' object='libutil_threads_la-thread.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-thread.lo `test -f 'thread.c' || echo '$(srcdir)/'`thread.c

libutil_threads_la-time.lo: time.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-time.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-time.Tpo -c -o libutil_threads_la-time.lo `test -f 'time.c' || echo '$(srcdir)/'`time.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-time.Tpo $(DEPDIR)/libutil_threads_la-time.Plo
#	source='time.c' object='libutil_threads_la-time.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-time.lo `test -f 'time.c' || echo '$(srcdir)/'`time.c

libutil_threads_la-window.lo: window.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-window.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-window.Tpo -c -o libutil_threads_la-window.lo `test -f 'window.c' || echo '$(srcdir)/'`window.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-window.Tpo $(DEPDIR)/libutil_threads_la-window.Plo
#	source='window.c' object='libutil_threads_la-window.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-window.lo `test -f 'window.c' || echo '$(srcdir)/'`window.c

libutil_threads_la-version.lo: version.c
	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -MT libutil_threads_la-version.lo -MD -MP -MF $(DEPDIR)/libutil_threads_la-version.Tpo -c -o libutil_threads_la-version.lo `test -f 'version.c' || echo '$(srcdir)/'`version.c
	$(am__mv) $(DEPDIR)/libutil_threads_la-version.Tpo $(DEPDIR)/libutil_threads_la-version.Plo
#	source='version.c' object='libutil_threads_la-version.lo' libtool=yes \
#	DEPDIR=$(DEPDIR) $(CCDEPMODE) $(depcomp) \
#	$(LIBTOOL)  --tag=CC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(CC) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(libutil_threads_la_CFLAGS) $(CFLAGS) -c -o libutil_threads_la-version.lo `test -f 'version.c' || echo '$(srcdir)/'`version.c

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

ID: $(HEADERS) $(SOURCES) $(LISP) $(TAGS_FILES)
	list='$(SOURCES) $(HEADERS) $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	mkid -fID $$unique
tags: TAGS

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	set x; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	shift; \
	if test -z "$(ETAGS_ARGS)$$*$$unique"; then :; else \
	  test -n "$$unique" || unique=$$empty_fix; \
	  if test $$# -gt 0; then \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      "$$@" $$unique; \
	  else \
	    $(ETAGS) $(ETAGSFLAGS) $(AM_ETAGSFLAGS) $(ETAGS_ARGS) \
	      $$unique; \
	  fi; \
	fi
ctags: CTAGS
CTAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) \
		$(TAGS_FILES) $(LISP)
	list='$(SOURCES) $(HEADERS)  $(LISP) $(TAGS_FILES)'; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '{ files[$$0] = 1; nonempty = 1; } \
	      END { if (nonempty) { for (i in files) print i; }; }'`; \
	test -z "$(CTAGS_ARGS)$$unique" \
	  || $(CTAGS) $(CTAGSFLAGS) $(AM_CTAGSFLAGS) $(CTAGS_ARGS) \
	     $$unique

GTAGS:
	here=`$(am__cd) $(top_builddir) && pwd` \
	  && $(am__cd) $(top_srcdir) \
	  && gtags -i $(GTAGS_ARGS) "$$here"

distclean-tags:
	-rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags

distdir: $(DISTFILES)
	@srcdirstrip=`echo "$(srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	topsrcdirstrip=`echo "$(top_srcdir)" | sed 's/[].[^$$\\*]/\\\\&/g'`; \
	list='$(DISTFILES)'; \
	  dist_files=`for file in $$list; do echo $$file; done | \
	  sed -e "s|^$$srcdirstrip/||;t" \
	      -e "s|^$$topsrcdirstrip/|$(top_builddir)/|;t"`; \
	case $$dist_files in \
	  */*) $(MKDIR_P) `echo "$$dist_files" | \
			   sed '/\//!d;s|^|$(distdir)/|;s,/[^/]*$$,,' | \
			   sort -u` ;; \
	esac; \
	for file in $$dist_files; do \
	  if test -f $$file || test -d $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    dir=`echo "/$$file" | sed -e 's,/[^/]*$$,,'`; \
	    if test -d "$(distdir)/$$file"; then \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    if test -d $(srcdir)/$$file && test $$d != $(srcdir); then \
	      cp -fpR $(srcdir)/$$file "$(distdir)$$dir" || exit 1; \
	      find "$(distdir)/$$file" -type d ! -perm -700 -exec chmod u+rwx {} \;; \
	    fi; \
	    cp -fpR $$d/$$file "$(distdir)$$dir" || exit 1; \
	  else \
	    test -f "$(distdir)/$$file" \
	    || cp -p $$d/$$file "$(distdir)/$$file" \
	    || exit 1; \
	  fi; \
	done
check-am: all-am
check: check-am
all-am: Makefile $(LTLIBRARIES)
installdirs:
install: install-am
install-exec: install-exec-am
install-data: install-data-am
uninstall: uninstall-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am

installcheck: installcheck-am
install-strip:
	if test -z '$(STRIP)'; then \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	      install; \
	else \
	  $(MAKE) $(AM_MAKEFLAGS) INSTALL_PROGRAM="$(INSTALL_STRIP_PROGRAM)" \
	    install_sh_PROGRAM="$(INSTALL_STRIP_PROGRAM)" INSTALL_STRIP_FLAG=-s \
	    "INSTALL_PROGRAM_ENV=STRIPPROG='$(STRIP)'" install; \
	fi
mostlyclean-generic:

clean-generic:

distclean-generic:
	-test -z "$(CONFIG_CLEAN_FILES)" || rm -f $(CONFIG_CLEAN_FILES)
	-test . = "$(srcdir)" || test -z "$(CONFIG_CLEAN_VPATH_FILES)" || rm -f $(CONFIG_CLEAN_VPATH_FILES)

maintainer-clean-generic:
	@echo "This command is intended for maintainers to use"
	@echo "it deletes files that may require special tools to rebuild."
clean: clean-am

clean-am: clean-generic clean-libtool clean-noinstLTLIBRARIES \
	mostlyclean-am

distclean: distclean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
distclean-am: clean-am distclean-compile distclean-generic \
	distclean-tags

dvi: dvi-am

dvi-am:

html: html-am

html-am:

info: info-am

info-am:

install-data-am:

install-dvi: install-dvi-am

install-dvi-am:

install-exec-am:

install-html: install-html-am

install-html-am:

install-info: install-info-am

install-info-am:

install-man:

install-pdf: install-pdf-am

install-pdf-am:

install-ps: install-ps-am

install-ps-am:

installcheck-am:

maintainer-clean: maintainer-clean-am
	-rm -rf ./$(DEPDIR)
	-rm -f Makefile
maintainer-clean-am: distclean-am maintainer-clean-generic

mostlyclean: mostlyclean-am

mostlyclean-am: mostlyclean-compile mostlyclean-generic \
	mostlyclean-libtool

pdf: pdf-am

pdf-am:

ps: ps-am

ps-am:

uninstall-am:

.MAKE: install-am install-strip

.PHONY: CTAGS GTAGS all all-am check check-am clean clean-generic \
	clean-libtool clean-noinstLTLIBRARIES ctags distclean \
	distclean-compile distclean-generic distclean-libtool \
	distclean-tags distdir dvi dvi-am html html-am info info-am \
	install install-am install-data install-data-am install-dvi \
	install-dvi-am install-exec install-exec-am install-html \
	install-html-am install-info install-info-am install-man \
	install-pdf install-pdf-am install-ps install-ps-am \
	install-strip installcheck installcheck-am installdirs \
	maintainer-clean maintainer-clean-generic mostlyclean \
	mostlyclean-compile mostlyclean-generic mostlyclean-libtool \
	pdf pdf-am ps ps-am tags uninstall uninstall-am


# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
