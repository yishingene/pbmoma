/*
 * ========================================================================
 * xfb.c - library of routines for non-X programs that want to do 
 *         quick X graphics, without dramatically re-writing the code
 *         currently requires an 8bit color X display
 *
 *  Author:    John Bradley (bradley@cis.upenn.edu)
 *
 *  Modified:  Hany Farid
 * ========================================================================
 */

#include <stdio.h>
#include <X11/Xos.h>		/* X stuff */
#include <X11/Xlib.h>		/* X stuff */
#include <X11/Xutil.h>		/* X stuff */

/* Bundle up the X display and window parameters into a single struct */
#define MAXDISPWIN   5

struct dispwintag {	/* bundle the X display and window */
  Display *display;
  Window window;
} dispwin[ MAXDISPWIN ];

#define NUMGRAY   64
#define GRAYSHIFT  2    /* # to shift down to map 0-255 into 0-(numgray-1) */

typedef unsigned char byte;
static int           theScreen;
static unsigned int  ncells, dispWIDE, dispHIGH, dispDEEP;
static Colormap      theCmap, LocalCmap;
static Window        rootW;
static GC            theGC;
static Visual        *theVisual;
static XImage        *theImage;     /* X version of epic */
static unsigned long cols[256];     /* X color table stuff */
static XColor        defs[256];
unsigned long        white, black;
XFontStruct          *mfinfo;
Font                 mfont;

/* not directly X stuff */
static char *wname;
static Window createWindow();

/* color table stuff */
unsigned long grays[NUMGRAY];


