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
 * spyramid.c:  create, manipulate a steerable scalable pyramid.
 *
 * Note:  The functions beginning with "I" in the name are designed to be
 *        "fast."  In other words, the destination of the function is
 *        assumed to already be allocated and is passed in as the first
 *        parameter.  It is important to note that no checks will be done
 *        to see if the destination is properly created (e.g. if improper
 *        parameters are given, it can easily cause a segmentation fault.)
 * ========================================================================
 */

#include <stdio.h>
#include "spyramid.h"
#include "itrp_sin.h"

#define LINE_LEN 80

MATRIX GetHighbandFilter(PFILTER P){
  if (P == NULL){
    fprintf(stderr,"GetHighbandFilter(): Invalid argument\n");
    return NULL;
  } else if (!P->use_highband){
    fprintf(stderr,"GetHighbandFilter(): Highband ");
    fprintf(stderr,"not used in given PFILTER\n");
    return NULL;
  }
  
  return (P->highband_filter);
}

MATRIX GetFirstLowbandFilter(PFILTER P){
  if (P == NULL){
    fprintf(stderr,"GetFirstLowbandFilter(): Invalid argument\n");
    return NULL;
  }
  
  return (P->fst_lowband_filter);
}

MATRIX GetSecondLowbandFilter(PFILTER P){
  if (P == NULL){
    fprintf(stderr,"GetSecondLowbandFilter(): Invalid argument\n");
    return NULL;
  }
  
  return (P->snd_lowband_filter);
}

MATRIX GetSubbandFilter(PFILTER P, int orientation){
  if (P == NULL){
    fprintf(stderr,"GetSubbandFilter(): Invalid argument\n");
    return NULL;
  } else if ((P->num_orientations <= orientation) || (orientation < 0)){
    fprintf(stderr,"GetSubbandFilter(): Orientation out of range\n");
    return NULL;
  }
  
  return (P->subband_filters[orientation]);
}


/* This routine reads the next line of the infile, removes comments,
   and returns a tag, value pair that is read (separated by '=' and
   possibly spaces). */

int GetTagValueFromStream(FILE *infile, char *tag,char *value){
  char buf[LINE_LEN];
  int i,j;
  
  while (fgets(buf,sizeof(buf),infile) != NULL){
    if ((strlen(buf) <= 2) || (buf[0] == '#') || (buf[0] == '%')){
      continue;
    }
    strcpy(tag,"");
    strcpy(value,"");
    
    /* Scan the tag in */
    for (i=0,j=0; (buf[i]!=' ') && (buf[i]!='=') && (buf[i]!='\n') ;){
      tag[j++] = buf[i++];
    }
    tag[j] = '\0';
    
    /* Scan equals and whitespace */
    for (;(buf[i]==' ') || (buf[i]=='=');i++);
    
    /* Scan the value (if there ) */
    for (j=0; (buf[i]!=' ') && (buf[i]!='=') && (buf[i]!='\n') ;){
      value[j++] = buf[i++];
    }
    value[j] = '\0';
    
    return (1);
  }
  return (0);
}

char* upcase(char* astring){
  int i;
  
  for (i=0;i<strlen(astring);i++){
    astring[i] = toupper(astring[i]);
  }
  return astring;
}

char* downcase(char* astring){
  int i;
  
  for (i=0;i<strlen(astring);i++){
    astring[i] = tolower(astring[i]);
  }
  return astring;
}

/* This loads a pyramid filter specification from a file (which must be
   in a specific format), into a PFILTER data structure */
PFILTER LoadPFilter(char *filename){
  FILE *Infile;
  PFILTER P;
  char tag[LINE_LEN];
  char value[LINE_LEN];
  int i;
  
  Infile = fopen(filename,"r");
  if (Infile == NULL) {
    fprintf(stderr,"LoadPFilter(): Unable to open %s\n",filename);
    return NULL;
  }
  
  P = (PFILTER) malloc(sizeof(struct _pfilter));
  P->num_orientations = 0;
  P->subband_filters = NULL;
  P->fst_lowband_filter = NULL;
  P->snd_lowband_filter = NULL;
  P->use_highband = 0;
  P->highband_filter = NULL;
  P->num_harmonics = 0;
  P->harmonics = NULL;
  P->interp = NULL;
  /* Set the default convolution type to "wrap" */
  strcpy(P->fwd_conv_type,"wrap");
  strcpy(P->inv_conv_type,"wrap");
  
  while (GetTagValueFromStream(Infile,tag,value)){
    upcase(tag);
    upcase(value);
    if (strncmp(tag,"NUMBEROFORIENTATIONS",20) == 0){
      P->num_orientations = atoi(value);
      P->subband_filters = (MATRIX *) malloc(sizeof(MATRIX) * 
					     P->num_orientations);
    } else if (strncmp(tag,"USEHIGHBAND",11) == 0){
      P->use_highband = (value[0] == 'Y');
    } else if (strncmp(tag,"NUMBEROFHARMONICS",17) == 0){
      P->num_harmonics = atoi(value);
      P->harmonics = (int *) malloc(sizeof(int) * P->num_harmonics);
    } else if (strncmp(tag,"HARMONICSLIST",13) == 0){
      if (P->harmonics == NULL){
	fprintf(stderr,"%s: Please specify number of harmonics before giving the harmonics list\n",filename);
	exit(-1);
      }
      for (i=0;i<P->num_harmonics;i++){
	fscanf(Infile," %d",&(P->harmonics[i]));
      }
    } else if (strncmp(tag,"FSTLOWBANDFILTER",13) == 0){
      P->fst_lowband_filter = ReadMatrixFromStream(Infile);
    } else if (strncmp(tag,"SNDLOWBANDFILTER",13) == 0){
      P->snd_lowband_filter = ReadMatrixFromStream(Infile);
    } else if (strncmp(tag,"INTERPOLATIONMATRIX",19) == 0){
      P->interp = ReadMatrixFromStream(Infile);
    } else if (strncmp(tag,"HIGHBANDFILTER",14) == 0){
      P->highband_filter = ReadMatrixFromStream(Infile);
    } else if (strncmp(tag,"SUBBANDFILTERS",14) == 0){
      if (P->subband_filters == NULL){
	fprintf(stderr,"%s: Please specify number of orientations before giving the subband list\n",filename);
	exit(-1);
      }
      for (i=0;i<P->num_orientations; i++){
	P->subband_filters[i] = ReadMatrixFromStream(Infile);
      }
    } else if (strncmp(tag,"FORWARDCONVOLUTIONTYPE") == 0){
      strcpy(P->fwd_conv_type,downcase(value));
    } else if (strncmp(tag,"INVERSECONVOLUTIONTYPE") == 0){
      strcpy(P->inv_conv_type,downcase(value));
    }
  }
  
  if (P->subband_filters == NULL){
    fprintf(stderr,"%s: Please list the subband filters with the heading 'SubbandFilters'.\n",filename);
    exit(-1);
  } else if (P->fst_lowband_filter == NULL){
    fprintf(stderr,"%s: Please specify the first lowband filter with the heading 'FstLowbandFilter'\n",filename);
    exit(-1);
  } else if (P->fst_lowband_filter == NULL){
    fprintf(stderr,"%s: Please specify the second lowband filter with the heading 'SndLowbandFilter'\n",filename);
    exit(-1);
  } else if (P->use_highband && (P->highband_filter == NULL)){
    fprintf(stderr,"%s: If UseHighband is 'Yes' then please specify a highband filter\n",filename);
    exit(-1);
  } else if (P->interp == NULL){
    fprintf(stderr,"%s: Please specify an interpolation matrix with the tag 'InterplationMatrix'\n");
    exit(-1);
  }
  
  fclose(Infile);
  return (P);
}

/* Write a filter into the proper format for LoadPFilter to read in */
int SavePFilter(PFILTER P, char *filename){
  FILE *Outfile;
  int i;
  
  if (P == NULL) return 0;
  
  Outfile = fopen(filename,"w");
  if (Outfile == NULL) return 0;
  
  fprintf(Outfile,"NumberOfOrientations = %d\n", P->num_orientations);
  
  if (P->use_highband) {
    fprintf(Outfile,"UseHighband = YES\n",P->use_highband);
  } else {
    fprintf(Outfile,"UseHighband = NO\n",P->use_highband);
  }
  
  fprintf(Outfile,"ForwardConvolutionType = %s\n",P->fwd_conv_type);
  fprintf(Outfile,"InverseConvolutionType = %s\n",P->inv_conv_type);
  
  fprintf(Outfile,"NumberOfHarmonics = %d\n",P->num_harmonics);
  fprintf(Outfile,"HarmonicsList\n");
  for (i=0;i<P->num_harmonics;i++){
    fprintf(Outfile,"%d ",P->harmonics[i]);
  }
  fprintf(Outfile,"\n\n");
  
  fprintf(Outfile,"FstLowbandFilter\n");
  WriteMatrixToStream(P->fst_lowband_filter,Outfile);
  
  fprintf(Outfile,"SndLowbandFilter\n");
  WriteMatrixToStream(P->snd_lowband_filter,Outfile);
  
  fprintf(Outfile,"InterpolationMatrix\n");
  WriteMatrixToStream(P->interp,Outfile);
  
  if (P->use_highband){
    fprintf(Outfile,"HighbandFilter\n");
    WriteMatrixToStream(P->highband_filter,Outfile);
  }
  
  fprintf(Outfile,"SubbandFilters\n");
  for (i=0;i< P->num_orientations; i++){
    WriteMatrixToStream(P->subband_filters[i],Outfile);
  }
  
  fclose(Outfile);
  return 1;
}

MATRIX GetHighbandImage(PYRAMID PY){
  if (PY == NULL){
    fprintf(stderr,"GetHighbandImage(): Invalid argument\n");
    return NULL;
  }
  
  return (PY->hiband);
}

MATRIX GetLowbandImage(PYRAMID PY){
  if (PY == NULL){
    fprintf(stderr,"GetLowbandImage(): Invalid argument\n");
    return NULL;
  }
  
  return (PY->lowband);
}

MATRIX GetSubbandImage(PYRAMID PY, int level, int orientation){
  if (PY == NULL){
    fprintf(stderr,"GetSubbandImage(): Invalid argument\n");
    return NULL;
  } else if ((PY->num_levels <= level) 
	     || (level < 0)){
    fprintf(stderr,"GetSubbandImage(): Level out of range\n");
    return NULL;
  } else if ((PY->pfilter->num_orientations <= orientation) 
	     || (orientation < 0)){
    fprintf(stderr,"GetSubbandImage(): Orientation out of range\n");
    return NULL;
  }
  
  return (PY->levels[level]->subband[orientation]);
}

/* Given and image (M), filter (PF), and number of levels (levels), return
 * a steerable scalable pyramid. */
PYRAMID CreatePyramid(MATRIX M, PFILTER PF, int levels){
  PYRAMID PY;
  int i,j;
  MATRIX NewLowband;
  
  if ((M == NULL) || (PF == NULL)){
    fprintf(stderr,"CreatePyramid():  Invalid Arguments\n");
    return NULL;
  }
  
  PY = (PYRAMID) malloc(sizeof(struct _pyramid));
  PY->pfilter = PF;
  PY->num_levels = levels;
  PY->levels = (PBAND *) malloc(sizeof(PBAND) * levels);
  
  /* Now we apply the highpass filter and the first lowpass filter
     in order to prepare for the recursive part of the pyramid */
  if (PF->use_highband) 
    PY->hiband = ApplyFilter(M,PF->highband_filter,PF->fwd_conv_type);
  PY->lowband = ApplyFilter(M,PF->fst_lowband_filter,PF->fwd_conv_type);
  
  for(i=0;i<levels;i++){
    /* First create the various subbands */
    PY->levels[i] = (PBAND) malloc(sizeof(struct _pband));
    PY->levels[i]->subband = (MATRIX *) malloc(sizeof(MATRIX) *
					       PF->num_orientations);
    for (j=0;j<PF->num_orientations;j++){
      PY->levels[i]->subband[j] = ApplyFilter(PY->lowband, 
					      PF->subband_filters[j], PF->fwd_conv_type);
    }
    
    /* Now create the lowband image which becomes the image for our
       next pass */	
    NewLowband = ApplyFilterAndSubsample(PY->lowband, 
					 PF->snd_lowband_filter, PF->fwd_conv_type);
    DeleteMatrix(PY->lowband);
    PY->lowband = NewLowband;
  }
  return(PY);
}

/* Takes a pyramid, collapses it and returns the image */
MATRIX CollapsePyramid(PYRAMID PY){
  int i,j;
  PFILTER PF;
  MATRIX Lowband,NewLowband,Subband,Highband;
  MATRIX Result;
  
  
  if (PY == NULL){
    fprintf(stderr,"CollapsePyramid():  Invalid Arguments\n");
    return NULL;
  }
  
  PF = PY->pfilter;
  
  /* First collapse the various subbands */
  Lowband = PY->lowband;
  for(i=PY->num_levels - 1;i>=0;i--){
    NewLowband = ExpandAndApplyFilter(Lowband,
				      PF->snd_lowband_filter, PF->inv_conv_type,
				      PY->levels[i]->subband[0]->rows,
				      PY->levels[i]->subband[0]->columns);
    for (j=0;j<PF->num_orientations;j++){
      Subband = ApplyFilterRev(PY->levels[i]->subband[j],
			       PF->subband_filters[j], PF->inv_conv_type);
      IAddMatrixToFirstArg(NewLowband,Subband);
      DeleteMatrix(Subband);
    }
    if (Lowband != PY->lowband) {
      DeleteMatrix(Lowband);
    }
    Lowband = NewLowband;
  }
  
  Result = ApplyFilterRev(Lowband,PF->fst_lowband_filter,PF->inv_conv_type);
  if (Lowband != PY->lowband){
    DeleteMatrix(Lowband);
  }
  
  if (PF->use_highband){
    Highband = ApplyFilterRev(PY->hiband, PF->highband_filter,
			      PF->inv_conv_type);
    IAddMatrixToFirstArg(Result,Highband);
    DeleteMatrix(Highband);
  }
  return (Result);
}

/* Takes a pyramid (PY), level and returns the same level steered to "angle".
 * The entire image is steered to the same angle. */
MATRIX SteerPyramid(PYRAMID PY, int level, float angle){
  MATRIX K,B,C;
  
  if ((PY == NULL) || (level >= PY->num_levels)) {
    fprintf(stderr,"SteerPyramid(): invalid arguments\n");
    return NULL;
  }
  
  if (PY->pfilter->harmonics[0] == 0){
    K = NewMatrix(1, PY->pfilter->num_harmonics * 2 - 1);
  } else {
    K = NewMatrix(1, PY->pfilter->num_harmonics * 2);
  }
  B = NewMatrix(1, PY->pfilter->num_orientations);
  C = NewMatrix(PY->levels[level]->subband[0]->rows,
		PY->levels[level]->subband[0]->columns);
  if (C == NULL) return NULL;
  
  ISteerPyramid(C,K,B,PY,level,angle);
  
  return (C);
}


/* Takes a pyramid (PY), level and returns the same level steered to "angle".
 * Here, each point in the image is steered to a, possibly different, angle
 * as specified by the matrix "angles". */
MATRIX SteerPyramidPointwise(PYRAMID PY, int level, MATRIX angles){
  MATRIX K,B,C;
  
  if ((PY == NULL) || (level >= PY->num_levels) || 
      (angles == NULL)) {
    fprintf(stderr,"SteerPyramidPointwise(): invalid arguments\n");
    return NULL;
  }
  
  if (PY->pfilter->harmonics[0] == 0){
    K = NewMatrix(1, PY->pfilter->num_harmonics * 2);
  } else {
    K = NewMatrix(1, PY->pfilter->num_harmonics * 2 - 1);
  }
  B = NewMatrix(1, PY->pfilter->num_orientations);
  C = NewMatrix(PY->levels[level]->subband[0]->rows,
		PY->levels[level]->subband[0]->columns);
  if (C == NULL) return NULL;
  
  ISteerPyramidPointwise(C,K,B,PY,level,angles);
  
  return (C);
}

/* We assume K is zero'ed */
int ICreateK(MATRIX K, int* harmonics, int harm_num, float angle){
  int i,j;
  
  i=0;
  j=0;
  if (harmonics[0] == 0) { 
    K->values[0] = 1;
    i++; 
    j++;
  }
  for (;i<harm_num;i++){
    K->values[j++] = itrp_cos(angle * (float) harmonics[i]);
    K->values[j++] = itrp_sin(angle * (float) harmonics[i]);
  }
}

/* We assume M and K is zero'ed */
void ISteerPyramid(MATRIX M, MATRIX K, MATRIX B, PYRAMID PY, int level, 
		   float angle){
  int i;
  
  ICreateK(K, PY->pfilter->harmonics, PY->pfilter->num_harmonics, angle);
  IMatrixMult(B,K,PY->pfilter->interp);
  for (i=0;i<PY->pfilter->num_orientations;i++){
    IMatrixAddAndScalarMult(M, M, PY->levels[level]->subband[i], 
			    B->values[i]);
  }
}

/* Assumes M and K is zero'ed */
void ISteerPyramidPointwise(MATRIX M, MATRIX K, MATRIX B, PYRAMID PY, 
			    int level, MATRIX angles){
  int i,j;
  int size;
  
  size = PY->levels[level]->subband[0]->rows * 
    PY->levels[level]->subband[0]->columns;
  for (i=0;i<size;i++){ /* Loop through every element in the aray */
    /* We don't need to re-zero K since we will always have the same
       harmonics */
    ICreateK(K, PY->pfilter->harmonics, 
	     PY->pfilter->num_harmonics, angles->values[i]);
    IMatrixMult(B,K,PY->pfilter->interp);
    
    for (j=0;j<PY->pfilter->num_orientations;j++){
      M->values[i] += PY->levels[level]->subband[i]->values[i] *
	B->values[i];
    }
    
  }
}
