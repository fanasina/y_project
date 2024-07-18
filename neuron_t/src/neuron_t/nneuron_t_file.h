#ifndef NNEURONE_T_FILE_H__C_
#define NNEURONE_T_FILE_H__C_

#include "neuron_t/neuron_t.h"
#include "tensor_t/tensor_t.h"

//#define GEN_TYPE_FILE_NN(type)\
//void export_to_file_weight_in_nneurons_##type(char *fileName, neurons_##type *src);

#define EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(type,nneurons ,attribute, file_name) \
do{\
  FILE *fileWrite = fopen(file_name, "w");\
  if(fileWrite == NULL) {\
    printf("error while opening %s\n",file_name);\
    exit(1);\
  }\
\
  char *val=NULL;\
  long int begin , end /*, beginIter, endIter*/ ;\
  long int (*iter)(long int) ;\
  bool (*cond)(long int, long int) ; \
\
  neurons_##type * tmpNN = nneurons;\
  tensor_##type * T = NULL;\
  size_t * coord = NULL;\
  while(tmpNN){\
    T = tmpNN->attribute;\
    if(T){\
      coord = malloc(sizeof(long int)*(T->dim)->size); \
      if (endian ) {\
            begin = (T->dim->size) - 1; end = 0;\
            iter = decr; cond = isGreatEqThan; \
            /*fprintf(fileWrite,"endian(=true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index \n");*/\
      }else{\
            begin = 0 ; end = (T->dim->size) - 1; \
            iter = incr; cond = isLessEqThan; \
            /*fprintf(fileWrite,"endian(=false): the lowest index varies first, e.g:  [x0,x1,x2,...,xn] x0 is the lowest index \n");*/\
      }\
      fprintf(fileWrite,"[");\
      for(size_t i=0; i<(T->dim)->size; ++i)\
        fprintf(fileWrite," %ld,", (T->dim)->perm[i]);\
      fprintf(fileWrite,"] \n");\
    \
      for(long int i=0;i<(T->dim)->rank;++i){\
        vCoordFromLin(coord,i,T->dim);\
        if(coord[begin]==0){\
          for(long int j=begin; cond(j,end); j= iter(j) ){\
            if(coord[j]==0) fprintf(fileWrite,"(");\
            else break;\
          }\
        }\
        /*fprintf(fileWrite," [");\
        for(size_t k=0; k<(T->dim)->size;++k) fprintf(fileWrite," %ld,",coord[k]);\
        */val=type##_TO_STR(T->x[i]);\
        fprintf(fileWrite," %s, ",val);\
        free(val); val=NULL;\
        if(coord[begin]==(T->dim)->perm[begin]-1){\
          size_t count=0;\
          for(long int j=begin; cond(j,end); j = iter(j)){\
            if(coord[j]==(T->dim)->perm[j]-1) {\
              fprintf(fileWrite,")"); ++count;\
            }\
            else break;\
          }\
          if(count == (T->dim)->size-1) fprintf(fileWrite,"\n ");\
        }\
      }\
      \
      free(coord);\
      fprintf(fileWrite,"\n");\
      }\
      tmpNN = tmpNN->next_layer;\
   }\
  fprintf(fileWrite,"\n");\
  fclose(fileWrite);\
\
}while(0);


#define IMPORT_FROM_FILE_TO_TENSOR_ATTRIBUTE_IN_NNEURONS(type,nneurons ,attribute, file_name) \
do{\
  FILE *fileWrite = fopen(file_name, "r");\
  if(fileWrite == NULL) {\
    printf("error while opening %s\n",file_name);\
    exit(1);\
  }\
\
  char *val=NULL;\
  long int begin , end /*, beginIter, endIter*/ ;\
  long int (*iter)(long int) ;\
  bool (*cond)(long int, long int) ; \
\
  neurons_##type * tmpNN = nneurons;\
  tensor_##type * T = NULL;\
  size_t * coord = NULL;\
  while(tmpNN){\
    T = tmpNN->attribute;\
    if(T){\
      coord = malloc(sizeof(long int)*(T->dim)->size); \
      if (endian ) {\
            begin = (T->dim->size) - 1; end = 0;\
            iter = decr; cond = isGreatEqThan; \
            /*fprintf(fileWrite,"endian(=true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index \n");*/\
      }else{\
            begin = 0 ; end = (T->dim->size) - 1; \
            iter = incr; cond = isLessEqThan; \
            /*fprintf(fileWrite,"endian(=false): the lowest index varies first, e.g:  [x0,x1,x2,...,xn] x0 is the lowest index \n");*/\
      }\
      fprintf(fileWrite,"[");\
      for(size_t i=0; i<(T->dim)->size; ++i)\
        fprintf(fileWrite," %ld,", (T->dim)->perm[i]);\
      fprintf(fileWrite,"] \n");\
    \
      for(long int i=0;i<(T->dim)->rank;++i){\
        vCoordFromLin(coord,i,T->dim);\
        if(coord[begin]==0){\
          for(long int j=begin; cond(j,end); j= iter(j) ){\
            if(coord[j]==0) fprintf(fileWrite,"(");\
            else break;\
          }\
        }\
        /*fprintf(fileWrite," [");\
        for(size_t k=0; k<(T->dim)->size;++k) fprintf(fileWrite," %ld,",coord[k]);\
        */val=type##_TO_STR(T->x[i]);\
        fprintf(fileWrite," %s, ",val);\
        free(val); val=NULL;\
        if(coord[begin]==(T->dim)->perm[begin]-1){\
          size_t count=0;\
          for(long int j=begin; cond(j,end); j = iter(j)){\
            if(coord[j]==(T->dim)->perm[j]-1) {\
              fprintf(fileWrite,")"); ++count;\
            }\
            else break;\
          }\
          if(count == (T->dim)->size-1) fprintf(fileWrite,"\n ");\
        }\
      }\
      \
      free(coord);\
      fprintf(fileWrite,"\n");\
      }\
      tmpNN = tmpNN->next_layer;\
   }\
  fprintf(fileWrite,"\n");\
  fclose(fileWrite);\
\
}while(0);

#define EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(type, neuronDst, attribute, file_name_input) \
do{\
  FILE *f_input;\
  f_input=fopen(file_name_input,"r");\
  if ( f_input == NULL ) {\
    fprintf( stderr, "Cannot open file: %s for reading\n",file_name_input );\
    exit( -1 );\
  }\
  size_t block_size=2;\
  size_t block_count=4;\
  char *input=malloc(block_size*block_count + 1);\
  char *iinput=malloc(block_size*block_count + 256);\
  bool size_unknown=false, broken=false; \
  bool Done=false;\
  int retfread = 0, curIn=0;\
\
  list_perm_in_dim *l_p=NULL;\
  dimension *dim=NULL;\
  size_t ss;\
  char *ttmp;\
  char *ppEnd="[";\
  bool bracketsDown=false, tensorNotMatched = false;\
  size_t j=0;\
  neurons_##type * tmpNN = neuronDst;\
  tensor_##type * T;\
  while(tmpNN){\
    bracketsDown = false;\
    Done = false;\
    T = tmpNN->attribute;\
    if(T == NULL){\
      Done = true;\
    }\
    j=0;\
    while(!Done && !tensorNotMatched){\
      retfread = fread(input, block_size, block_count, f_input) ;\
      Done = (retfread != block_count);\
      for(curIn=0; curIn<retfread*block_size; ++curIn) iinput[curIn]=input[curIn];\
      while(!Done && (((iinput[curIn-1] >='0') && (iinput[curIn-1] <='9'))||(iinput[curIn-1] =='.')||(iinput[curIn-1] =='E')||(iinput[curIn-1] =='e'))){\
        retfread = fread(input, 1, 1, f_input) ;\
        Done = (retfread != 1);\
        iinput[curIn++] = *input;\
      }\
      iinput[curIn]='\0';\
      ttmp=iinput;\
      \
      ppEnd=ttmp;\
      if( !bracketsDown){\
        while(*ttmp!='\0' && *ppEnd!=']' ){\
          ss = strtoul(ttmp, &ppEnd, 10);\
          while(ttmp == ppEnd && *ttmp!='\0'  && ppEnd[0] !=']'){\
            ttmp++;\
            ss = strtoul(ttmp, &ppEnd, 10);\
          }\
          if(ppEnd !=ttmp ){\
            append_in_list_perm(&l_p,ss);\
          }\
          ttmp=ppEnd;\
        }\
        if( *ttmp ==']'){\
          dim=create_dim_from_list_perm(l_p);\
          bracketsDown = true;\
          /*ttmp++; ppEnd++;*/\
        }\
      \
      }\
      if(bracketsDown){\
 \
        if(T->dim->rank == dim->rank){\
          \
          \
        \
          type x;\
          while(strlen(ttmp) && j<dim->rank){ \
            x = strto_##type(ttmp, &ppEnd);\
            while(ttmp == ppEnd && strlen(ttmp)){\
              ttmp++;\
              x = strto_##type(ttmp, &ppEnd);\
            }\
            if(ttmp != ppEnd){\
              T->x[j++]=x;\
            }\
            ttmp=ppEnd;\
          }\
          if(j == dim->rank ){\
            Done = true;\
          }\
        }else {\
          tensorNotMatched = true;\
          Done = true;\
          break;\
        }\
      }\
        if(Done){\
          free_dimension(dim);\
          free_list_perm_in_dim(l_p);\
          l_p=NULL;\
        }\
      if(tensorNotMatched) break;\
  \
    }\
     tmpNN = tmpNN->next_layer;\
  }\
  free(input);\
  free(iinput);\
  fclose(f_input);\
\
}while(0);


#endif /* NNEURONE_T_FILE_H__C_ */
