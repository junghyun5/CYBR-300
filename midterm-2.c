#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define NAME "JUNGHYUN"

struct account{
  char * name;
  int amount;
};

void printStruct(struct account);

main(){
  struct account a1;
  a1.name = NAME;
  a1.amount = SIZE;
  printStruct(a1);
}

void printStruct(struct account input){
  printf("Name: %s\n", input.name);
  printf("Amount: %d\n", input.amount);
}
