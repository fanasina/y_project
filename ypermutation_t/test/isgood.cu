#include <gtest/gtest.h>
#include <stdlib.h>

//#include "/home/fanasina/progr_/ptens0neD/src/tensor/tens0neD/tens0neD.h"
#include "src/tensor/tens0neD/tens0neD.h"
//#include "cudatensor.h"
//#include "/home/fanasina/progr_/ptens0neD/src/tensor/tensCuda/tensCuda.h"
#include "src/tensor/tensCuda/tensCuda.h"
/*TEST(LineraCoodTransform, check_print) {
    int t3[] = { [0] = 2,[1] = 4,[2] = 3 };

    struct dimension D0(3, t3);
    int coor0[3] = { 1,3,2 };
    int* coor1 = new int[3];

    int l0 = D0.CoordToLinear(coor0);

    D0.print();

    D0.LinearToCoord(coor1, l0);

    for (int i = 0; i < D0.rank; i++) {
        EXPECT_EQ(coor0[i], coor1[i]) << " coor0: " << coor0[i] << " coor1: " << coor1[i] << " i: " << i;
    }
}*/

TEST(subArray, concatArray) {
    int t[] = { 1,5,6,2,3 };
    int t0[] = { 1,5,6 };
    int t1[] = { 2,3 };
    int n = 5;
    int s0[3];
    int s1[2];
    int s[n];

    subArray(s0, t, 0, 3, 0);
    subArray(s1, t, 0, 2, 3);
    ASSERT_EQ(0, memcmp(t0, s0, sizeof(int) * 3));
    ASSERT_EQ(0, memcmp(t1, s1, sizeof(int) * 2));

    concatArray(s, s0, s1, 0, 0, 3, 0, 2);
    ASSERT_EQ(0, memcmp(t, s, sizeof(int) * 5));

}
TEST(tensorProdpetit, floatTemp) {

    /*int t3[] = { 2, 4, 3 };

    int t4[] = { 2, 4, 3, 2 };*/
    int t3[] = { 3, 6, 5 };

    int t4[] = { 3, 5, 8, 4 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<float> M3(d3), M4(d4), M;
    M3.initVal(3.0f); // M3.print();
    M4.initVal(2.0f); // M4.print();

    tensorProd<float>(M, M3, M4);
    //tensorProd(M, M4, M3);
    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int lin3, lin4, lin;
    d = M.Dim;

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
            for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
                            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {
                                for (int i = 0; i < d3.rank; i++) coord3[i] = idx3[i];
                                for (int i = 0; i < d4.rank; i++) coord4[i] = idx4[i];

                                concatArray(coord, coord3, coord4, 0, 0, d3.rank, 0, d4.rank);
                                lin3 = d3.CoordToLinear(coord3);
                                lin4 = d4.CoordToLinear(coord4);
                                lin = d.CoordToLinear(coord);

                                //ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                                ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                                //ASSERT_NEAR(M.elements[lin], M3.elements[lin3] * M4.elements[lin4], 0.0001) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                            }



}

TEST(tensorProd, doubleTemp) {

    int t3[] = { 2, 4, 3 };

    int t4[] = { 4, 3, 2,3 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<double> M3(d3), M4(d4), M;
    M3.initVal(3.0f); // M3.print();
    M4.initVal(2.0f); // M4.print();

    tensorProd(M, M3, M4);
    //tensorProd(M, M4, M3);
    d = M.Dim;
    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int lin3, lin4, lin;

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
            for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
                            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {
                                for (int i = 0; i < d3.rank; i++) coord3[i] = idx3[i];
                                for (int i = 0; i < d4.rank; i++) coord4[i] = idx4[i];

                                concatArray(coord, coord3, coord4, 0, 0, d3.rank, 0, d4.rank);
                                lin3 = d3.CoordToLinear(coord3);
                                lin4 = d4.CoordToLinear(coord4);
                                lin = d.CoordToLinear(coord);

                                //ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]);
                                ASSERT_DOUBLE_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]);
                                //ASSERT_NEAR(M.elements[lin], M3.elements[lin3] * M4.elements[lin4], 0.001) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                            }


}




void printArray(int* t, int sz) {
    for (int i = 0; i < sz;i++) printf(" %d ", t[i]);
}

TEST(tensorContractnProd, floatTemp) {

    int t3[] = { 2, 4, 3 };

    int t4[] = { 4, 3, 2, 3 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<float> M3(d3), M4(d4), M;
    M3.initVal(3.0f); // M3.print();
    M4.initVal(2.0f); // M4.print();

    int dee = 2;

    try {
        //tensorContractnProd(M, M3, M4, dee);
        tensorContractnProd(M, M3, M4, dee);
    }
    catch (const std::invalid_argument& e) {
        printf("bye from test tensorContractnProd floatTemp invalid arg! deep:\n");
        dimension dM;
        extractDimNestingDepth(dM, d3, d4, dee);
        dM.print();
        ASSERT_TRUE(false);
    }

    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int l0, l1;
    l0 = M3.Dim.rank - dee;
    l1 = M4.Dim.rank - dee;
    int pcoord3[l0];
    int pcoord4[l1];
    int r[dee];

    int lin3, lin4, lin;
    d = M.Dim;
    d.print();

    Tensor<float> Msum(d);
    //for (size_t idx = 0; idx < d.size; idx++) Msum.elements[idx] = 0.0f;

    //Msum.print();

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {

                for (int i = 0; i < l0; i++) pcoord3[i] = idx3[i];
                for (int i = 0; i < l1; i++) pcoord4[i] = idx4[i + dee];
                concatArray(coord, pcoord3, pcoord4, 0, 0, l0, 0, l1);
                lin = d.CoordToLinear(coord);
                Msum.elements[lin] = 0.0f;
                //for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
                //for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                    {
                        for (int i = 0; i < dee; i++) r[i] = idx4[i];

                        concatArray(coord3, pcoord3, r, 0, 0, l0, 0, dee);
                        concatArray(coord4, r, pcoord4, 0, 0, dee, 0, l1);
                        //printf("[");printArray(coord3, M3.Dim.rank); printf("]["); printArray(coord4, M4.Dim.rank);printf("] =*= ("); printArray(coord, Msum.Dim.rank); printf(")   |||");
                        lin3 = d3.CoordToLinear(coord3);
                        lin4 = d4.CoordToLinear(coord4);

                        Msum.elements[lin] += (M3.elements[lin3] * M4.elements[lin4]);
                        //printf("lin:%d lin3:%d lin4:%d el+:%f\n", lin, lin3, lin4, Msum.elements[lin]);

                    }

                ASSERT_FLOAT_EQ(Msum.elements[lin], M.elements[lin]);

            }



}

TEST(tensorContractnProdD, doubleTemp) {

    int t3[] = { 2, 3, 4 };

    int t4[] = { 3, 4, 2, 3 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<double> M3(d3), M4(d4), M;
    M3.initVal(3.0f); // M3.print();
    M4.initVal(2.0f); // M4.print();

    int dee = 2;

    try {
        //tensorContractnProd(M, M3, M4, dee);
        tensorContractnProd(M, M3, M4, dee);
    }
    catch (const std::invalid_argument& e) {
        printf("bye from test tensorContractnProd floatTemp invalid arg! deep:\n");
        dimension dM;
        extractDimNestingDepth(dM, d3, d4, dee);
        dM.print();
        ASSERT_TRUE(false);
    }

    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int l0, l1;
    l0 = M3.Dim.rank - dee;
    l1 = M4.Dim.rank - dee;
    int pcoord3[l0];
    int pcoord4[l1];
    int r[dee];

    int lin3, lin4, lin;
    d = M.Dim;
    d.print();

    Tensor<double> Msum(d);
    //for (size_t idx = 0; idx < d.size; idx++) Msum.elements[idx] = 0.0f;

    //Msum.print();

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {

                for (int i = 0; i < l0; i++) pcoord3[i] = idx3[i];
                for (int i = 0; i < l1; i++) pcoord4[i] = idx4[i + dee];
                concatArray(coord, pcoord3, pcoord4, 0, 0, l0, 0, l1);
                lin = d.CoordToLinear(coord);
                Msum.elements[lin] = 0.0f;
                //for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
                //for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                    {
                        for (int i = 0; i < dee; i++) r[i] = idx4[i];

                        concatArray(coord3, pcoord3, r, 0, 0, l0, 0, dee);
                        concatArray(coord4, r, pcoord4, 0, 0, dee, 0, l1);
                        //printf("[");printArray(coord3, M3.Dim.rank); printf("]["); printArray(coord4, M4.Dim.rank);printf("] =*= ("); printArray(coord, Msum.Dim.rank); printf(")   |||");
                        lin3 = d3.CoordToLinear(coord3);
                        lin4 = d4.CoordToLinear(coord4);

                        Msum.elements[lin] += (M3.elements[lin3] * M4.elements[lin4]);
                        //printf("lin:%d lin3:%d lin4:%d el+:%f\n", lin, lin3, lin4, Msum.elements[lin]);

                    }

                ASSERT_DOUBLE_EQ(Msum.elements[lin], M.elements[lin]);

            }



}

TEST(reverseArray, innt) {
    int n = 6;
    int t4[6] = { 3, 4, 2, 3 ,5, 1 };
    int revt4[6] = { 1,5,3,2, 4, 3 };
    reverseArray(t4, n);
    for (int i = 0; i < n; i++) {
        ASSERT_EQ(t4[i], revt4[i]);
    }
}

TEST(tensorContractnReverseProd, floatTemp) {

    int t3[] = { 4, 4, 3 };

    int t4[] = { 3, 4, 7, 2 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<float> M3(d3), M4(d4), M;
    M3.initVal(3.0f); // M3.print();
    M4.initVal(2.0f); // M4.print();

    int dee = 2;

    try {
        //tensorContractnProd(M, M3, M4, dee);
        tensorContractnReverseProd(M, M3, M4, dee);
    }
    catch (const std::invalid_argument& e) {
        printf("bye from test tensorContractnProd floatTemp invalid arg! deep:\n");
        dimension dM;
        extractDimNestingDepth(dM, d3, d4, dee);
        dM.print();
        ASSERT_TRUE(false);
    }

    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int l0, l1;
    l0 = M3.Dim.rank - dee;
    l1 = M4.Dim.rank - dee;
    int pcoord3[l0];
    int pcoord4[l1];
    int r[dee];
    int rev[dee];

    int lin3, lin4, lin;
    d = M.Dim;
    d.print();

    Tensor<float> Msum(d);

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {

                for (int i = 0; i < l0; i++) pcoord3[i] = idx3[i];
                for (int i = 0; i < l1; i++) pcoord4[i] = idx4[i + dee];
                concatArray(coord, pcoord3, pcoord4, 0, 0, l0, 0, l1);
                lin = d.CoordToLinear(coord);
                Msum.elements[lin] = 0.0f;
                //for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
                //for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                    {
                        for (int i = 0; i < dee; i++) {
                            r[i] = idx4[i];
                            rev[i] = idx4[dee - 1 - i];
                        }

                        concatArray(coord3, pcoord3, rev, 0, 0, l0, 0, dee);
                        concatArray(coord4, r, pcoord4, 0, 0, dee, 0, l1);
                        //printf("[");printArray(coord3, M3.Dim.rank); printf("]["); printArray(coord4, M4.Dim.rank);printf("] =*= ("); printArray(coord, Msum.Dim.rank); printf(")   |||");
                        lin3 = d3.CoordToLinear(coord3);
                        lin4 = d4.CoordToLinear(coord4);

                        Msum.elements[lin] += (M3.elements[lin3] * M4.elements[lin4]);
                        //printf("lin:%d lin3:%d lin4:%d el+:%f\n", lin, lin3, lin4, Msum.elements[lin]);
                    }
                ASSERT_FLOAT_EQ(Msum.elements[lin], M.elements[lin]);
            }
}


TEST(cudaTensorProd, floatTemp) {

    int t3[] = { 15, 6, 24 };

    int t4[] = { 23, 15, 6, 10 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<float> M3(d3), M4(d4), M;
    M3.initVal(1.0f); // M3.print();
    M4.initVal(0.5f); // M4.print();

    cudaTensorProd(M, M3, M4);
    //tensorProd(M, M4, M3);
    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int lin3, lin4, lin;
    d = M.Dim;
    d.print();

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
            for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
                            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {
                                for (int i = 0; i < d3.rank; i++) coord3[i] = idx3[i];
                                for (int i = 0; i < d4.rank; i++) coord4[i] = idx4[i];

                                concatArray(coord, coord3, coord4, 0, 0, d3.rank, 0, d4.rank);
                                lin3 = d3.CoordToLinear(coord3);
                                lin4 = d4.CoordToLinear(coord4);
                                lin = d.CoordToLinear(coord);

                                //ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;

                                //ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                                ASSERT_FLOAT_EQ(M.elements[lin], M3.elements[lin3] * M4.elements[lin4]) << " M " << M.elements[lin] << " lin: " << lin << " M3: " << M3.elements[lin3] << " lin3:" << lin3 << " lin4: " << lin4 << " M4 " << M4.elements[lin4] << std::endl;
                                //std::cout << " M " << M.elements[lin] << " lin: " << lin << " M3: " << M3.elements[lin3] << " lin3:" << lin3 << " lin4: " << lin4 << " M4 " << M4.elements[lin4] << std::endl;

                                //ASSERT_NEAR(M.elements[lin], M3.elements[lin3] * M4.elements[lin4], 0.0001) << " lin: " << lin << " lin3: " << lin3 << " lin4: " << lin4;
                            }

}


TEST(permuteTensor, float) {
    int t4[] = { 3, 8, 2, 4 };
    struct dimension  d4(4, t4);
    struct Tensor<float>  M4(d4), M;
    M4.initVal(1.0f);
    permutation p(4, true);
    int n = 5;
    //for (int n = 0; n < 24;n++) {
    PlaceToTab(p.perm, n, p.size);
    printf(" %*d  : ", 2, n);
    for (int i = 0; i < p.size; i++)printf("(%d)%d ", i, p.perm[i]);printf("\n");
    permuteTensor(M, M4, p);
    //permuteTensorDef(M, M4, p);
    int ind[4];
    int coor[4];
    size_t cM, cM4;
    for (ind[0] = 0; ind[0] < M4.Dim.dim[0]; ind[0]++)
        for (ind[1] = 0; ind[1] < M4.Dim.dim[1]; ind[1]++)
            for (ind[2] = 0; ind[2] < M4.Dim.dim[2]; ind[2]++)
                for (ind[3] = 0; ind[3] < M4.Dim.dim[3]; ind[3]++) {
                    p.permute(coor, ind);
                    cM = M.Dim.CoordToLinear(coor);
                    cM4 = M4.Dim.CoordToLinear(ind);
                    //printf("M[%ld]=%f M4[%ld]=%f \n", cM, M.elements[cM], cM4, M4.elements[cM4]);
                    ASSERT_FLOAT_EQ(M.elements[cM], M4.elements[cM4]);
                }

}


TEST(cudapermuteTensor, float) {
    int t4[] = { 3, 8, 2, 4 };
    struct dimension  d4(4, t4);
    struct Tensor<float>  M4(d4), M;
    M4.initVal(1.0f);
    permutation p(4, true);
    int n = 5;
    //for (int n = 0; n < 24;n++) {
    PlaceToTab(p.perm, n, p.size);
    printf(" %*d  : ", 2, n);
    for (int i = 0; i < p.size; i++)printf("{%d}%d ", i, p.perm[i]);printf("\n");
    cudapermuteTensor(M, M4, p);
    //permuteTensor(M, M4, p);
    //permuteTensorDef(M, M4, p);
    int ind[4];
    int coor[4];
    size_t cM, cM4;
    for (ind[0] = 0; ind[0] < M4.Dim.dim[0]; ind[0]++)
        for (ind[1] = 0; ind[1] < M4.Dim.dim[1]; ind[1]++)
            for (ind[2] = 0; ind[2] < M4.Dim.dim[2]; ind[2]++)
                for (ind[3] = 0; ind[3] < M4.Dim.dim[3]; ind[3]++) {
                    p.permute(coor, ind);
                    cM = M.Dim.CoordToLinear(coor);
                    cM4 = M4.Dim.CoordToLinear(ind);
                    //printf("M[%ld]=%f M4[%ld]=%f \n", cM, M.elements[cM], cM4, M4.elements[cM4]);
                    ASSERT_FLOAT_EQ(M.elements[cM], M4.elements[cM4]);
                }
}

TEST(scanPermuteMatchContractTensorfromSrcToDst1, permId) {
    int t[] = { 3, 8, 2, 3, 4 };
    //int tm[] = { 4, 2, 7, 3 };
    int tm[] = { 2, 3,4,7 };
    struct dimension  d(5, t);
    struct dimension  dm(4, tm);
    struct Tensor<float>  M4(d), M(dm);
    M4.initVal(1.0f);
    M.initVal(1.0f);
    int dee = 3;
    //int result[4] = { 1,3,0,2 };
    int result[4] = { 0,1,2,3 };
    int perm[M.Dim.rank];
    ASSERT_TRUE(scanPermuteMatchContractTensorfromSrcToDst(perm, M, M4, dee));
    for (int i = 0; i < M.Dim.rank; i++) printf(" %d[%d] ", i, perm[i]); printf(" first perm \n");
    ASSERT_EQ(0, memcmp(result, perm, sizeof(int) * M.Dim.rank));

    Tensor<float> tM;
    permutation p(M.Dim.rank, perm);
    permuteTensor(tM, M, p);

    ASSERT_FALSE(scanPermuteMatchContractTensorfromSrcToDst(perm, M, M4, 4));
    for (int i = 0; i < M.Dim.rank; i++) printf(" %d[%d] ", i, perm[i]); printf(": last perm \n");
    tM.Dim.print();
    int resultDim[] = { 2,3,4,7 };
    ASSERT_EQ(0, memcmp(resultDim, tM.Dim.dim, sizeof(int) * tM.Dim.rank));

}

TEST(scanPermuteMatchContractTensorfromSrcToDst2, floatest) {
    int t[] = { 3, 8, 2, 3, 4 };
    int tm[] = { 4, 2, 7, 3 };
    //int tm[] = { 2, 3,4,7 };
    struct dimension  d(5, t);
    struct dimension  dm(4, tm);
    struct Tensor<float>  M4(d), M(dm);
    M4.initVal(1.0f);
    M.initVal(1.0f);
    int dee = 3;
    int result[4] = { 1,3,0,2 };
    //int result[4] = { 0,1,2,3 };
    int perm[M.Dim.rank];
    ASSERT_TRUE(scanPermuteMatchContractTensorfromSrcToDst(perm, M, M4, dee));
    for (int i = 0; i < M.Dim.rank; i++) printf(" %d[%d] ", i, perm[i]); printf(" first perm \n");
    ASSERT_EQ(0, memcmp(result, perm, sizeof(int) * M.Dim.rank));

    Tensor<float> tM;
    permutation p(M.Dim.rank, perm);
    permuteTensor(tM, M, p);

    ASSERT_FALSE(scanPermuteMatchContractTensorfromSrcToDst(perm, M, M4, 4));
    for (int i = 0; i < M.Dim.rank; i++) printf(" %d[%d] ", i, perm[i]); printf(": last perm \n");
    tM.Dim.print();
    int resultDim[] = { 2,3,4,7 };
    ASSERT_EQ(0, memcmp(resultDim, tM.Dim.dim, sizeof(int) * tM.Dim.rank));



}


TEST(cudaTensorContractNestProd, floatTemp) {

    int t3[] = { 77, 8, 25 };

    int t4[] = { 8, 25, 52, 144 };
    struct dimension d3(3, t3), d4(4, t4), d;

    struct Tensor<float> M3(d3), M4(d4), M;
    M3.initVal(1.0f); // M3.print();
    M4.initVal(0.0f); // M4.print();

    int dee = 2;

    M4.Dim.print();

    try {
        //tensorContractnProd(M, M3, M4, dee);
        cudaTensorContractNestProd(M, M3, M4, dee);
    }
    catch (const std::invalid_argument& e) {
        printf("bye from test tensorContractnProd floatTemp invalid arg! deep: \n");
        dimension dM;
        extractDimNestingDepth(dM, d3, d4, dee);
        dM.print();
        ASSERT_TRUE(false);
    }

    int coord[M.Dim.rank];
    int coord3[M3.Dim.rank];
    int coord4[M4.Dim.rank];
    int idx3[M3.Dim.rank];
    int idx4[M4.Dim.rank];

    int l0, l1;
    l0 = M3.Dim.rank - dee;
    l1 = M4.Dim.rank - dee;
    int pcoord3[l0];
    int pcoord4[l1];
    int r[dee];
    //int rev[dee];

    int lin3, lin4, lin;
    d = M.Dim;
    d.print();

    Tensor<float> Msum(d);

    for (idx3[0] = 0; idx3[0] < d3.dim[0];idx3[0]++)
        for (idx4[2] = 0; idx4[2] < d4.dim[2];idx4[2]++)
            for (idx4[3] = 0; idx4[3] < d4.dim[3];idx4[3]++) {

                for (int i = 0; i < l0; i++) pcoord3[i] = idx3[i];
                for (int i = 0; i < l1; i++) pcoord4[i] = idx4[i + dee];
                concatArray(coord, pcoord3, pcoord4, 0, 0, l0, 0, l1);
                lin = d.CoordToLinear(coord);
                Msum.elements[lin] = 0.0f;
                //for (idx3[1] = 0; idx3[1] < d3.dim[1];idx3[1]++)
                //for (idx3[2] = 0; idx3[2] < d3.dim[2]; idx3[2]++)
                for (idx4[0] = 0; idx4[0] < d4.dim[0];idx4[0]++)
                    for (idx4[1] = 0; idx4[1] < d4.dim[1];idx4[1]++)
                    {
                        for (int i = 0; i < dee; i++) {
                            r[i] = idx4[i];
                            //rev[i] = idx4[dee - 1 - i];
                        }

                        //concatArray(coord3, pcoord3, rev, 0, 0, l0, 0, dee);
                        concatArray(coord3, pcoord3, r, 0, 0, l0, 0, dee);
                        concatArray(coord4, r, pcoord4, 0, 0, dee, 0, l1);
                        //printf("[");printArray(coord3, M3.Dim.rank); printf("]["); printArray(coord4, M4.Dim.rank);printf("] =*= ("); printArray(coord, Msum.Dim.rank); printf(")   |||");
                        lin3 = d3.CoordToLinear(coord3);
                        lin4 = d4.CoordToLinear(coord4);

                        Msum.elements[lin] += (M3.elements[lin3] * M4.elements[lin4]);
                        //printf("lin:%d lin3:%d lin4:%d el+:%f\n", lin, lin3, lin4, Msum.elements[lin]);
                    }
                ASSERT_FLOAT_EQ(Msum.elements[lin], M.elements[lin]) << " lin: " << lin << " Msumelem: " << Msum.elements[lin] << " Melem: " << M.elements[lin];
            }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
