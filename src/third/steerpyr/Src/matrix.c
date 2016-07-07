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
 * matrix.c:  matrix definition and manipulation routines.
 * 
 * Notes:  
 *    1)  The functions beginning with "I" in the name are designed to be
 *        "fast."  In other words, the destination of the function is
 *        assumed to already be allocated and is passed in as the first
 *        parameter.  It is important to note that no checks will be done
 *        to see if the destination is properly created (e.g. if improper
 *        parameters are given, it can easily cause a segmentation fault.)
 *    2)  The convolution code in convolve.c is unable to handle
 *        convolving a filter with a matrix that is smaller than it.
 *        For that reason, in the convolution functions defined below,
 *        we check for that case.  When the matrix is smaller than
 *        the filter, we execute a different set of convolution functions
 *        that can handle this case (but is much slower).  These slower
 *        convolution functions only do the edge handler "reflect1".
 * ========================================================================
 */
#include <stdio.h>
#include <malloc.h>
#include "matrix.h"

#define MIN(a,b) (a<b)?a:b
#define MAX(a,b) (a>b)?a:b


MATRIX NewMatrix(int rows, int columns){
  MATRIX M;
    
  M = (MATRIX) malloc(sizeof(struct _matrix));
  if (M == NULL) {
    fprintf(stderr,"NewMatrix(): Ran out of alloc space\n");
    return NULL;
  }
  
  M->rows = rows;
  M->columns = columns;
  M->values = (float *) malloc(sizeof(float) * rows * columns);
  if (M->values == NULL) {
    fprintf(stderr,"NewMatrix(): Ran out of alloc space\n");
    return NULL;
  }
  bzero ((char *) M->values, sizeof(float) * rows * columns);
  return M;
}

void DeleteMatrix(MATRIX M){
  if (M == NULL) return;
  free (M->values);
  free (M);
}

int MatrixRows(MATRIX M){
  if (M == NULL) return 0;
  else return M->rows;
}

int MatrixCols(MATRIX M){
  if (M == NULL) return 0;
  else return M->columns;
}

void MatrixSet(MATRIX M, int r, int c, float val){
  if ((M == NULL) || (r < 0) || (c < 0) || (r >= M->rows) || 
      (c >= M->columns)){
    return;
  } else {
    M->values[(r * M->columns) + c] = val;
  }
}

float MatrixGet(MATRIX M, int r, int c){
  if ((M == NULL) || (r < 0) || (c < 0) || (r >= M->rows) || 
      (c >= M->columns)){
    return 0.0;
  } else {
    return MATRIX_LOC(M,r,c);
  }
}

float MatrixGetCirc(MATRIX M, int r, int c){
  if (M == NULL) return 0.0;
  else {
    r = r % M->rows;
    if (r<0) r = r + M->rows;
    c = c % M->columns;
    if (c<0) c = c + M->columns;
    return MATRIX_LOC(M, r, c);
  }
}

/* Does reflection where edge is not repeated */

float MatrixGetRefl(MATRIX M, int r, int c){
  int Flip;
  
  if (M == NULL) return 0.0;
  
  if (r<0 || r>=M->rows){
    if (M->rows == 1) {
      r = 1;
    } else {
      if (r<0) r = -r;
      Flip = (((r / (M->rows-1)) % 2) == 1);
      r = r % (M->rows-1);
      if (Flip) r = (M->rows-1) - r;
    }
  }
  
  if (c<0 || c>=M->columns){
    if (M->columns == 1) {
      c = 1;
    } else {
      if (c<0) c = -c;
      Flip = (((c / (M->columns-1)) % 2) == 1);
      c = c % (M->columns-1);
      if (Flip) c = (M->columns-1) - c;
    }
  }
  
  return MATRIX_LOC(M, r, c);
}

void MatrixBlitScaledToMatrix(MATRIX Dest, MATRIX Source, int row, int column,
			      int height, int width){
  int r,c;
  float max,min,scale,value;
  int nr, nc;
  
  c = Source->rows * Source->columns;
  max = Source->values[0];
  min = Source->values[0];
  for (r=0;r<c;r++){
    if (min > Source->values[r]) min = Source->values[r];
    if (max < Source->values[r]) max = Source->values[r];
  }
  
  scale = 1 / (max - min);
  for (r=0;r<height;r++){
    for (c=0;c<width;c++){
      nr = (r*Source->rows)/height;
      nc = (c * Source->columns) / width;
      value = MATRIX_LOC(Source,nr,nc);
      MATRIX_LOC(Dest,(r+row),(c+column)) = (value - min) * scale;
    }
  }
}

void PrintMatrix(MATRIX M){
  int r,c;
  
  if (M == NULL) {
    printf("NULL\n");
  } else {
    for (r=0;r<M->rows;r++){
      for (c=0;c<M->columns;c++){
	printf("%7.2f ",MATRIX_LOC(M,r,c));
      }
      printf("\n");
    }
  }
}

MATRIX ReadMatrixFromStream(FILE *Infile){
  MATRIX M;
  int rows,columns;
  int r,c;
  float value;
  
  if (Infile == NULL) return(NULL);
  fscanf(Infile," %d %d",&rows,&columns);
  M = NewMatrix(rows,columns);
  if (M == NULL) {
    close (Infile);
    return (NULL);
  }
  for (r=0;r<rows;r++){
    for (c=0;c<columns;c++){
      fscanf(Infile, " %f",&value);
      MatrixSet(M,r,c,value);
    }
  }
  return (M);
}

/* It is assumed that the first character is 'P', also we assume that
   all comments go between P2 and the (column row) specification */

MATRIX ReadMatrixFromPGMStream(FILE *Infile){
  MATRIX M;
  char buf[80];
  int rows,columns;
  int r,c;
  int value;
  
  if (Infile == NULL) return(NULL);
  fgets(buf,sizeof(buf),Infile);
  
  if (buf[1] != '2'){
    fprintf(stdout,"ReadMatrixFromPGMStream():  File not P2 PGM image\n");
    return NULL;
  }

  do {
    fgets(buf,sizeof(buf),Infile);
  } while(buf[0] == '#');
		
  sscanf(buf," %d %d",&columns,&rows);

  fgets(buf,sizeof(buf),Infile);
  if (strncmp(buf,"255",3) != 0){
    fprintf(stdout,"ReadMatrixFromPGMStream():  File not 255 shade PGM image\n");
    return NULL;
  }
		
  M = NewMatrix(rows,columns);
  if (M == NULL) {
    close (Infile);
    return (NULL);
  }
  for (r=0;r<rows;r++){
    for (c=0;c<columns;c++){
      fscanf(Infile, " %d",&value);
      MatrixSet(M,r,c,(float) value);
    }
  }
  return (M);
}

int WriteMatrixToStream(MATRIX M, FILE* Outfile){
  int r,c;

  if ((Outfile == NULL) || (M == NULL)) return (0);

  fprintf(Outfile,"%d %d\n",M->rows,M->columns);
  for (r=0;r<M->rows;r++){
    for (c=0;c<M->columns;c++){
      fprintf(Outfile,"%e ",MATRIX_LOC(M,r,c));
    }
    fprintf(Outfile,"\n");
  }
  fprintf(Outfile,"\n");
  return (1);
}

MATRIX LoadMatrix(char *filename){
  FILE *Infile;
  MATRIX M;
  char c;
  
  Infile = fopen(filename,"r");
  if (Infile == NULL) {
    fprintf(stderr,"LoadMatrix():  Unable to open %s\n",filename);
    return NULL;
  }
  c = getc(Infile);
  ungetc(c,Infile);
  if (c == 'P'){
    M = ReadMatrixFromPGMStream(Infile);
  } else {
    M = ReadMatrixFromStream(Infile);
  }
  fclose(Infile);
  return M;
}

int SaveMatrix(MATRIX M, char* filename){
  FILE *Outfile;
  int response;

  Outfile = fopen(filename,"w");
  if ((Outfile == NULL) || (M == NULL)) return (0);
  response = WriteMatrixToStream(M, Outfile);
  fclose(Outfile);
  return response;
}

MATRIX CopyMatrix(MATRIX A){
  int r,c;
  int size;
  MATRIX C;

  C = (MATRIX) malloc(sizeof(struct _matrix));
  if (C == NULL) {
    fprintf(stderr,"CopyMatrix(): Ran out of alloc space\n");
    return NULL;
  }
  C->rows = A->rows;
  C->columns = A->columns;
  size = sizeof(float) * C->rows * C->columns;
  C->values = (float *) malloc(size);
  if (C->values == NULL) {
    fprintf(stderr,"CopyMatrix(): Ran out of alloc space\n");
    return NULL;
  }
  bcopy((char *) A->values, (char *) C->values, size);
  return (C);
}

MATRIX MatrixAdd(MATRIX A, MATRIX B){
  int r,c;
  int rows,columns;
  MATRIX C;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"MatrixAdd(): Invalid Arguments\n");
    return NULL;
  }

  rows = MIN(A->rows,B->rows);
  columns = MIN(A->columns,B->columns);
  C = NewMatrix(rows,columns);
  if (C == NULL) return NULL;
  
  for (r=0;r<rows;r++){
    for (c=0;c<columns;c++){
      MATRIX_LOC(C,r,c) = 
	MATRIX_LOC(A,r,c) + MATRIX_LOC(B,r,c);
    }
  }
  return (C);
}

MATRIX SubsampleMatrix(MATRIX A){
  int r,c;
  int nr,nc;
  MATRIX C;
  
  if (A == NULL) {
    fprintf(stderr,"SubsampleMatrix(): Invalid Arguments\n");
    return NULL;
  }
  if ((A->rows == 1) || (A->columns == 1)){
    fprintf(stderr,"SubsampleMatrix(): Can't subsample matrix with width or height 1\n");
    return NULL;
  }
  nr = (A->rows / 2) + (A->rows % 2);
  nc = (A->columns / 2) + (A->columns % 2);
  C = NewMatrix(nr,nc);
  for (r=0;r<A->rows;r+=2){
    for (c=0;c<A->columns;c+=2){
      MATRIX_LOC(C,(r/2),(c/2)) = MATRIX_LOC(A,r,c);
    }
  }
  return (C);
}

MATRIX ExpandMatrix(MATRIX A, int nr, int nc){
  int r,c;
  MATRIX C;
  
  if (A == NULL) {
    fprintf(stderr,"ExpandMatrix(): Invalid Arguments\n");
    return NULL;
  } else if (((nr/2) > A->rows) || ((nc/2) > A->columns)){
    fprintf(stderr,"ExpandMatrix(): Destination size too big\n");
    return NULL;
  }
  C = NewMatrix(nr,nc);
  for (r=0;r<nr;r+=2){
    for (c=0;c<nc;c+=2){
      MATRIX_LOC(C,r,c) = MATRIX_LOC(A,(r/2),(c/2));
    }
  }
  return (C);
}

MATRIX MatrixMult(MATRIX A, MATRIX B){
  int r,c,i;
  int rows,columns;
  MATRIX C;
  float sum;
  
  if ((A == NULL) || (B == NULL) || (A->columns != B->rows)){
    fprintf(stderr,"MatrixMult(): Invalid Arguments\n");
    return NULL;
  }
  
  rows = A->rows;
  columns = B->columns;
  C = NewMatrix(rows,columns);
  if (C == NULL) return NULL;
  
  IMatrixMult(C,A,B);
  
  return (C);
}

MATRIX ScalarMatrixMult(MATRIX A, float f){
  MATRIX C;
  int i;
  
  if (A == NULL) {
    fprintf(stderr,"ScalarMult(): Invalid Arguments\n");
    return NULL;
  }
  
  C = NewMatrix(A->rows, A->columns);
  if (C == NULL) return NULL;
  
  for (i= A->rows * A->columns - 1; i >=0; i--){
    C->values[i] = A->values[i] * f;
  }
  return (C);
}

MATRIX TransposeMatrix(MATRIX A){
  MATRIX C;
  int r,c;
  
  if (A == NULL) {
    fprintf(stderr,"TransposeMatrix(): Invalid Arguments\n");
    return NULL;
  }
  
  C = NewMatrix(A->columns, A->rows);
  if (C == NULL) return NULL;
  
  for (r = 0; r < A->rows; r++){
    for (c = 0; c < A->columns; c++){
      MATRIX_LOC(C,c,r) = MATRIX_LOC(A,r,c);
    }
  }
  
  return (C);
}

MATRIX Convolve(MATRIX A, MATRIX B){
  int r,c,i,j;
  int rowshift,colshift;
  MATRIX C;
  float sum;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"Convolve(): Invalid Arguments\n");
    return NULL;
  }
  
  rowshift = B->rows / 2;
  colshift = B->columns / 2;
  C = NewMatrix(A->rows,A->columns);
  if (C == NULL) return NULL;
  
  for (r=0;r<A->rows;r++){
    for (c=0;c<A->columns;c++){
      sum = 0.0;
      for (i=0;i<B->rows;i++){
	for (j=0;j<B->columns;j++){
	  sum += MatrixGetRefl(A,r-rowshift+i,c-colshift+j) *
	    MATRIX_LOC(B,(B->rows-i-1),(B->columns-j-1));
	}
      }
      MATRIX_LOC(C,r,c) = sum;
    }
  }
  return (C);
}

MATRIX ConvolveRev(MATRIX A, MATRIX B){
  int r,c,i,j;
  int rowshift,colshift;
  MATRIX C;
  float sum;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"ConvolveRev(): Invalid Arguments\n");
    return NULL;
  }
  
  rowshift = B->rows / 2;
  colshift = B->columns / 2;
  C = NewMatrix(A->rows,A->columns);
  if (C == NULL) return NULL;
  
  for (r=0;r<A->rows;r++){
    for (c=0;c<A->columns;c++){
      sum = 0.0;
      for (i=0;i<B->rows;i++){
	for (j=0;j<B->columns;j++){
	  sum += MatrixGetRefl(A,r-rowshift+i,c-colshift+j) *
	    MATRIX_LOC(B,i,j);
	}
      }
      MATRIX_LOC(C,r,c) = sum;
    }
  }
  return (C);
}

MATRIX ApplyFilter(MATRIX A, MATRIX B, char *ConvType){
  MATRIX C,Temp;
  
  if ((A == NULL) || (B == NULL)) {
    fprintf(stderr,"ApplyFilter(): Invalid Arguments\n");
    return NULL;
  }
  
  if ((A->rows < B->rows) || (A->columns < B->columns)) {
    if (strcmp(ConvType,"reflect1") != 0){
      fprintf(stderr,"ApplyFilter(): Image smaller ");
      fprintf(stderr,"than filter. Using reflecting convolution\n");
    }
    C = ConvolveRev(A,B);
    return (C);
  }
  
  C = NewMatrix(A->rows,A->columns);
  
  if (C == NULL) return NULL;
  
  if (strcmp(ConvType,"wrap") == 0){
    internal_wrap_filter(	A->values, A->columns, A->rows, 
			 B->values, B->columns, B->rows,
			 0, 1, 0, 1, C->values, 0);
		return (C);
  } else {
    Temp = NewMatrix(B->rows,B->columns);
    internal_filter(	A->values, A->columns, A->rows, 
		    B->values, Temp->values, B->columns, B->rows,
		    0, 1, 0, 1, C->values, ConvType);
    DeleteMatrix(Temp);
    return (C);
  }
}

MATRIX ApplyFilterRev(MATRIX A, MATRIX B, char *ConvType){
  MATRIX C,Temp;
  
  if ((A == NULL) || (B == NULL)) {
    fprintf(stderr,"ApplyFilterRev(): Invalid Arguments\n");
    return NULL;
  }
  
  if ((A->rows < B->rows) || (A->columns < B->columns)) {
    if (strcmp(ConvType,"reflect1") != 0){
      fprintf(stderr,"ApplyFilterRev(): Image smaller ");
      fprintf(stderr,"than filter. Using reflecting convolution\n");
    }
    C = Convolve(A,B);
    return (C);
  }
  
  C = NewMatrix(A->rows,A->columns);
  if (C == NULL) return NULL;
  
  if (strcmp(ConvType,"wrap") == 0){
    internal_wrap_expand(	A->values, A->columns, A->rows, 
			 B->values, B->columns, B->rows,
			 0, 1, 0, 1, C->values, 0);
    return (C);
  } else {
    Temp = NewMatrix(B->rows,B->columns);
    internal_expand(	A->values, A->columns, A->rows, 
		    B->values, Temp->values, B->columns, B->rows,
		    0, 1, 0, 1, C->values, ConvType);
    DeleteMatrix(Temp); 
    return (C);
  }
}

MATRIX ApplyFilterAndSubsample(MATRIX A, MATRIX B, char *ConvType){
  MATRIX C,Temp;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"ApplyFilterAndSubsample(): Invalid Arguments\n");
    return NULL;
  }
  
  if (((A->rows/2 + A->rows%2) < B->rows) ||
      ((A->columns/2 + A->columns%2) < B->columns)) {
    if (strcmp(ConvType,"reflect1") != 0){
      fprintf(stderr,"ApplyFilterAndSubsample(): Resulting image smaller ");
      fprintf(stderr,"than filter. Using reflicting convolution\n");
    }
    Temp = ConvolveRev(A,B);
    C = SubsampleMatrix(Temp);
    DeleteMatrix(Temp);
    return (C);
  }
  
  Temp = NewMatrix(B->rows,B->columns);
  C = NewMatrix(A->rows/2 + A->rows%2,A->columns/2 + A->columns%2);
  
  if (C == NULL){
    fprintf(stderr,"ApplyFilterAndSubsample():  NewMatrix error\n");
    DeleteMatrix(Temp);
    return NULL;
  }
  
  IApplyFilterAndSubsample(C,Temp->values,A,B,ConvType);
  
  DeleteMatrix(Temp);
  
  return(C);
}

MATRIX ExpandAndApplyFilter(MATRIX A, MATRIX B, char *ConvType, 
			    int rows, int cols){
  
  MATRIX C,Temp;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"ExpandAndApplyFilter(): Invalid Arguments\n");
    return NULL;
  }
  
  Temp = NewMatrix(B->rows,B->columns);
  C = NewMatrix(rows,cols);
  
  if (C == NULL){
    fprintf(stderr,"ExpandAndApplyFilter(): NewMatrix error\n");
    DeleteMatrix(Temp);
    return NULL;
  }
  
  IExpandAndApplyFilter(C,Temp->values,A,B,ConvType,rows,cols);
  
  DeleteMatrix(Temp);
  
  return(C);
}

int IMatrixMult(MATRIX Resp, MATRIX A, MATRIX B){
  register int i,j,k;
  register float *r,*a,*b;
  register int off_one;
  
  if ((Resp == NULL) || (A == NULL) || (B == NULL)){
    fprintf(stderr,"IMatrixMult(): Invalid Arguments\n");
    return 0;
  }
  Resp->rows = A->rows;
  Resp->columns = B->columns;
  r = Resp->values;
  for (i = A->rows,off_one=0; i ;off_one += A->columns, i--){
    for (j = 0; j<B->columns ; j++){
      a = A->values + off_one;
      b = B->values + j;
      for (k = A->columns,*r=0.0; k ; k--) {
	*r += *a++ * *b;
	b += B->columns;
      }
      *r++;
    }
  }
  return(0);
}

/* Resp = A + (B * f).  The danger of this routine is that it
   does not make ANY checks on size of the arrays (for efficiency). */

int IMatrixAddAndScalarMult(MATRIX Resp, MATRIX A, MATRIX B, float f){
  register int i;
  register float *r,*a,*b;
  register int total_offset;
  
  if ((Resp == NULL) || (A == NULL) || (B == NULL)){
    fprintf(stderr,"IMatrixAddAndScalarMult(): Invalid Arguments\n");
    return 0;
  }
  r = Resp->values;
  a = A->values;
  b = B->values;
  total_offset = A->rows * A->columns;
  for (i = 0; i < total_offset; i++){
    r[i] = a[i] + (b[i] * f);
  }
  return(1);
}

int IApplyFilterAndSubsample(MATRIX Resp, float *temp, MATRIX A, 
			     MATRIX B, char* ConvType){
  
  if ((Resp == NULL) || (A == NULL) || (B == NULL)){
    fprintf(stderr,"IApplyFilterAndSubsample(): Invalid Arguments\n");
    return 0;
  }
  
  if (strcmp(ConvType,"wrap") == 0){
    internal_wrap_filter(A->values, A->columns, A->rows, 
			 B->values, B->columns, B->rows,
			 0, 2, 0, 2, Resp->values, 0);
    return (1);
  } else {
    internal_filter(A->values, A->columns, A->rows, 
		    B->values, temp, B->columns, B->rows,
		    0, 2, 0, 2, Resp->values, ConvType);
    return (1);
  }
}

int IExpandAndApplyFilter(MATRIX Resp, float *temp, MATRIX A, MATRIX B, 
			  char* ConvType,int rows, int cols){
  
  if ((Resp == NULL) || (A == NULL) || (B == NULL)){
    fprintf(stderr,"IExpandAndApplyFilter(): Invalid Arguments\n");
    return 0;
  }

  if ((A->rows < B->rows) || (A->columns < B->columns)) {
    MATRIX C,Temp;
    if (strcmp(ConvType,"reflect1") != 0){
      fprintf(stderr,"IExpandAndApplyFilter(): Image smaller ");
      fprintf(stderr,"than filter. Using reflecting convolution\n");
    }
    /* First expand A */
    Temp = ExpandMatrix(A,rows,cols);
    /* Calculate C */
    C = ConvolveRev(Temp,B);
    /* Copy C to Response */
    Resp->rows = rows;
    Resp->columns = cols;
    bcopy((char *) C->values, (char *) Resp->values, 
	  sizeof(float) * rows * cols);
    /* Clean up */
    DeleteMatrix(Temp);
    DeleteMatrix(C);
    return (1);
  }
  
  if (strcmp(ConvType,"wrap") == 0){
    internal_wrap_expand(A->values, cols, rows, 
			 B->values, B->columns, B->rows,
			 0, 2, 0, 2, Resp->values, 0);
    return (1);
  } else {
    internal_expand(A->values, cols, rows, 
		    B->values, temp, B->columns, B->rows,
		    0, 2, 0, 2, Resp->values, ConvType);
    return (1);
  }
}

int IAddMatrixToFirstArg(MATRIX A, MATRIX B){
  int size,i;
  float *a, *b;
  
  if ((A == NULL) || (B == NULL)){
    fprintf(stderr,"IAddMatrixToFirstArg(): Invalid Arguments\n");
    return 0;
  }
  size = A->rows * A->columns;
  a = A->values;
  b = B->values;
  for (i=0;i<size;i++,a++,b++){
    *a += *b;
  }
}
