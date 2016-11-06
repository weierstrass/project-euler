#include <stdio.h>
#include <stdlib.h>


int main(){
  int length = 20 * (20 * 2 + 20), i;
  char *data = (char *)malloc(length);
  char *name = {"in.txt"};
  int *matrix = (int *)malloc((20 * 20) * sizeof(int));
  for(i = 0; i < 20*20; i++) matrix[i] = 0;

  read_matrix(data, &name[0], length);
  text2numeric_matrix(matrix, data,  length, 2);
  

  printf("exiting\n");
  return 0;
}
