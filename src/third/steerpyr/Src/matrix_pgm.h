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

/* This is the header file for matrix routines that convert them to pictures
   or display them as pictures */

#ifndef _MATRIX_PGM_H
#define _MATRIX_PGM_H

#include "matrix.h"

int WriteMatrixAsPGMToStream(MATRIX M, FILE* Outfile);
int SaveMatrixAsPGM(MATRIX M, char* filename);
void DisplayMatrix(MATRIX M, int idispwin, char *name, int xpos, int ypos,
		   float scale, float pedestal);
void UpdateDisplayMatrix(MATRIX M, int idispwin, float scale, float pedestal);

void sigcld_handler();

#endif /* _MATRIX_PGM_H */
