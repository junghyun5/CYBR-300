#include <stdio.h>
//Macros
//Structs
//Prototypes

int runningSum(int);

int main(){
  int sum = runningSum(10);
  printf("%d\n",sum);

  int a;
  printf("Enter a number\n");
  scanf("%d", &a); //don't write \n
  printf("a = %d\n", a);

  int good = 0;
  int inputCount = 0;
  while(good == 0 && inputCount < 3){
    printf("Enter a number less than 10: ");
    scanf("%d", &a);
    if (a < 10){
      good = 1;
    } else{
      printf("Read the instruction!\n");
    }
    inputCount ++;
    //and : &&
    //or: ||
    //Not: !=

    //fucntion : return type name(args){}
  }
}

//Sum numbers up to num
int runningSum(int num){
  int accum = 0;
  int i;
  for(i = 0; i<num; i++ ){
    accum += i;
  }
  return accum;
}

//char > 1byte/ 8bits
//int > 4bytes/ 32 8bits
//float > 8bytes/ 64bits
//0x0(base address) + (size(data type) * offset(Index))
// int *arr;
// arr = malloc(5*sizeof(int));
//null termination
