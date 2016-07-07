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
 * show_steer:  For demonstration purposes, display a movie of image steered
 * to several non-basis positions.
 * ========================================================================
 */

#include <stdio.h>
#include <sys/time.h>
#include "spyramid.h"
#include "matrix_pgm.h"
#define OPTIONS "f:p:l:" /* : after character means flag has an argument */

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
  MATRIX M,N;
  PYRAMID P;
  int i,j;
  float max_val,min_val,new_val,scale,pedestal;
  struct timeval tp;
  struct timezone tz; 
  long usecs;

  while  ((c = getopt(argc, argv, OPTIONS)) != EOF) /* parse command line */
    switch(c)                                  
      {   case 'f': filter_file = optarg;
	break;                      
      case 'p': image_file = optarg;
	break;                      
      case 'l': level = atoi(optarg);
	break;                      
      case '?': ++errflag; break;           
      }
  if (level <= 0) level = 1;
  /* errors */
  if (filter_file == NULL) errflag++;
  if (image_file == NULL) errflag++;
  if (errflag) {
    printf("usage:   %s -f filter_file -p image_file -l numlevels\n",argv[0]);
    exit(-1);
  }
  
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
  
  level --;

  min_val = P->levels[level]->subband[0]->values[0];
  max_val = min_val;

  /* Do one complete rotation to compute max and min values */
  for (i=0;i<29;i++){
    N = SteerPyramid(P,level,((float) i) * 2 * 3.14159 / 29);
    for(j=0;j<(N->rows*N->columns);j++){
      new_val = N->values[j];
      if (min_val > new_val) min_val = new_val;
      if (max_val < new_val) max_val = new_val;
    }
    DeleteMatrix(N);
  }

  /* Compute max of absolute values, scale, then pedestal */
  if ((-min_val) > max_val) max_val = (-min_val);
  scale = 128.0/max_val;
  pedestal = 128.0;

  DisplayMatrix(P->levels[level]->subband[0],0,"Steer",0,0,scale,pedestal);

  /* Do one steering to determine time delay */
  gettimeofday(&tp, &tz);
  usecs = tp.tv_usec;

  N = SteerPyramid(P,level,((float) 1) * 2 * 3.14159 / 29);
  UpdateDisplayMatrix(N,0,scale,pedestal);
  DeleteMatrix(N);
  
  gettimeofday(&tp, &tz);
  usecs = tp.tv_usec - usecs;    /* Compute time difference in microseconds */

  usecs = 32000 - usecs;
  if (usecs < 0) usecs = 0;
  
  while(1){
    for (i=0;i<29;i++){
      N = SteerPyramid(P,level,((float) i) * 2 * 3.14159 / 29);
      UpdateDisplayMatrix(N,0,scale,pedestal);
      DeleteMatrix(N);
      usleep(usecs);
    }
  }
}
