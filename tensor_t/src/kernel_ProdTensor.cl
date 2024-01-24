__kernel void prodTensorLin_TYPE_FLOAT(long unsigned int M1rank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed
    size_t k = get_global_id(0);
    size_t i = k / M1rank;
    size_t j = k % M1rank;
    Mx[k] = M0x[i] * M1x[j]; 
}

__kernel void prodTensorLin_TYPE_DOUBLE(long unsigned int M1rank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed
    size_t k = get_global_id(0);
    size_t i = k / M1rank;
    size_t j = k % M1rank;
    Mx[k] = M0x[i] * M1x[j]; 
}




