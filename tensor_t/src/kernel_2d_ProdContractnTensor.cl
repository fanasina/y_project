__kernel void prodContractnTensor2dLin_TYPE_FLOAT(long unsigned int dSubRank, long unsigned int dMRank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed 
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);

    size_t  k, n0_id, n1_id;
    size_t ind = i * dSubRank + j;
    Mx[ind] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = i * dMRank + k;
            n1_id = j + dSubRank * k;
            Mx[ind] += M0x[n0_id] * M1x[n1_id];
        }
}

__kernel void prodContractnTensor2dLin_TYPE_DOUBLE(long unsigned int dSubRank, long unsigned int dMRank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed 
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);

    size_t k, n0_id, n1_id;
    size_t ind = i * dSubRank + j;
    Mx[ind] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = i * dMRank + k;
            n1_id = j + dSubRank * k;
            Mx[ind] += M0x[n0_id] * M1x[n1_id];
        }
}

__kernel void prodContractnTensor2dLiniNotEndian_TYPE_FLOAT(long unsigned int dSubRank, long unsigned int dMRank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed 
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);

    size_t k, n0_id, n1_id;
    size_t ind = i + dSubRank * j;
    Mx[ind] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = i + dMRank * k;
            n1_id = j * dSubRank + k;
            Mx[ind] += M0x[n0_id] * M1x[n1_id];
        }
}

__kernel void prodContractnTensor2dLinNotEndian_TYPE_DOUBLE(long unsigned int dSubRank, long unsigned int dMRank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed 
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);

    size_t k, n0_id, n1_id;
    size_t ind = i + dSubRank * j;
    Mx[ind] = 0; 
        for (k = 0;  k < dMRank; k++) {
            n0_id = i + dMRank * k;
            n1_id = j * dSubRank + k;
            Mx[ind] += M0x[n0_id] * M1x[n1_id];
        }
}
