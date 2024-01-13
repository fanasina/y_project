#ifndef __DIMENSION_T__H__
#define __DIMENSION_T__H__

#include "permutation_t/permutation_t.h"

extern bool endian;

typedef struct PERMUTATION_TYPE_SIZE_T dimension ;

dimension * create_dim(size_t size);

void updateRankDim(dimension *dim);
size_t LineFromCoord(size_t *coo, dimension dim);
size_t* CoordFromLin(size_t line, dimension dim);



#endif /* __DIMENSION_T__H__ */
//int compare_dimension(dimension *d1, dimension *d2);
