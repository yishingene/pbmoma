#------------------------------------------------------------------------
#
#  Makefile for Steerable Filters
#  Professor Eero Simoncelli
#  Hany Farid
#  Robert Buccigrossi
#
#------------------------------------------------------------------------

### These may have to be adjusted for your system...
X11INCLUDE= /usr/openwin/include/ 
X11LIB= /usr/openwin/lib

IFLAGS= -I${X11INCLUDE}
LFLAGS= -L${X11LIB} -lm -lX11
CFLAGS= -DSYSV 
CC = gcc -O2 
AR = ar
RANLIB = ranlib

BIN_DIR = ../Demo
ARCHIVE_DIR = ..

SHOW_PFILTER = ${BIN_DIR}/show_pfilter
SHOW_PYRAMID = ${BIN_DIR}/show_pyramid
SHOW_STEER = ${BIN_DIR}/show_steer
ARCHIVE = ${ARCHIVE_DIR}/libspyr.a

SPYR_OBJ= itrp_sin.o matrix.o spyramid.o matrix_pgm.o\
	 convolve.o edges.o wrap.o spyramid_pgm.o xfb.o
SHOW_PFILTER_OBJ= show_pfilter.o ${SPYR_OBJ}
SHOW_PYRAMID_OBJ= show_pyramid.o ${SPYR_OBJ}
SHOW_STEER_OBJ= show_steer.o ${SPYR_OBJ}
#------------------------------------------------------------------------
# programs
#------------------------------------------------------------------------

all: ${SHOW_PFILTER} ${SHOW_PYRAMID} ${SHOW_STEER} ${ARCHIVE}

${ARCHIVE}: ${SPYR_OBJ};
	${AR} r ${ARCHIVE} ${SPYR_OBJ};
	${RANLIB} ${ARCHIVE}

${SHOW_PFILTER}: ${SHOW_PFILTER_OBJ};
	${CC} ${SHOW_PFILTER_OBJ} -o ${SHOW_PFILTER} ${LFLAGS} ${CFLAGS}

show_pfilter.o: show_pfilter.c spyramid_pgm.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

${SHOW_PYRAMID}: ${SHOW_PYRAMID_OBJ};
	${CC} ${SHOW_PYRAMID_OBJ} -o ${SHOW_PYRAMID} ${LFLAGS} ${CFLAGS}

show_pyramid.o: show_pyramid.c spyramid_pgm.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

${SHOW_STEER}: ${SHOW_STEER_OBJ};
	${CC} ${SHOW_STEER_OBJ} -o ${SHOW_STEER} ${LFLAGS} ${CFLAGS}

show_steer.o: show_steer.c spyramid_pgm.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

itrp_sin.o: itrp_sin.c itrp_sin.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

matrix.o: matrix.c matrix.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

matrix_pgm.o: matrix_pgm.c matrix_pgm.h matrix.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

convolve.o: convolve.c convolve.h 
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

wrap.o: wrap.c wrap.h convolve.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

edges.o: edges.c convolve.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

spyramid.o: spyramid.c spyramid.h matrix.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

spyramid_pgm.o: spyramid_pgm.c spyramid_pgm.h spyramid.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}

xfb.o: xfb.c xfb.h
	${CC} -c $*.c ${IFLAGS} ${CFLAGS}
