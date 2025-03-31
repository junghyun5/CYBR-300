#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 25

struct process{
  int pid;
};

struct semiphore{
  int val;
  struct process *list;
};

void wait(struct semiphore *);
void signals(struct semiphore *);
struct semiphore * initSemiphore(int);
struct process * jobList(int);

int main(){
  //printf("test");
  struct semiphore * S = initSemiphore(5);
  struct process * list = jobList(10);
  printf("process id: %d\n", list[0].pid);
  // printf("Val: %d\n", S->val);
  // wait(S);
  // printf("Val: %d\n", S->val);
  // wait(S);
  // wait(S);
  // wait(S);
  // wait(S);
  // printf("Val: %d\n", S->val);
  // signal(S);
  // printf("Val: %d\n", S->val);
}

struct process * jobList(int numProcs){
  int i;
  struct process * list = malloc(DEFAULT * sizeof(struct process));
  for (i = 0; i<numProcs; i++){
    list[i].pid = i;
  }
  return list;
}

struct semiphore * initSemiphore(int val){
  struct semiphore * S = malloc(sizeof(struct  semiphore));
  S -> val = val;
  S -> list = malloc(DEFAULT * sizeof(struct process));
  S -> list[DEFAULT - 1].pid = -1;
  return S;
}

void wait(struct semiphore * S) {
  S -> val--;
  if (S->val <= 0 ){
    printf("Add P to wait list\n");
  }
}

void signals(struct semiphore * S){
  S->val++;
  if (S->val <= 0){
    printf("Remove process P from list\n");
  }
}
