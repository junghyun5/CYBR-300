#include <stdio.h>
#include <stdlib.h>

char * getUserString(char *);
void printUserString(char*);

int main(){
  char * value = getUserString("Enter First Name: ");
  printUserString(value);
}

char * getUserString(char * prompt){
  printf("%s", prompt);
  char* userInput = malloc(STR_SIZE * sizeof(char));
  userInput[STR_SIZE - 1] = '\0';
  scanf("%s", userInput);
  return userInput;
}

void printUserString(char* str){
  printf("%s\n", str);
}
