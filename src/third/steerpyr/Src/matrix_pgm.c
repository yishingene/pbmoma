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

int WriteMatrixAsPGMToStream(MATRIX M, FILE* Outfile){
  int r,c;
  float max_val, min_val, new_val;
  int print_col;
  
  if ((Outfile == NULL) || (M == NULL)) return (0);
  
  fprintf(Outfile,"P2\n");
  fprintf(Outfile,"# CREATOR: Simoncelli and Farid Steerable Wedge Filters");
  fprintf(Outfile," by Buccigrossi\n");
  fprintf(Outfile,"%d %d\n",M->columns,M->rows);
  fprintf(Outfile,"255\n");
  
  max_val = M->values[0];
  min_val = M->values[0];
  
  for (r=0;r<M->rows;r++){
    for (c=0;c<M->columns;c++){
      new_val = MATRIX_LOC(M,r,c);
      if (max_val < new_val) max_val = new_val;
      if (min_val > new_val) min_val = new_val;
    }
  }
  
  print_col = 0;
  for (r=0;r<M->rows;r++){
    for (c=0;c<M->columns;c++){
      fprintf(Outfile,"%3d ",(int) 
	      ((MATRIX_LOC(M,r,c) - min_val) / (max_val - min_val) * 255));
      print_col ++;
      if (print_col == 16) {
	print_col = 0;
	fprintf(Outfile,"\n");
      }
    }
  }
  fprintf(Outfile,"\n");
  return 1;
}

int SaveMatrixAsPGM(MATRIX M, char* filename){
  FILE *Outfile;
  int response;
  
  Outfile = fopen(filename,"w");
  if (Outfile == NULL) {
    fprintf(stderr,"SaveMatrixAsPGM(): unable to open file %s\n",filename);
    return 0;
  }
  response = WriteMatrixAsPGMToStream(M, Outfile);
  fclose(Outfile);
  return response;
}

void sigcld_handler() /* So we don't get zombies (I hate zombies) */
{
  int status ;
  
  while (wait3(&status, WNOHANG | WUNTRACED, (struct rusage *)0) >0) ;
}

/* create and display a matrix into an X window.  The scale and pedestal
   should be set so that the values in M are scaled to the range [0,255].
   If (scale == 0) then the scale and pedestal are calculated so that
   the min is mapped to 0 and the max is mapped to 255. */
void DisplayMatrix( MATRIX M, int idispwin, char *name, int xpos, int ypos,
		   float scale, float pedestal ) {
  InitX( idispwin, name, xpos, ypos, M->columns, M->rows );
  UpdateDisplayMatrix(M,idispwin,scale,pedestal);
}

/* display a matrix into an X window that has already been created.  The 
   scale and pedestal should be set so that the values in M are scaled to the 
   range [0,255].  If (scale = 0) then the scale and pedestal are calculated 
   so that the min is mapped to 0 and the max is mapped to 255. */
void UpdateDisplayMatrix( MATRIX M, int idispwin, float scale, 
			 float pedestal ) {
  int r, c;
  int i;
  float max_val, min_val, new_val;
  
  r = M->rows;
  c = M->columns;

  if (scale == 0.0){
    max_val = M->values[0];
    min_val = M->values[0];
    for (i=0;i<r*c;i++){
      new_val = M->values[i];
      if (max_val < new_val) max_val = new_val;
      if (min_val > new_val) min_val = new_val;
    }
    if (max_val != min_val){
      scale = 255.0 / (max_val - min_val);
    } else {
      scale = 0.0;
    }
    pedestal = - scale * min_val;
  }
  DrawImage8( idispwin, M->values, 0, 0, c, r , scale, pedestal);
}
