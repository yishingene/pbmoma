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

/* This is the header file for the matrix routines.
   Please refer to matrix.c for more information */

#ifndef _MATRIX_H
#define _MATRIX_H

#define CONV_NAME_LEN 15	/* The max length of the string denoting
								the type of convolution */

#define MATRIX_LOC(M,r,c) M->values[(r*M->columns)+c]
		/* Quick access to a matrix location */

typedef struct _matrix {
	int rows;
	int columns;
	float * values;
} * MATRIX;


/* Function Prototypes */
MATRIX NewMatrix(int rows, int columns);
void DeleteMatrix(MATRIX M);

int MatrixRows(MATRIX M);
int MatrixCols(MATRIX M);
void MatrixSet(MATRIX M, int r, int c, float val);
float MatrixGet(MATRIX M, int r, int c);
float MatrixGetCirc(MATRIX M, int r, int c);
float MatrixGetRefl(MATRIX M, int r, int c);
void MatrixBlitScaledToMatrix(MATRIX Dest, MATRIX Source, int row, int column,
							int height, int width);

void PrintMatrix(MATRIX M);
MATRIX ReadMatrixFromStream(FILE* Infile);
int WriteMatrixToStream(MATRIX M, FILE* Outfile);
MATRIX LoadMatrix(char* filename);
int SaveMatrix(MATRIX M, char* filename);

MATRIX CopyMatrix(MATRIX A);
MATRIX MatrixAdd(MATRIX A, MATRIX B);
MATRIX MatrixMult(MATRIX A, MATRIX B);
MATRIX ScalarMatrixMult(MATRIX A, float f);
MATRIX SubsampleMatrix(MATRIX A);
MATRIX ExpandMatrix(MATRIX A,int rows, int cols);
MATRIX TransposeMatrix(MATRIX A);
MATRIX Convolve(MATRIX A, MATRIX B);
MATRIX ConvolveRev(MATRIX A, MATRIX B);
MATRIX ApplyFilter(MATRIX A, MATRIX B, char* ConvType);
MATRIX ApplyFilterRev(MATRIX A, MATRIX B, char* ConvType);
MATRIX ApplyFilterAndSubsample(MATRIX A, MATRIX B, char* ConvType);
MATRIX ExpandAndApplyFilter(MATRIX A, MATRIX B, char* ConvType,
							int rows, int cols);

int IMatrixMult(MATRIX Resp, MATRIX A, MATRIX B);
int IMatrixAddAndScalarMult(MATRIX Resp, MATRIX A, MATRIX B, float f);
int IApplyFilterAndSubsample(MATRIX Resp, float *temp, MATRIX A, 
							MATRIX B, char* ConvType);
int IExpandandApplyFilter(MATRIX Resp, float *temp, MATRIX A, 
							MATRIX B, char* ConvType, int rows, int cols);
int IAddMatrixToFirstArg(MATRIX A, MATRIX B);

#endif /* _MATRIX_H */
