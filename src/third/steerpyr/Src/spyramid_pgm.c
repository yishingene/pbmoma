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

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include "matrix.h"
#include "matrix_pgm.h"
#include "spyramid.h"

int DisplayPfilter(PFILTER PF, int idispwin,char *name,int xloc, int yloc){
  MATRIX picture;
  int width, height;
  int i;
  
  height = 100 + (100 * ((PF->num_orientations+3) / 4));
  
  if (PF->num_orientations >= 4) width = 400;
  else if ((PF->num_orientations == 3) || PF->use_highband) width = 300;
  else width = 200;
  
  picture = NewMatrix(height,width);
  MatrixBlitScaledToMatrix(picture,PF->fst_lowband_filter,1,1,98,98);
  MatrixBlitScaledToMatrix(picture,PF->snd_lowband_filter,1,101,98,98);
  if (PF->use_highband){
    MatrixBlitScaledToMatrix(picture,PF->highband_filter,1,201,98,98);
  }
  for (i=0;i<PF->num_orientations;i++){
    MatrixBlitScaledToMatrix(picture,PF->subband_filters[i],
			101 + (100 * (i / 4)), 1 + (100 * (i % 4)), 98, 98);
  }
  DisplayMatrix(picture,idispwin,name,xloc,yloc,0,0);
  DeleteMatrix(picture);
}

int DisplayPyramid(PYRAMID P, int subband, int idispwin, char* name,
		   int xloc,int yloc){
  MATRIX picture;
  MATRIX Orig;
  int width, height;
  int i;
  int column;
  
  if ((subband+1) > P->pfilter->num_orientations){
    fprintf(stderr,"DisplayPyramid: Subband number is out of range ");
    fprintf(stderr,"Defaulting to %d\n",
	    P->pfilter->num_orientations-1);
    subband = P->pfilter->num_orientations-1;
  }
  
  Orig = CollapsePyramid(P);
  
  width = (2 * Orig->columns)+3;
  height = (2 * Orig->rows)+3;
  
  picture = NewMatrix(height,width);
  
  MatrixBlitScaledToMatrix(picture,Orig,1,1,Orig->rows,Orig->columns);
  
  if (P->pfilter->use_highband){
    MatrixBlitScaledToMatrix(picture,P->hiband,1,Orig->columns+2,
			     Orig->rows,Orig->columns);
  }
  
  column = 1;
  for (i=0;i<P->num_levels;i++){
    MatrixBlitScaledToMatrix(picture,P->levels[i]->subband[subband],
			     Orig->rows + 2,column, 
			     P->levels[i]->subband[subband]->rows,
			     P->levels[i]->subband[subband]->columns);
    column += P->levels[i]->subband[subband]->columns;
  }
  MatrixBlitScaledToMatrix(picture,P->lowband,
			   Orig->rows + 2,column, 
			   P->lowband->rows,
			   P->lowband->columns);
  DisplayMatrix(picture,idispwin,name,xloc,yloc,0,0);
  DeleteMatrix(picture);
  DeleteMatrix(Orig);
}
