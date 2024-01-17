#include "dimension_t/dimension_t.h"

bool endian=true;

bool isLessEqThan(long int a, long int b) { return a <= b; }
bool isLessThan(long int a, long int b) { return a < b; }
bool isGreatEqThan(long int a, long int b)  { return a >= b; }
bool isGreatThan(long int a, long int b)  { return a > b; }
long int incr(long int i) { return i + 1; }
long int decr(long int i) { return i - 1; }

dimension* init_dim(size_t *t, size_t sz){
  dimension *d = INIT_PERMUTATION_TYPE_SIZE_T(t,sz);
  updateRankDim(d);
  return d;
}
dimension *
create_dim(size_t sz){
  return CREATE_PERMUTATION_TYPE_SIZE_T(sz);
}

void add_dimension(dimension **d, dimension *d0, dimension *d1) {
    (*d) = create_dim(d0->size + d1->size);
    //printf("d size : %ld\n",(*d)->size);
    (*d)->perm = malloc(sizeof(size_t)*((*d)->size));
    for (size_t i = 0; i < d0->size; i++) (*d)->perm[i] = d0->perm[i];
    for (size_t i = 0; i < d1->size; i++) (*d)->perm[d0->size + i] = d1->perm[i];
    updateRankDim(*d);
}

void min_dimension(dimension **d, dimension *d0, dimension *d1) {
    if (d0->size > d1->size) {
        *d = d1;
    }
    else if (d0->size < d1->size) {
        *d = d0;
    }
    else { // d0->size = d1->size
        *d = d0;
        for (size_t i = 0; i < d0->size; i++) {
            if (d0->perm[i] > d1->perm[i]) (*d)->perm[i] = d1->perm[i];
        }
    }
    updateRankDim(*d);
}

void printDebug_dimension(dimension *d,char *msg){

  printf("%s / dim->size = %ld | dim->rank = %ld \n",msg,d->size,d->rank);
  for(size_t i=0; i<d->size; ++i)
    printf("[%ld: %ld] |", i,d->perm[i]);
  printf("\n");
}

void updateRankDim(dimension *dim){
  dim->rank=1;
  for(size_t i=0; i<dim->size; ++i)
    dim->rank *=dim->perm[i];
}

size_t LineFromCoord(size_t *coo, dimension *dim){
    long int begin = 0;
    long int end = dim->size - 1;
    long int (*iter)(long int); iter = &incr;
    bool (*cond)(long int, long int); cond = &isLessEqThan;

    if (endian) {
        begin = dim->size - 1; end = 0;
        iter = &decr; cond = &isGreatEqThan;
    }

    long int pp = 1;
    long int sm = 0;
    for (long int i = begin; cond(i, end); i = iter(i)) {
        sm += (coo[i] * pp);
        pp *= dim->perm[i];
    }
    return sm;

}

void vCoordFromLin(size_t *ret, size_t line, dimension *dim ){
    
    long int begin = 0, end = dim->size - 1;
    long int (*iter)(long int) = incr;
    bool (*cond)(long int, long int) = isLessThan;
    if (endian == false) {
        //if (endian) {
        begin = dim->size - 1; end = 0;
        iter = decr; cond = isGreatThan;
    }
    //prlong intf("to coor begin = %d end = %d \n", begin, end);

    long int sm = line;
    long int pp = dim->rank;
    for (long int i = begin; cond(i, end); i = iter(i)) {
        //prlong intf(" i: %d ", i);
        pp /= dim->perm[i];
        ret[i] = sm / pp;
        sm %= pp;
        //prlong intf("sm[%d] = %d , pp=%d ; ", i, sm, pp);
    }
    ret[end] = sm;
}

size_t* CoordFromLin(size_t line, dimension *dim){
    size_t *ret;
    ret=malloc(dim->size*sizeof(size_t));
    vCoordFromLin(ret,line,dim);
    return ret;
}

