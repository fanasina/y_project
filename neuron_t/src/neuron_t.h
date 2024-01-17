#ifndef __NEURON_T_C__H
#define __NEURON_T_C__H

#include <stdlib.h>

#include "tools_t/tools_t.h"
#include "permutation_t/permutation_t.h"

typedef PERMUTATION_TYPE_FLOAT vectf; 

struct neuron {
  size_t id;
  struct vectf *x; /* input */
  struct vectf *w_in; /* weight link in */
  struct vectf *w_out; /* weight link out */
  struct vectf *d; /* delta */
};

struct func {
  float (*func_act)(struct neuron *nr); /* function activation */
  float (*d_func_act)(struct neuron *nr); /* derivate func act */
  float (*func_agreg)(struct neuron *nr); /* function aggregation */
};

#if 0

#define GENERATE_NEURON(type)                       \
  struct NEURON_##type{                                      \
    type *x;                                                      \
    type *w;    \
  };                                                              \
  typedef struct NEURON_##type NEURON_##type;           \
  NEURON_##type * CREATE_NEURON_##type(size_t id/*TYPE_##type*/);    \
  bool IS_NEURON_##type(NEURON_##type *st);             \

GENERATE_NEURON(TYPE_FLOAT)
GENERATE_NEURON(TYPE_DOUBLE)

#endif

#endif /*__NEURON_T_C__H*/
