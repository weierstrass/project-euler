#include <stdio.h>
#define START 1
#define NUM_PRIMES 1000000

int main(){
  unsigned int i = 0 , j, t = 0, div, k = 0, p = 0, first = 1;
  unsigned int primes[NUM_PRIMES];

  for(i = 2; i <= -1; i++){
    if(p >= NUM_PRIMES) break;
    if(is_prime(i)){
      primes[p++] = i;
    }
  }


  for(i = 1; i < START; i++){
    t += i;
  }
  printf("t_start : %d\n", t);

  for(i = START; i < -1; i++){
    t += i;
    printf("%d: ", t);
    //number of divisors??
    //if( t % 2 != 0) continue;
    div = 2;
    k = 0;
    while(1){
      if(primes[k] >= t ) break;

      if(t % primes[k] == 0){
	first = 1;
	for(j = t / primes[k]; ; j /= primes[k]){
	  if(j == 0) break;
	  if(t % j != 0) break;
	  if(is_prime(j)) break;
	  printf("%d, ", j);
	  div++;
	  if(!first) div++;
	  first = 0;
	}
	printf("%d, ", primes[k]);
	div++;
      }
      k++;
    }
    printf(" (%d) \n", div);
    if(div > 500){
      printf("%d\n", t);
     return 0;
    }
  }
  
  return 0;
}
