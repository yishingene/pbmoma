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

/* This is the header files for the interpolated sine and cosine functions.
   Please refer to itrp_sin.c for more information */

#ifndef _ITRP_SIN_H
#define _ITRP_SIN_H

/* This determines the number of intervals in the array holding
   calculated values of sin and thus determine the accuracy of 
   itrp_sin() and itrp_cos() */
#define ITRP_INTERVALS		1000

double SetupInterpSin();
double itrp_sin(double x);
double itrp_cos(double x);

#endif /* _ITRP_SIN_H */
