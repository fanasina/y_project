#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "fmock/fmock.h"


//#include "permutation_t/permutation_t.h"
#include "dimension_t/dimension_t.h"

TEST(dimension0){

  dimension *D = create_dim(5);

  EXPECT_EQ(D->size,5);

}
TEST(rank){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);
  EXPECT_EQ(D->rank, 180);

}
TEST(SubDim){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  dimension *d_head2 = sub_minus_dim_head(D,2);
  
  
  EXPECT_EQ(d_head2->rank, 2*3);

  dimension *d_tail2 = sub_minus_dim_tail(D,2);
  EXPECT_EQ(d_tail2->rank, 5*6);

}

TEST(SubDim){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;


  dimension *d_head2 = sub_minus_dim_head(D,2);
  
  
  EXPECT_EQ(d_head2->rank, 2*3);

  dimension *d_tail2 = sub_minus_dim_tail(D,2);
  EXPECT_EQ(d_tail2->rank, 5*6);

}

TEST(Coord_linear){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);

  size_t line=255;
  size_t *coord = CoordFromLin(line,D);

  for(size_t i=0; i<D->size; ++i){
    LOG("coo[%ld]=%ld\n",i,coord[i]);
  }
  
  EXPECT_EQ(line, LineFromCoord(coord, D));  
}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
