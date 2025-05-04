#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 20
#define TIMESIZE 10
#define MEMSIZE 100


//Struct
struct Process{
  int procNum;
  int size;
  int time;
};


struct MemoryArea{
  int start;
  int end;
  struct Process *proc;
};

struct Memory{
  int size;
  struct MemoryArea **memory;
};


struct MemoryArea * makeMemoryArea(int, int);
struct MemoryArea ** makeBuffer(int);
int addAreaToBuffer(struct MemoryArea *, int size, int key);
struct Memory * makeMemory(int);
void printMemory(struct Memory *);
void printBuffer(struct MemoryArea **, int size);
struct Process * makeProcess(int);
void printProcess(struct Process *);
int run(struct Memory *);
void aquire(struct Memory *, struct Process *);
void updateMemory(struct Memory *);
void release(struct Memory *, struct Process *);
void resetEnd(int, struct Memory *);
int isEmpty(struct Memory *);


int main() {
  struct Memory * m = makeMemory(MEMSIZE);
  printMemory(m);
  run(m);
}


int run(struct Memory * m) {
  int totalProcesses = 1;
  int empty = -1;
  srand(time(NULL));
  do {
    printf("\n*********************** ITERATION ***************************\n");
    updateMemory(m);
    if (totalProcesses < 15) {
      struct Process * p = makeProcess(totalProcesses);
      printProcess(p);
      aquire(m, p);
      totalProcesses++;
    }
    printMemory(m);
    printf("\n********************** ITERATION END *************************\n\n");
    empty = isEmpty(m);
  } while (empty == 0);
  return 0;
}


struct Process * makeProcess(int procNum) {
  struct Process *p = malloc(sizeof(struct Process));
  p->procNum = procNum;
  p->size = (rand() % MAXSIZE) + 1;
  p->time = (rand() % TIMESIZE) + 3;
  return p;
}


void printProcess(struct Process * p) {
  printf("PROCESS:\n");
  printf("\tNum: \t%d\n",p->procNum);
  printf("\tSize: \t%d\n",p->size);
  printf("\tTime: \t%d\n",p->time);

}


int isEmpty(struct Memory * m) {
  if (m->memory[0]->proc == NULL && (m-> memory[0]-> end - m->memory[0]->start == m->size)){
    return 1;
  }
  return 0;
}


void aquire(struct Memory * m, struct Process * p) {
  int i = 0;
  while (m->memory[i+1] != NULL && m->memory[i+1]->start != -1){
    i++;
  }

  int availablesize = m->memory[i]->end - m->memory[i]->start;

  if(p->size < availablesize){
    m->memory[i]->proc = p;
    m->memory[i]->end = m->memory[i]->start + p->size;

    m->memory[i+1]->start = m->memory[i]->end + 1;
    m->memory[i+1]->end = m->size;
  }
  else{
    printf("Not Enough Room! Releasing Memory.\n");
  }

}


void release(struct Memory * m, struct Process * p) {
  int start_location = 0;
  int end_location = 0;

  for (int i = 0; i < m->size; i++){
    if (m->memory[i]->proc->procNum == p->procNum){
      start_location = i;
      break;
    }
  }

  for (int i = start_location + 1; i< m->size; i++){
    if(m->memory[i]->start == -1){
      end_location = i-1;
    }
    if(end_location == 0){
      end_location = m-> size -1;
    }
  }




  for(int i = start_location; i <= end_location -1; i++){
    m->memory[i]->end = m->memory[i]->start + (m->memory[i+1]->end - m->memory[i+1]->start);
    m->memory[i]->proc = m->memory[i+1]->proc;
    m->memory[i+1]->start = m->memory[i]->end + 1;
  }

  for(int i = end_location; i >= 0; i--){
    m->memory[i]->start = m->memory[i - 1]->end + 1;
    m->memory[i]->end = m->size;
    m->memory[i]->proc = NULL;
  }

  if(end_location + 1 < m->size){
    m->memory[end_location + 1] -> start = -1;
    m->memory[end_location + 1] -> end = -1;
  }

}


void updateMemory(struct Memory * m) {
  for(int i = 0; i< m->size; i++){
    if(m->memory[i]->proc->procNum != 0){
      if(m->memory[i]->proc->time <= 0){
        release(m,m->memory[i]->proc);
      }
      else{
        m->memory[i]->proc->time--;
      }
    }
  }
}


struct MemoryArea * makeMemoryArea(int start, int end) {
  struct MemoryArea *p = malloc(sizeof(struct MemoryArea));
  p->start = start;
  p->end = end;
  p->proc = malloc(sizeof(struct Process));
  p->proc->procNum = 0;
  p->proc->time = 0;
  p->proc->size = 0;

  return p;

}


struct MemoryArea ** makeBuffer(int size) {
  struct MemoryArea**buffer = malloc(size * sizeof(struct MemoryArea *));

  for(int i = 0; i<size; i++){
    if (i == 0)
        buffer[i] = makeMemoryArea(0, size);
    else
        buffer[i] = makeMemoryArea(-1, -1);
    }
  return buffer;
}


struct Memory * makeMemory(int size) {
  struct Memory *m = malloc(sizeof(struct Memory));
  m->size = size;
  m->memory = makeBuffer(size);

  return m;

}


void printMemory(struct Memory * mem) {
  printf("BUFFER\n");
  printBuffer(mem->memory, mem->size);
}


void printBuffer(struct MemoryArea ** m, int size) {
  for(int i = 0; i < size; i++){
    if(m[i]->start != -1){
      printf("\n\tStart:\t%d\n",m[i]->start);
      printf("\tEnd:\t%d\n",m[i]->end);
      printf("\tSize:\t%d\n",m[i]->proc->size);
      printf("\tProc:\t%d\n",m[i]->proc->procNum);
      printf("\tTime:\t%d\n",m[i]->proc->time);
      printf("\n");
    }
  }
}
