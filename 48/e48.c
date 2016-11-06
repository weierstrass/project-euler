
#include <stdio.h>
#include <math.h>

long last_4_pow(int b, int e);

int main(){

  long res = 0;
  int i;
  for(i = 1; i < 1000; i++){//intentionally < 
    res += last_4_pow(i, i);
    res %= 10000000000;
  }

  printf("result:  %ld", res);
  return 0;
}

long last_4_pow(int b, int e){
  long ret = 1;
  int i;
  for(i = 1; i <= e; i++){
    ret *= b;
    ret %= 10000000000;
  }
  printf("b : %d l4: %ld\n", b, ret);
  return ret;
}
