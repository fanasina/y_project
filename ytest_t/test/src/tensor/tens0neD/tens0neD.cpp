#include <cstdio>
#include <cstdlib>

#include <stdexcept>

#include <vector>
#include <algorithm>


//#include "/home/fanasina/progr_/ptens0neD/tensor/tens0neD/tens0neD.h"
#include "tensor/tens0neD/tens0neD.h"
//#include "include/tens0neD.h"


//#include "cudatensor.h"
//#include "/home/fanasina/progr_/ptens0neD/permutation/permutation.h"
#include "permutation/permutation.h"


template<typename T>
void transform(Tensor<T>& Dst, const Tensor<T>& Src, int* perm, int sz) {
    transform(Dst.Dim, Src.Dim, perm, sz);
    dimension dsrc = Src.Dim;
    dimension ddst = Dst.Dim;
    int coor[dsrc.rank];
    int dcoor[ddst.rank], ldst;
    for (int i = 0; i < Src.Dim.size; i++) {
        dsrc.LinearToCoord(coor, i);
        for (int j = 0; j < dsrc.rank; j++) dcoor[j] = coor[perm[j]];
        ldst = ddst.CoordToLinear(dcoor);
        Dst.elements[ldst] = Src.elements[i];
    }
}

template void transform<float>(Tensor<float>& Dst, const Tensor<float>& Src, int* perm, int sz);
template void transform<double>(Tensor<double>& Dst, const Tensor<double>& Src, int* perm, int sz);

template<typename T>
Tensor<T>& Tensor<T>::operator=(const Tensor<T>& M) {
    Dim = M.Dim;
    for (int i = 0; i < Dim.size; ++i) elements[i] = M.elements[i];
    return *this;
}

template<typename T>
Tensor<T>& Tensor<T>::operator*=(const T& val) {
    //for (int i = 0; i < rank.size; ++i) elements[i] *= val;
    return *this;
}

template<typename T>
Tensor<T>& operator*(const Tensor<T>& M0, const Tensor<T>& M1) {
    struct dimension d; add(d, M0.Dim, M1.Dim);
    Tensor<T> Mret(d);
    for (int i = 0; i < M0.Dim.size; ++i) Mret.elements[i] = M0.elements[i];
    Mret.Dim += M0.Dim;
    return Mret;
}


void subArray(int* dst, int* src, int debDst, int finDst, int debSrc) {
    for (int i = debDst; i < finDst; i++) {
        dst[i] = src[i + debSrc];
    }
}

void concatArray(int* dst, int* src0, int* src1, int debDst, int debSrc0, int finSrc0, int debSrc1, int finSrc1) {
    int i = debDst;
    for (int j = debSrc0; j < finSrc0; j++) {
        dst[i++] = src0[j];
    }
    for (int j = debSrc1; j < finSrc1; j++) {
        dst[i++] = src1[j];
    }
}

template<typename T>
void Tensor<T>::initVal(T val) {
    int* coord = new int[Dim.rank];
    T pp, mult = 0.5;
    for (int i = 0; i < Dim.size; i++) {
        Dim.LinearToCoord(coord, i);
        elements[i] = val;
        pp = mult;
        for (int j = 0; j < Dim.rank; j++) {
            elements[i] += (coord[j] + 1) * pp;
            pp *= mult;
        }
    }
}
template
void Tensor<float>::initVal(float val);
template
void Tensor<double>::initVal(double val);

template<typename T>
void Tensor<T>::print() {
    Dim.print();
    int* coord = new int[Dim.rank];
    int begin = 0, end = Dim.rank - 1;
    //int beginInv = Dim.rank - 1, endInv = 0;
    int (*iter)(int) = incr;
    //int (*iterInv)(int) = decr;
    bool (*cond)(int, int) = isLessEqThan;
    //bool (*condInv)(int, int) = isGreatEqThan;
    if (Dim.endian == false) {
        begin = Dim.rank - 1; end = 0;
        //beginInv = 0; endInv = Dim.rank - 1;
        iter = decr; cond = isGreatEqThan;
        //iterInv = incr; condInv = isLessEqThan;
    }
    for (int i = 0; i < Dim.size; i++) {
        Dim.LinearToCoord(coord, i);
        //if (coord[Dim.rank - 1] == 0) {
        if (coord[begin] == 0) {
            for (int j = begin; cond(j, end); j = iter(j)) {
                //for (int j = Dim.rank - 1; j >= 0; j--) {
                if (coord[j] == 0) {
                    printf("(");
                }
                else break;
            }
        }

        //printf(" ");for (int j = 0; j < Dim.rank; j++)  printf("[%d]", coord[j]); printf(" ");
        //printf(" ");  for (int j = beginInv; condInv(j, endInv); j = iterInv(j))  printf("[%d]", coord[j]); printf(" ");
        //printf(" ");  for (int k = beginInv; condInv(k, endInv); k = iterInv(k)) { printf("[%d]", coord[k]); } printf(" ");

        printf(" %.6f ", elements[i]);

        //if (coord[Dim.rank - 1] == Dim.dim[Dim.rank - 1] - 1) {
        if (coord[begin] == Dim.dim[begin] - 1) {
            for (int j = begin; cond(j, end); j = iter(j)) {
                //for (int j = Dim.rank - 1; j >= 0; j--) {
                if (coord[j] == Dim.dim[j] - 1) {
                    printf(")");
                }
                else break;
            }
        }
    }

    printf("\n");
}
template
void Tensor<float>::print();
template
void Tensor<double>::print();

template<typename T>
void tensorProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1) {
    add(M.Dim, M0.Dim, M1.Dim);
    M.initTensor();
    int* coord = new int[M.Dim.rank];
    int* coord0 = new int[M0.Dim.rank], lin0;
    int* coord1 = new int[M1.Dim.rank], lin1;
    for (int i = 0; i < M.Dim.size; i++) {
        M.Dim.LinearToCoord(coord, i);
        subArray(coord0, coord, 0, M0.Dim.rank, 0);
        subArray(coord1, coord, 0, M1.Dim.rank, M0.Dim.rank);
        lin0 = (M0.Dim).CoordToLinear(coord0);
        lin1 = (M1.Dim).CoordToLinear(coord1);
        M.elements[i] = M0.elements[lin0] * M1.elements[lin1];
    }
}

template
void tensorProd<double>(Tensor<double>& M, const Tensor<double>& M1, const Tensor<double>& M0);
template
void tensorProd<float>(Tensor<float>& M, const Tensor<float>& M1, const Tensor<float>& M0);




bool checkMatchProdTensor(const dimension& d0, const dimension& d1, int nestingDepth) {
    if (d0.rank <= nestingDepth || d1.rank <= nestingDepth) return false;
    for (int i = 0; i < nestingDepth;i++) {
        if (d1.dim[i] != d0.dim[d0.rank - nestingDepth + i]) return false;
    }
    return true;
}

bool checkMatchProdTensorReverse(const dimension& d0, const dimension& d1, int nestingDepth) {
    if (d0.rank <= nestingDepth || d1.rank <= nestingDepth) return false;
    for (int i = 0; i < nestingDepth;i++) {
        if (d1.dim[i] != d0.dim[d0.rank - 1 - i]) return false;
    }
    return true;
}

void extractDimNestingDepth(dimension& dM, const dimension& d0, const dimension& d1, int nestingDepth) {
    int len0 = d0.rank - nestingDepth;
    int len1 = d1.rank - nestingDepth;

    int* tsub0 = new int[len0];
    int* tsub1 = new int[len1];
    int* tDk1 = new int[nestingDepth];
    int* tDk0 = new int[nestingDepth];
    subArray(tsub0, d0.dim, 0, len0, 0);
    subArray(tsub1, d1.dim, 0, len1, nestingDepth);
    subArray(tDk1, d1.dim, 0, nestingDepth, 0);
    subArray(tDk0, d0.dim, 0, nestingDepth, len0);
    dimension dSub0(len0, tsub0);
    dimension dSub1(len1, tsub1);
    dimension dM1(nestingDepth, tDk1);
    dimension dM0(nestingDepth, tDk0);

    min(dM, dM0, dM1);
    //max(dM, dM0, dM1);
}

// M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l
// M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)   
//M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]
template<typename T>
void tensorContractnProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1, int nestingDepth) {
    if (!checkMatchProdTensor(M0.Dim, M1.Dim, nestingDepth)) {
        printf("Deep = %d\n", nestingDepth);
        //throw std::check_ProdTensor(" Failed imbrication order in Multiplication matrix ");

        //throw std::invalid_argument(" Failed imbrication order in Multiplication matrix ");
    }

    int len0 = M0.Dim.rank - nestingDepth;
    int len1 = M1.Dim.rank - nestingDepth;

    int* tsub0 = new int[len0];
    int* tsub1 = new int[len1];
    int* tDk1 = new int[nestingDepth];
    int* tDk0 = new int[nestingDepth];
    subArray(tsub0, M0.Dim.dim, 0, len0, 0);
    subArray(tsub1, M1.Dim.dim, 0, len1, nestingDepth);
    subArray(tDk1, M1.Dim.dim, 0, nestingDepth, 0);
    subArray(tDk0, M0.Dim.dim, 0, nestingDepth, len0);

    dimension dSub0(len0, tsub0);
    dimension dSub1(len1, tsub1);
    dimension dM1(nestingDepth, tDk1);
    dimension dM0(nestingDepth, tDk0);
    dimension dM;
    min(dM, dM0, dM1);
    //max(dM, dM0, dM1);

    add(M.Dim, dSub0, dSub1);
    M.initTensor();

    int* coord = new int[M.Dim.rank];

    int* coord0 = new int[len0], lin0;
    int* coord1 = new int[len1], lin1;

    int* coordM0 = new int[M0.Dim.rank];
    int* coordM1 = new int[M1.Dim.rank];

    int* Koord = new int[nestingDepth];
    for (int i = 0; i < M.Dim.size; i++) {
        M.Dim.LinearToCoord(coord, i);
        subArray(coord0, coord, 0, len0, 0);
        subArray(coord1, coord, 0, len1, len0);
        M.elements[i] = 0;
        for (int k = 0; k < dM.size; k++) {
            dM.LinearToCoord(Koord, k);
            concatArray(coordM0, coord0, Koord, 0, 0, len0, 0, nestingDepth);
            concatArray(coordM1, Koord, coord1, 0, 0, nestingDepth, 0, len1);
            lin0 = (M0.Dim).CoordToLinear(coordM0);
            lin1 = (M1.Dim).CoordToLinear(coordM1);
            M.elements[i] += M0.elements[lin0] * M1.elements[lin1];
        }
    }
}

template
void tensorContractnProd<float>(Tensor<float>& M, const Tensor<float>& M0, const Tensor<float>& M1, int nestingDepth);
template
void tensorContractnProd<double>(Tensor<double>& M, const Tensor<double>& M0, const Tensor<double>& M1, int nestingDepth);

void reverseDim(dimension& d, const dimension& d0) {
    d.rank = d0.rank;
    d.size = d0.size;
    if (d.dim != NULL) free(d.dim);
    d.dim = (int*)malloc(d.rank * sizeof(int));
    for (int i = 0; i < d.rank; i++) d.dim[i] = d0.dim[d.rank - i - 1];
}

template<typename T>
void reverseTensor(Tensor<T>& M, const Tensor<T>& M0) {
    reverseDim(M.Dim, M0.Dim);
    size_t id;
    int coor[M0.Dim.rank];
    for (size_t i = 0; i < M.Dim.size; i++) {
        M0.Dim.LinearToCoord(coor, i);
        reverseArray(coor, M0.Dim.rank);
        id = M.Dim.CoordToLinear(coor);
        M.elements[id] = M0.elements[i];
    }
}

// M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xn = y0,x{n-1}=y1, x{n-l}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l
// M[x0,x1,x3..xl x{l+1}..xn] X M[xn,x{n-1},..x{l+1}xl y{l+1}..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)  
//M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]
template<typename T>
void tensorContractnReverseProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1, int nestingDepth) {
    if (!checkMatchProdTensorReverse(M0.Dim, M1.Dim, nestingDepth)) {
        printf("Failed in Deep = %d\n", nestingDepth);
        //throw std::check_ProdTensor(" Failed imbrication order in Multiplication matrix ");

        //throw std::invalid_argument(" Failed imbrication order in Multiplication matrix ");
    }

    int len0 = M0.Dim.rank - nestingDepth;
    int len1 = M1.Dim.rank - nestingDepth;

    int* tsub0 = new int[len0];
    int* tsub1 = new int[len1];
    int* tDk1 = new int[nestingDepth];
    int* tDk0 = new int[nestingDepth];
    subArray(tsub0, M0.Dim.dim, 0, len0, 0);
    subArray(tsub1, M1.Dim.dim, 0, len1, nestingDepth);
    subArray(tDk1, M1.Dim.dim, 0, nestingDepth, 0);
    subArray(tDk0, M0.Dim.dim, 0, nestingDepth, len0);

    dimension dSub0(len0, tsub0);
    dimension dSub1(len1, tsub1);
    dimension dM1(nestingDepth, tDk1);
    dimension dM0(nestingDepth, tDk0);
    dimension dM;
    bool rev;
    minReverse(dM, dM0, dM1, rev);
    if (rev) reverseArray(dM.dim, dM.rank);
    //max(dM, dM0, dM1);

    add(M.Dim, dSub0, dSub1);
    M.initTensor();

    int* coord = new int[M.Dim.rank];

    int* coord0 = new int[len0], lin0;
    int* coord1 = new int[len1], lin1;

    int* coordM0 = new int[M0.Dim.rank];
    int* coordM1 = new int[M1.Dim.rank];

    int* Koord = new int[nestingDepth];
    for (int i = 0; i < M.Dim.size; i++) {
        M.Dim.LinearToCoord(coord, i);
        subArray(coord0, coord, 0, len0, 0);
        subArray(coord1, coord, 0, len1, len0);
        M.elements[i] = 0;
        for (int k = 0; k < dM.size; k++) {
            dM.LinearToCoord(Koord, k);
            concatArray(coordM0, coord0, Koord, 0, 0, len0, 0, nestingDepth);
            reverseArray(Koord, nestingDepth);
            concatArray(coordM1, Koord, coord1, 0, 0, nestingDepth, 0, len1);
            lin0 = (M0.Dim).CoordToLinear(coordM0);
            lin1 = (M1.Dim).CoordToLinear(coordM1);
            M.elements[i] += M0.elements[lin0] * M1.elements[lin1];
        }
    }
}

template
void tensorContractnReverseProd<float>(Tensor<float>& M, const Tensor<float>& M0, const Tensor<float>& M1, int nestingDepth);
template
void tensorContractnReverseProd<double>(Tensor<double>& M, const Tensor<double>& M0, const Tensor<double>& M1, int nestingDepth);

template<typename T>
void permuteTensorDef(Tensor<T>& M, const Tensor<T>& M0, permutation p) {
    if (p.size == M0.Dim.rank) {
        M.Dim.rank = M0.Dim.rank;
        M.Dim.size = M0.Dim.size;
        M.Dim.initDim();
        M.initTensor();
        //permuteArray(M.Dim.dim, M0.Dim.dim, p);
        //for (int i = 0; i < p.size; i++) { M.Dim.dim[i] = M0.Dim.dim[p.perm[i]]; }
        p.permute(M.Dim.dim, M0.Dim.dim);
        size_t img;
        int coor[p.size];
        int rooc[p.size];
        for (size_t i = 0; i < M.Dim.size;i++) {
            M0.Dim.LinearToCoord(coor, i);
            p.permute(rooc, coor);
            img = M.Dim.CoordToLinear(rooc);
            if (img >= M.Dim.size) printf(" i: %ld vs img:%ld size: %ld\n", i, img, M.Dim.size);
            M.elements[img] = M0.elements[i];

        }
    }
}

template
void permuteTensorDef(Tensor<float>& M, const Tensor<float>& M0, permutation p);

template<typename T>
bool scanPermuteMatchContractTensorfromSrcToDst(int* perm, const Tensor<T>& Msecond, const Tensor<T>& Mfirst, int contractNest) {
    if (contractNest < Msecond.Dim.rank && contractNest < Mfirst.Dim.rank) {
        std::vector<int> founded;
        int begin = Mfirst.Dim.rank - contractNest, tmp;
        for (int i = 0; i < Msecond.Dim.rank;i++) perm[i] = i;
        for (int i = begin; i < Mfirst.Dim.rank; i++) {
            for (int j = 0; j < Msecond.Dim.rank;j++) {
                if (std::find(founded.begin(), founded.end(), perm[j]) == founded.end()) {// not found
                    if (Msecond.Dim.dim[perm[j]] == Mfirst.Dim.dim[i]) {
                        founded.push_back(perm[j]);
                        tmp = perm[i - begin];
                        perm[i - begin] = perm[j];
                        perm[j] = tmp;
                    }
                }
            }
        }
        return (founded.size() == contractNest);
    }
    return false;
}
template
bool scanPermuteMatchContractTensorfromSrcToDst(int* perm, const Tensor<float>& Msecond, const Tensor<float>& Mfirst, int contractNest);


template<typename T>
bool scanInvPermuteMatchContractTensorfromSrcToDst(int* perm, const Tensor<T>& Msecond, const Tensor<T>& Mfirst, int contractNest) {
    if (contractNest < Msecond.Dim.rank && contractNest < Mfirst.Dim.rank) {
        std::vector<int> founded;
        int begin = Mfirst.Dim.rank - contractNest, tmp;
        for (int i = 0; i < Msecond.Dim.rank;i++) perm[i] = i;
        for (int i = begin; i < Mfirst.Dim.rank; i++) {
            for (int j = 0; j < Msecond.Dim.rank;j++) {
                if (std::find(founded.begin(), founded.end(), j) == founded.end()) {// not found
                    if (Msecond.Dim.dim[j] == Mfirst.Dim.dim[perm[i - begin]]) {
                        founded.push_back(j);
                        tmp = perm[i - begin];
                        perm[i - begin] = j;
                        perm[j] = tmp;
                    }
                }
            }
        }
        return (founded.size() == contractNest);
    }
    return false;
}
template
bool scanInvPermuteMatchContractTensorfromSrcToDst(int* perm, const Tensor<float>& Msecond, const Tensor<float>& Mfirst, int contractNest);


void LinearTransformCoord(size_t& dst, size_t src, int* inversePerm, size_t Msize, dimension dDst, dimension dSrc) {
    size_t sm = src;
    size_t pp = Msize;
    size_t s = 0;
    size_t p = 1;
    int ret;// = new int[rank];
    int i;
    for (i = 0; i < dSrc.rank; ++i) {
        pp /= dSrc.dim[i];
        ret = sm / pp;
        p = 1;
        for (int j = inversePerm[i] + 1; j < dDst.rank;j++) {
            p *= dDst.dim[j];
        }
        s += ret * p;

        sm %= pp;

    }
    dst = s;
    if (s > Msize) printf("I have a problem in LinearTransformCoord: s:%ld siez:%ld \n", s, Msize);

}


template<typename T>
void permuteTensor(Tensor<T>& M, const Tensor<T>& M0, permutation p) {
    if (p.size == M0.Dim.rank) {
        M.Dim.rank = M0.Dim.rank;
        M.Dim.size = M0.Dim.size;
        M.Dim.initDim();
        M.initTensor();

        if (p.size == M0.Dim.rank) p.permute(M.Dim.dim, M0.Dim.dim);
        else {
            printf("something wrong perm, not the same size as M0.Dim.rank\n");
            exit(1);
        }
        size_t img = 0;
        printf("in permuteTensor:\n");
        M0.Dim.print();
        M.Dim.print();
        setInit se(M.Dim.rank, 0);
        int invP[M.Dim.rank];
        inverseArray(invP, p.perm, M.Dim.rank);
        for (size_t i = 0; i < M.Dim.size;i++) {
            //LinearTransformCoord(img, i, p.perm, M.Dim.size, M.Dim, M0.Dim);
            LinearTransformCoord(img, i, invP, M.Dim.size, M.Dim, M0.Dim);
            M.elements[img] = M0.elements[i];
        }
    }
}

template
void permuteTensor(Tensor<float>& M, const Tensor<float>& M0, permutation p);

