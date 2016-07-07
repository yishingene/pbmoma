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
 * show_pfilter:  For demonstration purposes, displays the steerable filters
 * along with the high and low band filters.
 * ========================================================================
 */

#include <stdio.h>
#include "spyramid_pgm.h"
#define OPTIONS "f:" /* : after character means flag has an argument */

extern int optind; extern char *optarg;
main(argc, argv)
     int argc;
     char **argv;
{  
  int  errflag=0, c;
  char *filter_file=NULL;
  PFILTER PF;
  
  while  ((c = getopt(argc, argv, OPTIONS)) != EOF) /* parse command line */
    switch(c)                                  
      {   case 'f': filter_file = optarg;
	break;                      
      case '?': ++errflag; break;           
      }
  /* errors */
  if (filter_file == NULL) errflag++;
  if (errflag) {
    printf("usage:   %s -f filter_file\n",argv[0]);
    exit(-1);
  }
  
  PF = LoadPFilter(filter_file);
  if (PF == NULL) {
    fprintf(stderr,"Unable to open filter file\n");
    exit(-1);
  }
  DisplayPfilter(PF,0,filter_file,20,20);
  fgetc(stdin);	/* terminate */
}
