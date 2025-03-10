#include <stdio.h>
#include <stdlib.h>

//define
#define WELCOME "Welcome to the Assignment 1! This program will create programs for the job queue!\n\n"
#define START "****** PROGRAM START ******\n\n"
#define PRINT "\n\n****** BEGIN PRINTOUT ******\n"
#define FREE "\n\n****** BEGIN FREE ******"
#define SIZE 20
#define INITSTATE 0

//define
void printWelcome();
int getNumProcs();
int clearStdin();
void addInt(int *, char *);
char * addString(char *);
void changeState(int, struct process *);
void setStart(int, struct process *);
void addProcs(int, struct process *);
char * getState(int);
void printProcs(struct process *);
void freeMemory (struct process *);


//struct
struct process{
  int pid;
  int state;
  int size;
  int start;
  char * description;
};

int main(){
  int num;
  struct process * jobQueue = malloc((SIZE + 1) * sizeof(struct process)); // size check please.
  jobQueue[SIZE].pid = -1;
  printWelcome();
  num = getNumProcs();
  addProcs(num, jobQueue);
  printProcs(jobQueue);
  freeMemory(jobQueue);
  return 0;

}

void printWelcome(){
  printf("%s",WELCOME);
  printf("%s",START);
}

int getNumProcs(){
  int num;
  char term;
  printf("Please enter a number of processes you wolud like to add: ");
  for(;;){
    if(scanf("%d%c",&num,&term) != 2 || term != '\n'){
      printf("Please enter the integer! Try again: ");
      clearStdin();
    } else{
      break;
    }
  }
  return num;
}


int clearStdin(){
  int c = 0;
  while(('\n' != (c=fgetc(stdin))) && (c != EOF)){
    if(c==EOF) break;
  }
  return 0;
}

void addInt(int * num, char * prompt){
  printf("\t%s",prompt);
  scanf("%d",num);
}

char * addString(char * prompt){
  char * str = (char *)malloc(SIZE * sizeof(char));
  str[SIZE -  1] = '\0';
  printf("\t%s",prompt);
  scanf("%s",str);
  return str;
}

void changeState (int num, struct process * jobQueue){
  for(int i=0; i<num; i++){
    jobQueue[i].state = 1;
  }
}

void setStart(int num, struct process * jobQueue){
  if(num == 0){
    jobQueue[num].start = 0;
  }else{
    jobQueue[num].start = jobQueue[num - 1].start + jobQueue[num-1].size +1;
  }
}

void addProcs(int loopNum, struct process * jobQueue){
  for(int i = 0; i < loopNum; i++){
    printf("\n\n****** New Process %d ******\n\n", i+1);
    jobQueue[i].pid = i + 1;
    jobQueue[i].state = INITSTATE;
    changeState(i, jobQueue);
    addInt(&jobQueue[i].size, "Enter process size: ");
    setStart(i, jobQueue);
    jobQueue[i].description = addString("Enter Description: ");
  }
  jobQueue[loopNum].pid = -1;
}

char * getState(int state){
  if (state == 0){
    return "Start";
  } else if (state == 1){
    return "Ready";
  } else {
    return "Error";
  }
}

void printProcs(struct process * jobQueue){
  int num = -2;
  int count = 0;
  printf("%s\n",PRINT);
  while (num != -1 && count < SIZE){
    num = jobQueue[count].pid;
    if(num != -1){
      printf("\n****** Process Number %d Summary ******\n\n", count+1);
      printf("\tProcess ID: %d\n",jobQueue[count].pid);
      printf("\tProcess State: %s\n", getState(jobQueue[count].state));
      printf("\tProcess Start: %d\n", jobQueue[count].start);
      printf("\tProcess Size: %d\n", jobQueue[count].size);
      printf("\tProcess Description: %s\n", jobQueue[count].description);
    }
    count++;
  }
}
void freeMemory (struct process * jobQueue){
  int num = -2;
  int count = 0;
  printf("%s\n",FREE);
  while(num != -1 && count < SIZE){
    num = jobQueue[count].pid;
    if (num != -1){
      free(jobQueue[count].description);
    }
    count++;
  }
  free(jobQueue);
}
