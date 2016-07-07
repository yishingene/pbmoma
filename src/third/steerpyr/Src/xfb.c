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

#include "xfb.h"

/*
 * ========================================================================
 * InitX(): initialize an X window.
 * ========================================================================
 */
InitX( idispwin, name, xpos, ypos, w, h )
     int idispwin;
     char *name;
     int   w,h;
{
  Display *display;
  Window window;
  
  wname = name;
  
  if( (display = XOpenDisplay( NULL )) == NULL ) {
    fprintf( stderr, "Can't open display\n" );
    exit( -1 );
  }
  
  theScreen = DefaultScreen(display);
  theCmap   = DefaultColormap(display, theScreen);
  rootW     = RootWindow(display,theScreen);
  theGC     = DefaultGC(display,theScreen);
  theVisual = DefaultVisual(display,theScreen);
  ncells    = DisplayCells(display, theScreen);
  dispWIDE  = DisplayWidth(display,theScreen);
  dispHIGH  = DisplayHeight(display,theScreen);
  dispDEEP  = DisplayPlanes(display,theScreen);
  
  white = WhitePixel(display,theScreen);
  black = BlackPixel(display,theScreen);
  
  window = createWindow( display, xpos, ypos, w, h );
  XMapWindow( display, window );
  
  /* Generate a colormap */
  if( dispDEEP == 8 || dispDEEP == 4 ) {   
    XColor c;
    int    i, j, j2, k, err;
    
    err = 0;
    for( i=0; i<NUMGRAY; i++ ) {
      c.red = c.green = c.blue = (i*0xffff)/(NUMGRAY-1);
      if( !XAllocColor( display, theCmap, &c ) ) 
	err++;
      grays[i] = c.pixel;
    }
    
    if (err) {
      fprintf( stderr,
	      "Warning: problem allocating %d colors\n",err);
    }
  }
  
  
  XFlush( display );
  
  dispwin[ idispwin ].display = display;
  dispwin[ idispwin ].window = window;
}

/*
 * ========================================================================
 * createWindow():  called by InitX().
 * ========================================================================
 */
static Window createWindow( display, xpos, ypos, w, h )
     Display *display;
     int xpos, ypos, w, h;
{
  Window window;
  XSetWindowAttributes xswa;
  unsigned int         xswamask;
  XSizeHints           hints;
  int                  x,y;
  
  hints.x = xpos;        hints.y = ypos;
  hints.width = w;       hints.height = h;
  hints.max_width  = w;  hints.max_height = h;
  hints.min_width  = w;  hints.min_height = h;
  hints.flags = USPosition | USSize | PMaxSize | PMinSize;
  
  xswa.background_pixel = black;
  xswa.border_pixel     = white;
  xswamask = CWBackPixel | CWBorderPixel;
  
  window = XCreateWindow( display, rootW, hints.x, hints.y, w, h, 2, 0,
			 CopyFromParent, CopyFromParent, xswamask, &xswa );
  if( !window ) {
    fprintf( stderr, "Can't create window" );
    exit(-1);
  }
  
  XSetStandardProperties( display, window, wname, wname, None, 0, NULL, 
			 &hints );
  
  return( window );
}

/*
 * ========================================================================
 * DrawImage8(): blast an 8-bit image to an X window.
 * ========================================================================
 */
static XImage *ximage = NULL;
static byte   *epic   = NULL;
static long   lastsize = 0;

/* The scale and pedestal are used to scale the values between the
   range [0 and 255] */
DrawImage8( idispwin, p, x, y, w, h, scale, pedestal)
     int idispwin;
     float *p;
     float scale,pedestal;
     int x, y, w, h;
{
  int i, j, k, bperlin, pad;
  byte *ep;
  float *pp;
  float value;
  long size;
  Display *display;
  Window window;
  
  display = dispwin[ idispwin ].display;
  window = dispwin[ idispwin ].window;
  
  /* note: have to pad epic so that it's a multiple of 32-bits per line */
  size = w * h;
  bperlin = (w + 3) & (~3);
  pad = bperlin - w;
  
  if( size != lastsize || !epic ) { /* have to re-allocate epic */
    if( epic )
      free( epic );
    epic = (byte *)malloc( bperlin * h );
    if( !epic ) { 
      fprintf( stderr, "Can't malloc epic\n" ); 
      return; 
    }
  }
  
  ep = epic;
  pp = p;
  for (i=0; i<h; i++){
    for (j=0;j<w;j++){
      value =  (pp[j] * scale) + pedestal;
      if (value < 0.0) value = 0.0;
      else if (value > 255.0) value = 255.0;
      ep[j] = (byte) value;
    }
    ep += bperlin;
    pp = &(pp[w]); 
  }
  
  for (i=0, ep=epic; i<bperlin*h; i++,ep++) {
    /* map gray values to colormap indicies */
    *ep = (byte) grays[ *ep >> GRAYSHIFT];
  }
  
  
  if (!ximage || size != lastsize) {    /* create XImage  */
    if( ximage ) 
      XDestroyImage(ximage);
    ximage = XCreateImage( display, theVisual, dispDEEP, ZPixmap, 0,
			  (char *)epic, w, h, 32, bperlin );
  }
  
  XPutImage( display, window, theGC, ximage, 0, 0, x, y, w, h );
  lastsize = size;
}

DrawLine(idispwin, x, y, x1, y1, c)
     int x, y, x1, y1, c;
{
  int i;
  Display *display;
  Window window;
  
  display = dispwin[ idispwin ].display;
  window = dispwin[ idispwin ].window;
  
  c >>= GRAYSHIFT;   /* shift down to # of grays we have */
  /* should actually set color to cols[c] */
  XSetForeground(display,theGC, grays[c]);

  XDrawLine(display, window, theGC, x, y, x1, y1);
  XFlush(display);
}
