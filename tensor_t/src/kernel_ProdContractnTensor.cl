__kernel void prodContractnTensorLin_TYPE_FLOAT(long unsigned int dSubRank, long unsigned int dMRank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed 
    size_t i = get_global_id(0);
    size_t k, a0_id, a1_id, n0_id, n1_id;
    a0_id = i / dSubRank; 
    a1_id = i % dSubRank; 
    Mx[i] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = a0_id * dMRank + k;
            n1_id = a1_id + dSubRank * k;
            Mx[i] += M0x[n0_id] * M1x[n1_id];
        }
}

__kernel void prodContractnTensorLin_TYPE_DOUBLE(long unsigned int dSubRank, long unsigned int dMRank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed 
    size_t i = get_global_id(0);
    size_t k, a0_id, a1_id, n0_id, n1_id;
    a0_id = i / dSubRank; 
    a1_id = i % dSubRank; 
    Mx[i] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = a0_id * dMRank + k;
            n1_id = a1_id + dSubRank * k;
            Mx[i] += M0x[n0_id] * M1x[n1_id];
        }
}





__kernel void prodContractnTensorLinNotEndian_TYPE_FLOAT(long unsigned int dSubRank, long unsigned int dMRank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed 
    size_t i = get_global_id(0);
    size_t k, a0_id, a1_id, n0_id, n1_id;
    a0_id = i % dSubRank; 
    a1_id = i / dSubRank; 
    Mx[i] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = a0_id + dSubRank * k;
            n1_id = a1_id * dMRank + k;
            Mx[i] += M0x[n0_id] * M1x[n1_id];
        }
}

__kernel void prodContractnTensorLinNotEndian_TYPE_DOUBLE(long unsigned int dSubRank, long unsigned int dMRank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed 
    size_t i = get_global_id(0);
    size_t k, a0_id, a1_id, n0_id, n1_id;
    a0_id = i % dSubRank; 
    a1_id = i / dSubRank; 
    Mx[i] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = a0_id + dSubRank * k;
            n1_id = a1_id * dMRank + k;
            Mx[i] += M0x[n0_id] * M1x[n1_id];
        }
}
