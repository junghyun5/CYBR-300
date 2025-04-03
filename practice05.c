#include <stdio.h>
#include <stdlib.h>

#define DEFAULT 25

struct process{
  int pid;
};

struct semiphore{
  int val;
  struct process **list;
};



void wait(struct semiphore *, struct process *);
void signals(struct semiphore *, struct process *);
int findNextLocation(struct process **);
struct semiphore * initSemiphore(int);
struct process ** jobList(int);
int findProcess(struct process **, int);

int main(){
  //printf("test");
  struct semiphore * S = initSemiphore(2);
  struct process ** list = jobList(10);
  printf("process id: %d\n", list[0]->pid);
  wait(S, list[0]);
  wait(S, list[1]);
  signal(S, list[0]);
  signal(S, list[1]);
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

struct process ** jobList(int numProcs){
  int i;
  struct process ** list = malloc(DEFAULT * sizeof(struct process));
  for (i = 0; i<numProcs; i++){
    list[i] = malloc(sizeof(struct process));
    list[i]->pid = i;
  }
  return list;
}

struct semiphore * initSemiphore(int val){
  struct semiphore * S = malloc(sizeof(struct  semiphore));
  S -> val = val;
  S -> list = malloc(DEFAULT * sizeof(struct process));
  S -> list[DEFAULT - 1]->pid = -1;
  return S;
}

int findNextLocation(struct process ** list){
  int count = 0;
  while (list[count] != NULL){
    count++;
  }
  return count;
}

void wait(struct semiphore * S, struct process * p) {
  printf("Process calling wait: %d\n", p->pid);
  S -> val--;
  if (S->val <= 0 ){
    printf("Add P to wait list\n");
    //S->list.. 25 slots to add to
    int index = findNextLocation(S->list);
    // printf("Open index: %d\n", index);
    if (index < DEFAULT){
      S -> list[index] = p;
    }
  }
}

void signals(struct semiphore * S, struct process * p){
  printf("Process calling sginal: %d\n", p->pid);
  S->val++;
  if (S->val <= 0){
    printf("Remove process P from list\n");
    int index =findProcess(S->list, p->pid);
    if (index < DEFAULT -1){
      S->list[index] = NULL;
    }
  }
}

int findProcess(struct process ** list, int pid){
  int count = 0;
  while (list[count] -> pid != pid){
    count++;
  }
  return count;
}
