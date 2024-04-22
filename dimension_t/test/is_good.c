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

  free_dimension(D);
}
TEST(rank){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);
  EXPECT_EQ(D->rank, 180);

  free_dimension(D);
}
TEST(SplitDim){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;
  
  updateRankDim(D);
  printDebug_dimension(D," D root");  

  dimension *d_part1 = NULL,*d_part2=NULL;

 split_dim_part(D, &d_part1, &d_part2, 1, 2); 

  printDebug_dimension(d_part1," part1 from Root");  
  printDebug_dimension(d_part2," part2 from Root");  

  dimension *ad;

  add_dimension(&ad,d_part1, d_part2);
  printDebug_dimension(D," D root");  
  printDebug_dimension(ad," ad ");  


  free_dimension(D);
  free_dimension(ad);
  free(d_part1);
  free(d_part2);
}

TEST(SplitDim_2){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;
  
  updateRankDim(D);
  printDebug_dimension(D," D root");  

  dimension *d_part1 = NULL,*d_part2=NULL;

 split_dim_part(D, &d_part1, &d_part2, 3, 2); 

  printDebug_dimension(d_part1," part1 from Root");  
  printDebug_dimension(d_part2," part2 from Root");  

  dimension *ad;

  add_dimension(&ad,d_part1, d_part2);
  printDebug_dimension(D," D root");  
  printDebug_dimension(ad," ad ");  


  free_dimension(D);
  free_dimension(ad);
  free(d_part1);
  free(d_part2);
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

  free_dimension(D);
  free(d_tail2);
  free(d_head2);
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

  free_dimension(D);
  free(d_tail2);
  free(d_head2);
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
  free_dimension(D);
  free(coord);
}

TEST(signedCoord_linear){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);

  long line=-255;
  long *coord = signedCoordFromLin(line,D);

  for(size_t i=0; i<D->size; ++i){
    LOG("coo[%ld]=%ld\n",i,coord[i]);
  }
  
  EXPECT_EQ(line, signedLineFromCoord(coord, D));  
  free_dimension(D);
  free(coord);
}

TEST(signedCoord_linearSuccessif){
  dimension *D=create_dim(3);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=2;

  updateRankDim(D);

  for(long line=-4; line < 4; ++line){
    long *coord = signedCoordFromLin(line,D);

    for(size_t i=0; i<D->size; ++i){
      LOG("coo[%ld]=%ld\n",i,coord[i]);
    }
  
    EXPECT_EQ(line, signedLineFromCoord(coord, D));  
    free(coord);
  }
    free_dimension(D);
}

TEST(sprint_dim){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);

  char *dimSTR =NULL;
  size_t nb=sprint_dimension(&dimSTR, D);

  LOG(" nb char : %ld\n, dim print:\n%s\n",nb, dimSTR);

  free_dimension(D);
  free(dimSTR);
}

TEST(incrment_dim){
  endian=false;
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);

  char *dimSTR =NULL;
  size_t nb=sprint_dimension(&dimSTR, D);

  LOG(" nb char : %ld\n, dim print:\n%s\n",nb, dimSTR);

  increment_dim_var(D);

  nb=sprint_dimension(&dimSTR, D);

  LOG(" nb char : %ld\n, dim print increment:\n%s\n",nb, dimSTR);

  free_dimension(D);
  free(dimSTR);
}


TEST(list_perm_in_dim){
  list_perm_in_dim *l_p=NULL;

  for(size_t i=1;i<5; ++i){
    append_in_list_perm(&l_p, i);
  }

  dimension *dim=create_dim_from_list_perm(l_p);

  printDebug_dimension(dim, "from l_p"); 
}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
