#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

struct User{
  char * firstName;
  char * lastName;
};

int getNum(char *);
char * getString(char *);
struct User * fillList(int);
void printList(struct User *, int);

int main(){

}

int getNum(char * prompt){
  int num;
  printf("%s", prompt);
  scanf("%d", &num);
  return num;
}

char * getString(char * prompt){
  char * stringInput = malloc(SIZE * sizeof(char));
  stringInput[SIZE - 1] = '\0';
  printf("%s", prompt);
  scanf("%s", stringInput);
  return stringInput;
}

struct User * fillList(int num){
  struct User * users = malloc(num * sizeof(struct User));
  for(int i = 0; i <num; i++){
    users.[i].firstName = getString("Enter first name: ");
    users.[i].lastName = getString("Enter last name: ");
  }
  return users;
}

void printList(struct User * users, int num){
  for (int i = 0; i < num; i ++){
    printf("Name: %s %s\n", users[i].firstName, users[i].lastName);
  }
}
