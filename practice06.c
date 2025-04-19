#include <stdio.h>
#include <Stdlib.h>
#include <time.h>

struct Process {
  int procNum;
  int size;
  int time;
};

struct MemoryArea {
  int strat;
  int end;
  struct Process * proc;
};

struct Memory{
  int size;
  struct MemoryArea * Memory;
};

int main(){
  struct Process * p1 = malloc(sizeof(struct Process));
  p1 -> procNum = 1;
  p1 -> size = 10;
  p1 -> time = 2;

  printf("Proc: %d\n\tSize: %d\n\tTime: %d\n,", p1->procNum, p1->size, p1->time);
  struct MemoryArea * m1 = malloc(sizeof(struct MemoryArea));
  m1 -> start = 0;
  m1 -> end = m1->start + p1->size;
  m1 -> proc = p1;

  printf("MemArea: \n\tStart: %d\n\tEnd: %d\n\tProcID: %d\n", m1->start, m1->end, m1->proc->procNum);

  struct Memory * mem1 = malloc(sizeof(struct Memory));
  mem1 -> size = 10;
  mem1 -> memory = malloc(mem1 -> size * sizeof(struct MemoryArea));
  mem1 -> memory[0] = m1;

  printf("Memory:\n\tSize: %d\n\tMem 0 proc id: %d\n", mem1->size, mem1->memory[0]->proc->procNum);
}
