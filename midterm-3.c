#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

char* getUserInput(char*, char*);

main(){
  char * format = "%19s";
  char * prompt = "Please enter your first name: ";
  char* ui = getUserInput(format, prompt);
  printf("%s",ui);
}

char* getUserInput(char * format, char * prompt){
  char * ui = malloc(SIZE * sizeof(char));
  ui[SIZE - 1] = '\0';
  printf("%s", prompt);
  scanf(format,ui);
  return ui;
}
