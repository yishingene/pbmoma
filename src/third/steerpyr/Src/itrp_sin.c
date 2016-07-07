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
 * itrp_sin.c:  lookup tables for sine and cosine - for speed up.
 * ========================================================================
 */

#include <stdio.h>
#include <math.h>
#include "itrp_sin.h"

static double * SinValues = NULL;


/* This routine allocates the array for the interpolated sine and cosine.
 *      If successful it returns 1, else it returns 0. */
int SetupIntrpSin(){
  int i;
  
  if (SinValues != NULL) return 1;       /* Don't do anything if already
                                            allocated */

  SinValues = (double *) malloc(sizeof(double) * (ITRP_INTERVALS+1));
  /* Malloc the memory */
  if (SinValues == NULL) return 0;       /* Fail if the Malloc failed */
  
  for (i=0;i<=ITRP_INTERVALS;i++){       /* Now set the array values */
    SinValues[i] = sin(((double) i) / ITRP_INTERVALS * M_PI);
  }
  
  return 1;                              /* We're done! */
}

/* This uses our precomputed sin values (in SinValues) to compute sine for
 *      general values of x (using interpolation */
double itrp_sin(double x){
  double index;
  double frac;
  
  if (SinValues == NULL){                /* If SinValues has not been defined,
                                            let's fill it first */
    if (!SetupIntrpSin()){               /* If allocating the memory fails,
                                            just return sin(x) */
      return sin(x);
    }
  }

  if ((x < 0) || (x >= 2.0 * M_PI)){     /* if x not in [0, 2 * M_PI] then
                                            bring x into that range */
    return itrp_sin(x - (floor(x / (2.0*M_PI)) * (2.0 * M_PI)));
  } else if ( x > M_PI ){                /* if x in (M_PI, 2 * M_PI] then 
                                            bring x into [0, M_PI] */
    return (- itrp_sin((2.0 * M_PI) - x));
  } else if ( x > (M_PI / 2.0)){         /* if x in (M_PI/2, M_PI] then bring
                                            x into [0, M_PI/2] */
    return (itrp_sin(M_PI-x));
  } else {                               /* if x in [0, M_PI] interpolate */
    index = floor(x / M_PI * ITRP_INTERVALS);
    frac = (x / M_PI * ITRP_INTERVALS) - index;
                                         /* frac is the fraction the x lies
                                            between index and index+1 */
    return (SinValues[(int) index] * (1 - frac) +
            SinValues[(int) index + 1] * frac);
  }
}

/* This function uses itrp_sin to return the cosine value of the parameter */
double itrp_cos(double x){
  return itrp_sin(x + (M_PI / 2.0));
}
