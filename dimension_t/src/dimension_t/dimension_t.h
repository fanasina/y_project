#ifndef __DIMENSION_T__H__
#define __DIMENSION_T__H__

#include "permutation_t/permutation_t.h"

extern bool endian;

bool isLessEqThan(long int a, long int b) ;
bool isLessThan(long int a, long int b) ;
bool isGreatEqThan(long int a, long int b)  ;
bool isGreatThan(long int a, long int b)  ;
long int incr(long int i) ;
long int decr(long int i) ;


typedef struct PERMUTATION_TYPE_SIZE_T dimension ;

dimension * create_dim(size_t size);
dimension * create_reverse_dim(size_t size);
dimension* init_dim(size_t *t, size_t sz);
dimension* init_copy_dim(size_t *t, size_t sz);
dimension* clone_dim(dimension *dim);
void free_dimension(dimension *d);

bool is_equal_dim(dimension *d0, dimension *d1);

dimension* sub_minus_dim_head(dimension *t, size_t minusSubdim);
dimension* sub_minus_dim_tail(dimension *t, size_t minusSubdim);
dimension* sub_dim_head(dimension *t, size_t subdim);
dimension* sub_dim_tail(dimension *t, size_t subdim);

dimension* sub_copy_minus_dim_head(dimension *t, size_t minusSubdim);
dimension* sub_copy_minus_dim_tail(dimension *t, size_t minusSubdim);
dimension* sub_copy_dim_head(dimension *t, size_t sub_copydim);
dimension* sub_copy_dim_tail(dimension *t, size_t sub_copydim);

void split_dim_part(dimension *root, dimension **part_1, dimension **part_2, size_t pivotSplit, size_t rangeInPivot );

void add_copy_dimension(dimension **d, dimension *d0, dimension *d1);
void min_copy_dimension(dimension **d, dimension *d0, dimension *d1);

void add_dimension(dimension **d, dimension *d0, dimension *d1);
void min_dimension(dimension **d, dimension *d0, dimension *d1);

void printDebug_dimension(dimension *d, char *msg);
size_t sprint_dimension(char **dimContent, dimension *d);

void updateRankDim(dimension *dim);

size_t LineFromCoord(size_t *coo, dimension *dim);
size_t* CoordFromLin(size_t line, dimension *dim);
void vCoordFromLin(size_t *ret, size_t line, dimension *dim );

long int signedLineFromCoord(long int *coo, dimension *dim);
long int* signedCoordFromLin(long int line, dimension *dim);
void signedvCoordFromLin(long int *ret, long int line, dimension *dim );


void increment_dim_var(dimension *d);
void decrement_dim_var(dimension *d);

struct list_perm_in_dim{
  size_t index;
  size_t perm;
  struct list_perm_in_dim *next;
};

typedef struct list_perm_in_dim list_perm_in_dim;

void append_in_list_perm(list_perm_in_dim **list_p, size_t perm);
dimension * create_dim_from_list_perm( list_perm_in_dim *l_p);

dimension * create_binary_dim(size_t dimension_size);

void free_list_perm_in_dim(list_perm_in_dim *l_p);

#endif /* __DIMENSION_T__H__ */
//int compare_dimension(dimension *d1, dimension *d2);
