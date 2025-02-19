#include <stdio.h>
#include <stdlib.h>
//Include statement
#define WELCOME "\nWelcome to the Process Manager\n"
#define END "\nEnding Process Manager\n\n"
#define SIZE 10
// #Define statements
void PrintWelcome ();
struct process MakeProcess ();
int getID ();
char * getName ();
void printProcess (struct process);
void printEnd ();
void freeProc(struct process);
//Funchtion prototypes


struct process{
  int id;
  char * name;
};
//Structure statements

int main(){
  PrintWelcome();
  struct process p1;
  p1 = MakeProcess();
  printProcess(p1);
  freeProc(p1);
  printEnd();
  return 0;
}
//Main method

void PrintWelcome (void){
  printf("%s",WELCOME);
}

struct process MakeProcess(){
  printf("\n******GET INPUT******\n\n");
  struct process p1;
  p1.id = getID();
  p1.name = getName();
  return p1;
}

int getID(){
  int num;
  printf("Enter ID: ");
  scanf("%d", &num);
  return num;
}

char * getName(){
  char * temp = malloc(SIZE * sizeof(char));
  temp[SIZE - 1] = '\0';
  printf("Enter Name: ");
  scanf("%s", temp);
  return temp;
}

void printProcess (struct process p1){
  printf("\n******PRINT OUT******\n\n");
  printf("Process ID: %d\n",p1.id);
  printf("Process Name: %s\n", p1.name);

}

void printEnd (void){
  printf("%s", END);
}

void freeProc(struct process p1){
  free(p1.name);
}
//Fucntion defined in same order as function prototypes
