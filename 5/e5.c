#include <stdio.h>

int main(){
  unsigned long t;
  int mod;

  for(t = 20; t < -1; t += 20){
    for(mod = 3; mod < 20; mod++){
      if((t % mod) != 0) {
	break;
      }else if(mod == 19){
	printf("%ld", t);
	return 0;
      }
    }
    //printf("%ld\n", t);
  } 

  return 0;
}
