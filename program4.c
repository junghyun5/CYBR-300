//Input, output, iterate, count, copy, size, manipulation, 2d, command line Input
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

char * getUserInput(char *);
int stringLength(char *);
int charCount(char *);
void putString(int,char,char*);
char * copyString(char *);
//fucntion prototype

int main(){
  printf("Yo!\n");
  char * First = getUserInput("Enter first name: ");
  printf("%s", First);
  int s1Length = stringLength(First);
  printf("Length = %d\n", s1Length);
  int count1 = charCount(First);
  printf("NumberL %d\n", count1);
  putString(1,'x',First);

  //deep vs Shallow
  char * name = getUserInput("Enter name: ");
  printf("Your name is %s\n", name);
  char * newName = name;

  printf("Name pointer = %p\n", name);
  printf("NewName pointer = %p\n", newName);
  newName[1] = 'p';
  printf("Name = %s\n", name);

  char * newName2 = copyString(name);
  printf("NewName2 = %s\n", newName2);
  name[0] = 'b';
  printf("NewName2 = %s\nName = %s\n", newName2, name);
}

char * getUserInput(char * prompt){
  char * UserInput;
  UserInput = malloc(SIZE * sizeof(char)); // If I wanna make array
  //null terminate
  UserInput[SIZE-1] = '\0';
  printf("%s",prompt);
  scanf("%s",UserInput);
  return UserInput;
}

int stringLength(char * input){
  int index = 0;
  while (input[index] != '\0'){
    index++;
  }
  return index;
}

char * copyString(char * toCopy){ //Deep copy function
  int len = stringLength(toCopy);
  char * temp;
  temp = malloc(len * sizeof(char));
  temp[len - 1] = '\0';
  int i;
  for(i = 0; i<len; i++){
    temp[i] = toCopy[i];
  }
  return temp;
}

int charCount(char * string){
  char * check = getUserInput("Enter a char: ");
  int len = stringLength(string);
  //GEt the length of the input string
  int i;
  int count = 0;
  for (i=0; i<len; i++){
    printf("%c\n", string[i]);
    if (string[i] == check[0]){
      //If the current character matches the one entered by the user
      count++; //Increment the count
    }
  }
  return count;
}
//Deep copy : we make a new memory. so the other address.
//Shallow Copy : we use same address. so, if we change one stuff, the other are changed, too.
void putString(int index, char letter, char * string){
  string[index] = letter;
}
