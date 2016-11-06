#include <stdio.h>
#include <math.h>

int main(){
  long sum = 2;
  int p;

  for(p = 3; p < 2000000; p += 2){
    if(is_prime(p)){
      sum += p;
    }
  }

  printf("%ld", sum);
  return 0;
}

int is_prime(long p){
  long t;

  if(p == 2) return 1;
  if((p % 2) == 0) return 0;

  for(t = 3; t <= sqrt(p); t += 2 ){
    if((p % t) == 0)
      return 0;
  }
  
  return 1;
}
