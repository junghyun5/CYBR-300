#include <stdio.h>

int main(){
  printf("Hello\n");

  int a = 5;
  int *aAddress = &a;
  printf("a = %d\na Address = %p\n", a, aAddress);
  //Format string, any variables we'll be using
  //To put variables in the format string, format specifiers
  //%d - int, %f - float, %c - char
  //%x - hex, %p - Pointer, %s - string
  int *newAddress = aAddress + 1;
  printf("new = %p\n",newAddress);
  * (newAddress+1) = 90; //why it is not working?
  printf("New var = %d\n", * newAddress+1);

  //Loop Structures
  int i;
  for(i=15; i > 0; i--){
    //*(newAddress+1) = 0;
    printf("Value = %x\n", *(newAddress+i));
    // int**, char*, float*
  }
  int count = 0;
  while (count < 10){ //test condition
    count += 2;
    printf("%d\n", count);
  }

  int good = 0;
  count = 0;
  while(good == 0){
    count++;
    printf("val --> %d\n", count);
    if (count > 10){
      good = 1;
    } else if (count%2 == 0){
      printf("Even\n");
    } else{
      printf("Odd\n");
    }
  }
}
