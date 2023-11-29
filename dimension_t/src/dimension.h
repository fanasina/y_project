#ifndef __DIM__
#define __DIM__

#include <stdio.h>
#include <stdlib.h>

struct dimension
{
    unsigned int rank;
    unsigned int* dim;
    size_t size;
};
typedef dimension dimension;


void print_dimension(dimension d);


void add(dimension* d, const dimension* d0, const dimension* d1);

void max(dimension* d, const dimension* d0, const dimension* d1);

void min(dimension* d, const dimension* d0, const dimension* d1);

bool minReverse(dimension* d, const dimension* d0, const dimension* d1);

void transform(dimension* dDst, const dimension* dSrc, int* perm);


#endif

