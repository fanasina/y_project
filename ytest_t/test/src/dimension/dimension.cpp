#include <cstdio>
#include <cstdlib>

#include <stdexcept>

#include <vector>
#include <algorithm>



//#include "/home/fanasina/progr_/ptens0neD/dimension/dimension.h"

//#include "/home/fanasina/progr_/ptens0neD/permutation/permutation.h"


#include "dimension/dimension.hpp"

#include "permutation/permutation.hpp"
//#include "permutation.h"

/*void dimension::initDim(int* arr, bool end = true) {
    endian = end;
    delete[]dim;
    dim = new int[rank];
    size = 1;
    for (int i = 0; i < rank; ++i) {
        dim[i] = arr[i];
        size *= dim[i];
    }
}*/

dimension& dimension::operator=(const dimension& d) {
    int oldRank = rank;
    rank = d.rank;
    size = d.size;
    initDim(d.dim, oldRank);
    //for (int i = 0; i < rank; i++) dim[i] = d.dim[i];
    return *this;
}

dimension& dimension::operator+=(const dimension& d) {
    int oldRank = rank;
    int* t = new int[rank + d.rank];
    for (int i = 0; i < rank; i++) t[i] = dim[i];
    for (int i = 0; i < d.rank; i++) t[rank + i] = d.dim[i];
    size *= d.size;
    rank += d.rank;
    initDim(t, oldRank);
    return *this;
}

void dimension::LinearToCoord(int* ret, int lin) const {
    int begin = 0, end = rank - 1;
    int (*iter)(int) = incr;
    bool (*cond)(int, int) = isLessThan;
    if (endian == false) {
        //if (endian) {
        begin = rank - 1; end = 0;
        iter = decr; cond = isGreatThan;
    }
    //printf("to coor begin = %d end = %d \n", begin, end);

    int sm = lin;
    int pp = size;
    for (int i = begin; cond(i, end); i = iter(i)) {
        //printf(" i: %d ", i);
        pp /= dim[i];
        ret[i] = sm / pp;
        sm %= pp;
        //printf("sm[%d] = %d , pp=%d ; ", i, sm, pp);
    }
    ret[end] = sm;
}

int dimension::CoordToLinear(int* coo) const {
    int begin = 0;
    int end = rank - 1;
    int (*iter)(int); iter = &incr;
    bool (*cond)(int, int); cond = &isLessEqThan;

    if (endian) {
        begin = rank - 1; end = 0;
        iter = &decr; cond = &isGreatEqThan;
    }

    int pp = 1;
    int sm = 0;
    for (int i = begin; cond(i, end); i = iter(i)) {
        sm += (coo[i] * pp);
        pp *= dim[i];
    }
    return sm;
}

bool isLessEqThan(int a, int b) { return a <= b; }
bool isLessThan(int a, int b) { return a < b; }
bool isGreatEqThan(int a, int b) { return a >= b; }
bool isGreatThan(int a, int b) { return a > b; }
int incr(int i) { return i + 1; }
int decr(int i) { return i - 1; }


void add(dimension& d, const dimension& d0, const dimension& d1) {
    int oldRank = d.rank;
    int* t = new int[d0.rank + d1.rank];
    for (int i = 0; i < d0.rank; i++) t[i] = d0.dim[i];
    for (int i = 0; i < d1.rank; i++) t[d0.rank + i] = d1.dim[i];
    d.rank = d0.rank + d1.rank;
    d.initDim(t, oldRank);
}

void max(dimension& d, const dimension& d0, const dimension& d1) {
    if (d0.rank > d1.rank) {
        d = d0;
    }
    else if (d0.rank < d1.rank) {
        d = d1;
    }
    else {// d0.rank = d1.rank
        d = d0;
        for (int i = 0; i < d.rank; i++) {
            if (d.dim[i] < d1.dim[i]) d.dim[i] = d1.dim[i];
        }
    }
}

void min(dimension& d, const dimension& d0, const dimension& d1) {
    if (d0.rank > d1.rank) {
        d = d1;
    }
    else if (d0.rank < d1.rank) {
        d = d0;
    }
    else {// d0.rank = d1.rank
        d = d0;
        for (int i = 0; i < d.rank; i++) {
            if (d.dim[i] > d1.dim[i]) d.dim[i] = d1.dim[i];
        }
    }
}

void minReverse(dimension& d, const dimension& d0, const dimension& d1, bool& rev) {
    if (d0.rank > d1.rank) {
        d = d1;
        rev = true;
    }
    else if (d0.rank < d1.rank) {
        d = d0;
        rev = false;
    }
    else {// d0.rank = d1.rank
        d = d0;
        for (int i = 0; i < d.rank; i++) {
            if (d.dim[i] > d1.dim[d.rank - 1 - i]) d.dim[i] = d1.dim[d.rank - 1 - i];
        }
        rev = false;
    }
}

void reverseArray(int* arr, int sz) {
    int tmp[sz], i = 0;
    for (; i < sz / 2; i++) {
        tmp[i] = arr[i];
        arr[i] = arr[sz - 1 - i];
    }
    for (; i < sz; i++) {
        arr[i] = tmp[sz - 1 - i];
    }
}

void transform(dimension& dDst, const dimension& dSrc, int* perm, int sz) {
    dDst = dSrc;
    setInit setIn(sz);
    if (sz == dSrc.rank) {
        if (isPermutation(perm, setIn, sz)) {
            for (int i = 0; i < sz; i++) dDst.dim[i] = dSrc.dim[perm[i]];
        }
    }
}


