#ifndef __COORDINATE_C__H__
#define __COORDINATE_C__H__

#include "dimension/dimension.h"


struct coordinate
{
  size_t lin_coo;
  unsigned int *coord;
  struct dimension *dimension;
};

typedef coordinate coordinate;

void LinearToCoord(struct coordinate *coor);
void CoordToLinear(struct coordinate *coor);



#endif
