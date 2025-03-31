#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
//NO ;
char * getUserInput(char *);
void loopString(char *);

int main(){
  char *arr;
  arr = malloc(5* sizeof(char)); //null termination '\0'
  arr[4] = '\0';

  printf("Hello world\n");
  char * first = getUserInput("Enter First Name: ");
  char * middle = getUserInput("Enter Middle Name: ");
  char * last = getUserInput("Enter Last Name: ");
  printf("%s %s %s",first, middle, last);
  //Create a function that prints a prompt and takes user input, passes it back,
  loopString(first);
}

char *getUserInput(char * prompt){
  char * UserInput;
  UserInput = malloc(SIZE * sizeof(char));
  UserInput[SIZE-1] = '\0';
  printf("%s", prompt);
  scanf("%s", UserInput);
  return UserInput;
}

void loopString(char *stringToLoop){
  int index = 2;
  printf("%d = %c\n", index, stringToLoop[index]);
}
