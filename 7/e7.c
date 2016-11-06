#include <stdio.h>
#include <math.h>

int main(){
  unsigned long p;
  int n = 1;
  for(p = 3; p < -1; p += 2){
    if(is_prime(p)){
      n++;
    }
    if(n == 10001){
      printf("%ld\n", p);
      return 0;
    }
  }
  
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
