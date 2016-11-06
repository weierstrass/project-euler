#include <stdio.h>
#include <math.h>

int main(){
  int i, len = 0;
  for(i = 1; i <= 1000; i++){
    len += get_alphabetic_length(i);
  }
  printf("\ntotal length: %d\n", len);
  return 0;
}

int get_alphabetic_length(int n){
  int i, k, exp, len = 0, add_and = 0;
  printf("n: %d, len: ", n);
  if(n == 11 || n == 12) return 6;
  if(n == 15 || n == 16) return 7;
  if(n == 13 || n == 14 || n == 18 || n == 19) return 8;
  if(n == 17) return 9;

  if(n == 111 || n == 112) return 6+7+3+3;
  if(n == 115 || n == 116) return 7+7+3+3;
  if(n == 113 || n == 114 || n == 118 || n == 119) return 8+7+3+3;
  if(n == 117) return 9+7+3+3;

  if(n == 211 || n == 212) return 6+7+3+3;
  if(n == 215 || n == 216) return 7+7+3+3;
  if(n == 213 || n == 214 || n == 218 || n == 219) return 8+7+3+3;
  if(n == 217) return 9+7+3+3;

  if(n == 311 || n == 312) return 6+7+3+5;
  if(n == 315 || n == 316) return 7+7+3+5;
  if(n == 313 || n == 314 || n == 318 || n == 319) return 8+7+3+5;
  if(n == 317) return 9+7+3+5;

  if(n == 411 || n == 412) return 6+7+3+4;
  if(n == 415 || n == 416) return 7+7+3+4;
  if(n == 413 || n == 414 || n == 418 || n == 419) return 8+7+3+4;
  if(n == 417) return 9+7+3+4;

  if(n == 511 || n == 512) return 6+7+3+4;
  if(n == 515 || n == 516) return 7+7+3+4;
  if(n == 513 || n == 514 || n == 518 || n == 519) return 8+7+3+4;
  if(n == 517) return 9+7+3+4;

  if(n == 611 || n == 612) return 6+7+3+3;
  if(n == 615 || n == 616) return 7+7+3+3;
  if(n == 613 || n == 614 || n == 618 || n == 619) return 8+7+3+3;
  if(n == 617) return 9+7+3+3;

  if(n == 711 || n == 712) return 6+7+3+5;
  if(n == 715 || n == 716) return 7+7+3+5;
  if(n == 713 || n == 714 || n == 718 || n == 719) return 8+7+3+5;
  if(n == 717) return 9+7+3+5;

  if(n == 811 || n == 812) return 6+7+3+5;
  if(n == 815 || n == 816) return 7+7+3+5;
  if(n == 813 || n == 814 || n == 818 || n == 819) return 8+7+3+5;
  if(n == 817) return 9+7+3+5;

  if(n == 911 || n == 912) return 6+7+3+4;
  if(n == 915 || n == 916) return 7+7+3+4;
  if(n == 913 || n == 914 || n == 918 || n == 919) return 8+7+3+4;
  if(n == 917) return 9+7+3+4;

  for(i = 0; ; i++){
    exp = pow(10, i);
    if(exp > n) break;
    k = n % (int)pow(10, i+1) - n % exp;
    if(k < 100 && k > 0) add_and = 1;
    //printf("n: %d\n", k);
    if(k == 1 || k == 2 || k == 6 || k == 10) len += 3; //3
    if(k == 4 || k == 5 || k == 9) len += 4; //4
    if(k == 3 || k == 7 || k == 8 || k == 40 ||\
       k == 50 || k == 60) len += 5; //5
    if(k == 20 || k == 30 || k == 80 || k == 90) len += 6; // 6
    if(k == 70) len += 7;// 7

    if(k == 100 || k == 200 || k == 600) len += 10; //3
    if(k == 400 || k == 500 || k == 900) len += 11; //4
    if(k == 300 || k == 700 || k == 800) len += 12;

    if(k == 1000) len += 11;
    printf(" %d, ", len);
  }
  if(n > 100 && add_and){
    len += 3;
    printf(" adding and");
  }
  printf(", final len: %d \n", len);
  return len;
}

int get_length(int n){
  if(1);
}
