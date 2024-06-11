#include "learn_to_drive.h"


float reLU(float x){
  if(x>0) return x;
  return 0;
}

float d_reLU(float x){
  if (x>0) return 1;
  return 0;
}

float L2(float t, float o){
  return (o - t) * (o - t)/2;
}

float D_L2(float t, float o){
  return (o - t);
}




