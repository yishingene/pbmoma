/* This is the header file for the steerable pfilter routines.
   Please refer to spfilter.c for more information */

#ifndef _SPYRAMID_H
#define _SPYRAMID_H

#include "matrix.h"

/* steerable filters for generating pyramid */
typedef struct _pfilter { 
  int num_orientations;
  MATRIX *subband_filters;
  MATRIX fst_lowband_filter;
  MATRIX snd_lowband_filter;
  int use_highband;
  MATRIX highband_filter;
  char fwd_conv_type[CONV_NAME_LEN+1];
  char inv_conv_type[CONV_NAME_LEN+1];
  int num_harmonics;
  int *harmonics;
  MATRIX interp;
} * PFILTER;            


/* pyramid subbands - used by struct _pyramid */
typedef struct _pband { 
  MATRIX *subband;
} * PBAND;                      

/* the pyramid */
typedef struct _pyramid { 
  PFILTER pfilter;
  MATRIX lowband;
  MATRIX hiband;
  int num_levels;
  PBAND *levels;
} * PYRAMID;            


/* Function Prototypes */
MATRIX GetHighbandFilter(PFILTER P);
MATRIX GetFirstLowbandFilter(PFILTER P);
MATRIX GetSecondLowbandFilter(PFILTER P);
MATRIX GetSubbandFilter(PFILTER P, int orientation);
PFILTER LoadPFilter(char *filename);
int SavePFilter(PFILTER P, char *filename);

MATRIX GetHighbandImage(PYRAMID PY);
MATRIX GetLowbandImage(PYRAMID PY);
MATRIX GetSubbandImage(PYRAMID PY, int level, int orientation);
PYRAMID CreatePyramid(MATRIX M, PFILTER PF, int levels);
MATRIX CollapsePyramid(PYRAMID PY);
MATRIX SteerPyramid(PYRAMID PY, int level, float angle);
MATRIX SteerPyramidPointwise(PYRAMID PY, int level, MATRIX angles);

void ISteerPyramid(MATRIX M, MATRIX K, MATRIX B, PYRAMID PY, 
                   int level, float angle);
void ISteerPyramidPointwise(MATRIX M, MATRIX K, MATRIX B, PYRAMID PY, 
                            int level, MATRIX angles);

#endif /* _SPYRAMID_H */
