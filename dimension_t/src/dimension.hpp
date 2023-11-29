#ifndef __DIMENSION__
#define __DIMENSION__

#include <cstdio>
#include <cstdlib>

#include <stdexcept>

//#include "tensor.h"

//#include "dimension.h"

static int iArray1[1] = { 1 };



struct dimension {
    //friend dimension& operator+(const dimension& d, const dimension& d1);
    friend void add(dimension& d, const dimension& d0, const dimension& d1);
    friend void max(dimension& d, const dimension& d0, const dimension& d1);
    friend void min(dimension& d, const dimension& d0, const dimension& d1);
    friend void minReverse(dimension& d, const dimension& d0, const dimension& d1, bool& Rev);
    friend bool checkMatchProdTensor(dimension& d0, const dimension& d1, int nestingDepth);
    friend bool checkMatchProdTensorReverse(dimension& d0, const dimension& d1, int nestingDepth);
    friend void extractDimNestingDepth(dimension& dM, const dimension& d0, const dimension& d1, int nestingDepth);


    int rank;
    int* dim;
    size_t size;
    bool endian; //LitleEndian : true,  BigEndian : false, 
    void initDim(int* arr, int oldRank) {

        //delete[]dim;
        //dim = new int[rank];
        if (rank > oldRank) {
            free(dim);
            dim = (int*)malloc(rank * sizeof(int));
        }
        size = 1;
        for (int i = 0; i < rank; ++i) {
            dim[i] = arr[i];
            size *= dim[i];
        }
    }
    void initDim(bool end = true) {
        endian = end;
        //delete[]dim;
        //dim = new int[rank];

        if (dim != NULL) free(dim);
        dim = (int*)malloc(rank * sizeof(int));
    }
    dimension& operator=(const dimension& d);
    dimension& operator+=(const dimension& d);
    //dimension& operator*=(const dimension& d);
    dimension(int d = 1, int* arr = iArray1, bool end = true) {
        endian = end;
        rank = d;
        //dim = new int[d];
        dim = (int*)malloc(d * sizeof(int));
        initDim(arr, rank);
    }
    void print() const { printf(" rank: %d\n", rank);for (int i = 0; i < rank; i++) printf(" %d ", dim[i]);printf("\nsize:%ld\n", size); }
    void LinearToCoord(int* ret, int  lin) const;
    int CoordToLinear(int* coo) const;
};

bool isLessEqThan(int a, int b); // { return a <= b; }
bool isLessThan(int a, int b); // { return a < b; }
bool isGreatEqThan(int a, int b); //  { return a >= b; }
bool isGreatThan(int a, int b); //  { return a > b; }
int incr(int i); //  { return i + 1; }
int decr(int i); //  { return i - 1; }



void add(dimension& d, const dimension& d0, const dimension& d1);

void max(dimension& d, const dimension& d0, const dimension& d1);

void min(dimension& d, const dimension& d0, const dimension& d1);

void minReverse(dimension& d, const dimension& d0, const dimension& d1, bool& rev);

void transform(dimension& dDst, const dimension& dSrc, int* perm, int sz);


#endif

