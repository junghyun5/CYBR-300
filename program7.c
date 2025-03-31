#include <stdio.h>
#include <stdlib.h>

#define NAME_SIZE 10
//2D array

char * getName();
char ** getNameList(int);
int getSize();
void printNameList(Char **);
int twodStringSize(char **);

int main(){
  //list of students in class
  // char * name1 = getName();
  // printf("Name : %s\n", name1);
  // int size = getSize();
  // printf("Size: %d\n", size);
  char ** nameList = getNameList(getSize());
  printNAmeList(nameList);
  int size = twodStringSize(nameList);
  printf("List Size: %d\n", size);
}

char * getName(){
  printf("Enter a name: ");
  char * name = malloc(NAME_SIZE * sizeof(char));
  name[NAME_SIZE - 1] = '\0';
  scanf("%s", name);
}

int getSize(){
  printf("Enter the size of your name list: ");
  int ui;
  scanf("%d", &&ui);
  return ui;
}

char ** getNameList(int size){
  char ** nameList = malloc(size * sizeof(char*));
  int i;
  for(i=0;i<size; i++){
    nameList[i] = getName();
  }
    nameList[i] = NULL;
    return nameList;
  //every level Must BE Malloced!!!!
}

void printNAmeList(char ** nameList){
  int counter = 0;
  while(nameList[count] != NULL){
    printf("%s\n", nameList[counter]);
  }
}

int twodStringSize(cahr ** list){
  int counter = 0;
  while(list[counter != NULL]){
    counter++;
  }
  return counter;
}
