__kernel void prodTensor2dLin_TYPE_FLOAT(long unsigned int M1rank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);
  
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t k = i * M1rank+ j;
    Mx[k] = M0x[i] * M1x[j]; 
}

__kernel void prodTensori2dLin_TYPE_DOUBLE(long unsigned int M1rank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);
  
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t k = i * M1rank+ j;
    Mx[k] = M0x[i] * M1x[j]; 

}

__kernel void prodTensor2dLinNotEndian_TYPE_FLOAT(long unsigned int M0rank, __global const float *M0x , __global const float *M1x, __global float *Mx ){

    //Get the index of the current element to be processed
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);
  
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t k = i + M0rank * j;
    Mx[k] = M0x[i] * M1x[j]; 
}

__kernel void prodTensori2dLinNotEndian_TYPE_DOUBLE(long unsigned int M0rank, __global const double *M0x , __global const double *M1x, __global double *Mx ){

    //Get the index of the current element to be processed
    size_t i = get_group_id(0)*get_local_size(0) + get_local_id(0);
    size_t j = get_group_id(1)*get_local_size(1) + get_local_id(1);
  
    //size_t i = get_global_id(0);
    //size_t j = get_global_id(1);
    
    size_t k = i + M0rank * j;
    Mx[k] = M0x[i] * M1x[j]; 

}






