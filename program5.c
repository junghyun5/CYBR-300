#include <stdio.h>
#include <stdlib.h>

#define SIZE 2
#define STRINGSIZE 20

char * getUserInput(char *);
void getUserAge(struct User);

struct User {
  char * firstName;
  char * lastName;
  int age;
};



int main(int argc, char ** argz){
  //struchture
  struct User u1;
  u1.firstName = "Adam";
  u1.lastName = "Spanier";
  u1.age = 245;

  printf("First Name: %s\n", u1.firstName);
  printf("Last Name: %s\n", u1.lastName);
  printf("Age: %d\n", u1.age);

  struct User * users;

  users = malloc(SIZE * sizeof(struct User));
  //not use null terminate. Because it is messy.

  //a list of 20 possible users
  int i;
  for(i=0; i<SIZE; i++){
    users[i].firstName = getUserInput("Enter first name: ");
    users[i].lastName = getUserInput("Enter last name: ");
    getUserAge(users[i]);
  }
}

char * getUserInput(char * prompt){
  char * userInput;
  userInput = malloc(STRINGSIZE * sizeof(char));
  //naver forget the null terminate
  userInput[STRINGSIZE - 1] = '\0';
  printf("%s", prompt);
  scanf("%s", userInput);
  return userInput;
}

void getUserAge(struct User u){
  printf("Enter your age: ");
  scanf("%d", &u.age);
}
