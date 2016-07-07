/*
 * -------------------------------------------------------------------
 *		   Steerable Pyramid Software Library
 *    Designed by Eero Simoncelli, Rob Buccigrassi and Hany Farid.
 *         Developed at the GRASP Laboratory, Computer and 		
 *	Information Science  Department, University of Pennsylvania.	
 *	        Copyright 1995, University of Pennsylvania 		
 *			 All rights reserved.				
 * -------------------------------------------------------------------
*/

/*
 * ========================================================================
 * show_pyramid:  For demonstration purposes, display one subband of the
 * pyramid along with the high and low bands.
 * ========================================================================
 */

#include <stdio.h>
#include "spyramid_pgm.h"
#define OPTIONS "f:p:l:s:" /* : after character means flag has an argument */

extern int optind; extern char *optarg;
main(argc, argv)
int argc;
char **argv;
{  
  int  errflag=0, c;
  int level=1,subband=0;
  char *filter_file=NULL;
  char *image_file=NULL;
  PFILTER PF;
  MATRIX M;
  PYRAMID P;
  
  while  ((c = getopt(argc, argv, OPTIONS)) != EOF) /* parse command line */
    switch(c)                                  
      {   case 'f': filter_file = optarg;
	break;                      
      case 'p': image_file = optarg;
	break;                      
      case 'l': level = atoi(optarg);
	break;                      
      case 's': subband = atoi(optarg);
	break;                      
      case '?': ++errflag; break;           
      }
  /* errors */
  if (filter_file == NULL) errflag++;
  if (image_file == NULL) errflag++;
  if (errflag) {
    printf("usage:   %s -f filter_file -p image_file -l numlevels -s subband\n",argv[0]);
    exit(-1);
  }
  if (level < 1) level = 1;
  if (subband < 0) subband = 0;
  
  PF = LoadPFilter(filter_file);
  if (PF == NULL) {
    fprintf(stderr,"Unable to open filter file\n");
    exit(-1);
  }
  M = LoadMatrix(image_file);
  if (M == NULL) {
    fprintf(stderr,"Unable to open image file\n");
    exit(-1);
  }
  if (((M->rows >> level) < 1) || ((M->columns >> level) < 1)){
    fprintf(stderr,"Image too small for the given level depth\n");
    exit(-1);
  }
  P = CreatePyramid(M,PF,level);
  DisplayPyramid(P,subband,0,image_file,20,20);
  fgetc(stdin);	/* terminate */
}
