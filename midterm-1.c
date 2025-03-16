#include <stdio.h>
#include <stdlib.h>

void countNum (int);

main(){
  countNum(10);
}

void countNum(int num){
  for(int i = 0; i <= num; i++){
    printf("%d\n",i);
  }
}
