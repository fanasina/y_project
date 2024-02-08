#ifndef __DIMENSION_T__H__
#define __DIMENSION_T__H__

#include "permutation_t/permutation_t.h"

extern bool endian;

typedef struct PERMUTATION_TYPE_SIZE_T dimension ;

dimension * create_dim(size_t size);
dimension* init_dim(size_t *t, size_t sz);
dimension* init_copy_dim(size_t *t, size_t sz);
void free_dimension(dimension *d);

dimension* sub_minus_dim_head(dimension *t, size_t minusSubdim);
dimension* sub_minus_dim_tail(dimension *t, size_t minusSubdim);
dimension* sub_dim_head(dimension *t, size_t subdim);
dimension* sub_dim_tail(dimension *t, size_t subdim);

dimension* sub_copy_minus_dim_head(dimension *t, size_t minusSubdim);
dimension* sub_copy_minus_dim_tail(dimension *t, size_t minusSubdim);
dimension* sub_copy_dim_head(dimension *t, size_t sub_copydim);
dimension* sub_copy_dim_tail(dimension *t, size_t sub_copydim);

void add_copy_dimension(dimension **d, dimension *d0, dimension *d1);
void min_copy_dimension(dimension **d, dimension *d0, dimension *d1);

void add_dimension(dimension **d, dimension *d0, dimension *d1);
void min_dimension(dimension **d, dimension *d0, dimension *d1);

void printDebug_dimension(dimension *d, char *msg);

void updateRankDim(dimension *dim);
size_t LineFromCoord(size_t *coo, dimension *dim);
size_t* CoordFromLin(size_t line, dimension *dim);
void vCoordFromLin(size_t *ret, size_t line, dimension *dim );


#endif /* __DIMENSION_T__H__ */
//int compare_dimension(dimension *d1, dimension *d2);
