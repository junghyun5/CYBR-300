#include <stdio.h>
#include <stdlib.h>

int getUserInput(char *);
float calcAvg(int);
void farewell();


int main(){
  printf("\nWelcome to Lab 2!\n\n");

  int a;
  a = getUserInput("Please enter a number from 1 to 10: ");
  printf("\nYou chose the value: %d\n", a);

  float b = calcAvg(a);
  printf("The mean is: %f\n",b);
  farewell();
}

int getUserInput(char * prompt){
  int UserInput;
  printf("%s", prompt);
  scanf("%d", &UserInput);
  return UserInput;
}

float calcAvg(int userInput){
  int i;
  float accumulator = 0.0;
  for(i = 0; i <userInput; i++){
    accumulator += i;
  }
  float mean = accumulator / userInput;
  return mean;
}

void farewell(){
  printf("\nFarewell! Thank you for using this program!\n\n");
}
