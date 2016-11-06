#include <stdio.h>
#define UPPER 100

int main(){
  
  int dif = 0, i, j, tmp;

  for(i = 1; i <= UPPER; i++){
    tmp = 0;
    for(j = 1; j <= UPPER; j++){
      tmp += i*j;
    }
    dif += tmp - i*i;
  }
  
  printf("%d", dif);
  return 0;
}
