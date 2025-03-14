#include <stdio>
#include<stdlib>

#define SIZE 20

char * getString(char *);

int main(){
  char * firstName = getString("Enter the first name: ");
  char * lastName = getString("Enter the last name: ");
  printf("Name entered: %s %%s\n", firstName, lastName);
}

char * getString(char * prompt){
  char * stringInput = malloc(SIZE * sizeof(char));
  stringInput[SIZE - 1] = '\0';
  printf("%s", prompt);
  scanf("%s", stringInput);
  return stringInput;
}
