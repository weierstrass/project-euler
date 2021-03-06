#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_matrix(char *ret, char *file_name, int chars_to_read );
int is_prime(long p);


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

/*
 * delimiter : character that separates entries
 */
void read_matrix(char *ret, char *file_name, int chars_to_read ){
  FILE *fs;
  fs = fopen(file_name, "r");
  char c;
  int i = 0;

  if(fs == NULL){
    perror("Error when opening file");
    return;
  }

  
  for(i = 0; i < chars_to_read; i++){
    c = fgetc(fs);
    
    if(c == EOF) break;
    ret[i] = c;
    //printf("%c\n", c);
  }
  
}

void text2numeric_matrix(int *ret, char *data, int data_len, int elen){
  int i, j = 0;
  for(i = 0; i < data_len; i += elen + 1 ){
    printf("%c%c\n", data[i], data[i+1]);
    for(j = elen - 1; j >= 0; j--){
      
    } 
  }

}

int char2int(char c){
  return (int) c - 0x30;
}
