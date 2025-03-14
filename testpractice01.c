#include <stdio.h>
#include <stdlib.h>

int getNum(char *);
void printNum(int);

int main(){

  int num = getNum("Enter number limit here: ");
  printNum(num);
}

int getNum(char * prompt){
  int num;
  printf("%s", prompt);
  scanf("%d", &num);
  return num;
}

void printNum(int num){
  for(int i = 0; i < num; i++){
    printf("%d\n", i);
  }
}
