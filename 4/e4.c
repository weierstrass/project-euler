#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(){
  int i, j;
  i = 39;
  j = 565;
  int max_pal = 0;
  for(i = 1; i < 1000; i++){
    for(j = i; j < 1000; j++){
      if(is_palindrome(i * j) && i * j > max_pal){
	max_pal = i * j;
      }
    }
  }
  printf("%d", max_pal);
  return 0;
}

int is_palindrome(int n){
  char buf[10];
  int end , beg  = 0;
  sprintf(buf, "%d", n);

  for(end = 9; end > beg; end--){
    if(buf[end] != '\0'){
      // printf("end : %d , %c\n", end, buf[beg]);
      if(buf[beg] != buf[end]){
	return FALSE;
      }
      beg++;
    }
  }
  //printf("%s", buf);
  
  return TRUE;

}
