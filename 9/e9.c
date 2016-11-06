#include <stdio.h>
#include <math.h>

int main(){
  int a, b, c;

  for(a = 1; a <= 1000; a++){
    for(b = a; b <= 1000; b++){
      c = sqrt(a*a + b*b);
      if(1000  == a + b + c && a*a + b*b == c*c){
	printf("a: %d, b: %d, c: %d, prod: %d\n",a, b, c,  a * b * c);
	//return 0;
      }
    }
  }  
  return 0;
}
