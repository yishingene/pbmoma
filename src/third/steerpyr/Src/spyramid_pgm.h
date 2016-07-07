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

/* This is the header file for pyramid routines that convert them to pictures
   or display them as pictures */

#ifndef _SPYRAMID_PGM_H
#define _SPYRAMID_PGM_H

#include "spyramid.h"

void DisplayPfilter(PFILTER PF,int idispwin,char* name,int xloc, int yloc);
void DisplayPyramid(PYRAMID P, int subband, int idispwin, char* name,
                    int xloc, int yloc);

#endif /* _SPYRAMID_PGM_H */
