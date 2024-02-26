#include "dimension_t/dimension_t.h"

#define min(x,y) (((x)<(y))?(x):(y)) 

bool endian=true;

bool isLessEqThan(long int a, long int b) { return a <= b; }
bool isLessThan(long int a, long int b) { return a < b; }
bool isGreatEqThan(long int a, long int b)  { return a >= b; }
bool isGreatThan(long int a, long int b)  { return a > b; }
long int incr(long int i) { return i + 1; }
long int decr(long int i) { return i - 1; }

dimension* init_dim(size_t *t, size_t sz){
  dimension *d = malloc(sizeof(dimension));
  d->size=sz;
  d->perm=t;
  updateRankDim(d);
  return d;
}

dimension* init_copy_dim(size_t *t, size_t sz){
  dimension *d = INIT_COPY_PERMUTATION_TYPE_SIZE_T(t,sz);
  updateRankDim(d);
  return d;
}
dimension *
create_dim(size_t sz){
  return CREATE_PERMUTATION_TYPE_SIZE_T(sz);
}
dimension *
create_reverse_dim(size_t sz){
  dimension *dim = CREATE_PERMUTATION_TYPE_SIZE_T(sz);
  for(size_t i=0;i<sz;++i) dim->perm[i]=sz-1-i;
  updateRankDim(dim);
  return dim;
}

void free_dimension(dimension *d){
  if(d) free_permut_TYPE_SIZE_T(d);
}

dimension* sub_copy_minus_dim_head(dimension *root, size_t minusSubdim){
  if(minusSubdim < (root->size)){
    dimension *d = INIT_COPY_PERMUTATION_TYPE_SIZE_T(root->perm, (root->size)-minusSubdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}

dimension* sub_copy_minus_dim_tail(dimension *root, size_t minusSubdim){
  if(minusSubdim < (root->size)){
    dimension *d = INIT_COPY_PERMUTATION_TYPE_SIZE_T((root->perm)+minusSubdim, (root->size)-minusSubdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}

dimension* sub_copy_dim_head(dimension *root, size_t subdim){
  if(subdim < (root->size)){
    dimension *d = INIT_COPY_PERMUTATION_TYPE_SIZE_T(root->perm, subdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}

dimension* sub_copy_dim_tail(dimension *root, size_t subdim){
  if(subdim < (root->size)){
    dimension *d = INIT_COPY_PERMUTATION_TYPE_SIZE_T((root->perm)+(root->size - subdim), subdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}

void add_copy_dimension(dimension **d, dimension *d0, dimension *d1) {
    (*d) = create_dim(d0->size + d1->size);
    for (size_t i = 0; i < d0->size; i++) (*d)->perm[i] = d0->perm[i];
    for (size_t i = 0; i < d1->size; i++) (*d)->perm[d0->size + i] = d1->perm[i];
    updateRankDim(*d);
}

void min_copy_dimension(dimension **d, dimension *d0, dimension *d1) {
    size_t mindim = min(d0->size,d1->size) ;
    (*d)=create_dim(mindim);

       for (size_t i = 0; i < mindim; i++) {
            if (d0->perm[i] > d1->perm[i]) (*d)->perm[i] = d1->perm[i];
            else (*d)->perm[i] = d0->perm[i];
        }
    updateRankDim(*d);
}




dimension* sub_minus_dim_head(dimension *root, size_t minusSubdim){
  if(minusSubdim < (root->size)){
    dimension *d = INIT_PERMUTATION_TYPE_SIZE_T(root->perm, (root->size)-minusSubdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}
dimension* sub_minus_dim_tail(dimension *root, size_t minusSubdim){
  if(minusSubdim < (root->size)){
    dimension *d = INIT_PERMUTATION_TYPE_SIZE_T((root->perm)+minusSubdim, (root->size)-minusSubdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}
dimension* sub_dim_head(dimension *root, size_t subdim){
  if(subdim < (root->size)){
    dimension *d = INIT_PERMUTATION_TYPE_SIZE_T(root->perm, subdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}
dimension* sub_dim_tail(dimension *root, size_t subdim){
  if(subdim < (root->size)){
    dimension *d = INIT_PERMUTATION_TYPE_SIZE_T((root->perm)+(root->size - subdim), subdim);
    updateRankDim(d);
    return d;
  }
  return NULL;
}

/*
void split_dim_part(dimension *root, dimension **part_1, dimension **part_2, size_t sz_nb_minus_part ) */
void split_dim_part(dimension *root, dimension **part_1, dimension **part_2, size_t pivotSplit, size_t rangeInPivot ) {
  if(pivotSplit < root->size){
  if(rangeInPivot <  root->perm[pivotSplit]){
    //size_t sz_part1= (root->rank * sz_nb_minus_part)/(root->perm[(root->size)-1]);
    //printf("sz_part1 :%ld \n",sz_part1);
    *part_1 = init_copy_dim(root->perm, root->size);
    ((*part_1)->perm[pivotSplit]) -= rangeInPivot;
    updateRankDim(*part_1);
    /*if(sz_nb_minus_part <2)
      *part_2 = init_copy_dim((root->perm), root->size-1 );
    else{*/
      *part_2 = init_copy_dim((root->perm), root->size );
      (*part_2)->perm[pivotSplit] = rangeInPivot ;
    //}
    updateRankDim(*part_2);
  }
  }
}

void increment_dim_var(dimension *d){
  if(endian){
    (d->perm[0])++;
  }
  else{
    (d->perm[d->size - 1])++;
  }
}

void add_dimension(dimension **d, dimension *d0, dimension *d1) {
    (*d) = create_dim(d0->size + d1->size);
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

  printf("(%s)->size = %ld | (%s)->rank = %ld \n[",msg,d->size,msg,d->rank);
  for(size_t i=0; i<d->size; ++i)
    printf(" %ld,", d->perm[i]);
    printf("] \n");
    //printf("[%ld: %ld] |", i,d->perm[i]);
 /* if(endian)
    printf("\nendian (true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index\n");
  else
    printf("\nendian (false): the lowest index varies first, e.g: [x0,x1,x2,...,xn] x0 is the lowest index\n");
*/
}

size_t sprint_dimension(char **dimContent, dimension *d){
  if(*dimContent != NULL){
    free(*dimContent);
    *dimContent=NULL;
  }
  size_t nbch=6*d->size+40;
  *dimContent = malloc(nbch);
  //printf("nbCh=%ld\n",nbch);
  char *val=NULL;
  size_t cur=0;
  char *dimSzCh="dim->size";
  for(size_t i=0; i<strlen(dimSzCh);++i)
    (*dimContent)[cur++]=dimSzCh[i];
  (*dimContent)[cur++]='=';
  val=TYPE_SIZE_T_TO_STR(d->size);
  for(size_t c=0;c<strlen(val);++c)
    (*dimContent)[cur++]=val[c];
  free(val); val = NULL;
  (*dimContent)[cur++]=' ';
  (*dimContent)[cur++]='/';
  (*dimContent)[cur++]=' ';
  char *dimRkCh="dim->rank";
  for(size_t i=0; i<strlen(dimRkCh);++i)
    (*dimContent)[cur++]=dimRkCh[i];
  (*dimContent)[cur++]='=';
  val=TYPE_SIZE_T_TO_STR(d->rank);
  for(size_t c=0;c<strlen(val);++c)
    (*dimContent)[cur++]=val[c];
  free(val); val = NULL;
  (*dimContent)[cur++]=' ';
  (*dimContent)[cur++]='\n';
  (*dimContent)[cur++]='[';
  for(size_t i=0; i<d->size;++i){
    (*dimContent)[cur++]=' ';
    val=TYPE_SIZE_T_TO_STR(d->perm[i]);
    for(size_t c=0;c<strlen(val);++c)
      (*dimContent)[cur++]=val[c];
    free(val); val = NULL;
    (*dimContent)[cur++]=',';
   
  }
  (*dimContent)[cur++]=']';

  (*dimContent)[cur++]='\n';
  (*dimContent)[cur++]='\0';

  return cur;
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

void append_in_list_perm(list_perm_in_dim **list_p, size_t perm){
    list_perm_in_dim *lis=malloc(sizeof(list_perm_in_dim));
    lis->perm=perm;
    lis->next=NULL;
  if(*list_p == NULL){
    lis->index=0;
    *list_p = lis;
  }
  else{
    list_perm_in_dim *tmp =*list_p;
    while(tmp->next) tmp=tmp->next;
    lis->index = tmp->index +1;
    tmp->next=lis;
  }
}

dimension * create_dim_from_list_perm( list_perm_in_dim *l_p){

  if(l_p){
    list_perm_in_dim *tmp =l_p;
    while(tmp->next) tmp=tmp->next;
    dimension *dim=create_dim(tmp->index + 1);
    (dim)->size = tmp->index + 1;
    tmp=l_p;
    while(tmp){
      (dim)->perm[tmp->index]=tmp->perm;
      tmp=tmp->next;
    }
    updateRankDim(dim);
    return dim;
  }
  return NULL;
}

void free_list_perm_in_dim(list_perm_in_dim *l_p){
  list_perm_in_dim *tmp=l_p, *ttmp;
  while(tmp){
    ttmp = tmp;
    tmp = ttmp->next;
    free(ttmp);
  }
}

