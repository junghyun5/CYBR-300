#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

// int main(int argc, char** argz){
//   printf("argc = %d\n", argc); //study here
//   if(argc == 3){
//     int i; //program6.exe {and write sentence here}
//     for (i=1; i<argc; i++){
//       printf("Arg %d: %s\n", i, argz[i]);
//     }
//   } else{
//     printf("You need to give only two arguments!\n");
//   }
// }

struct Car{
  int year;
  char * make;
  char * model;
  char * color;
};

void printCar(struct Car);
int main() {
  //declaration
  struct Car car;
  car1.year = 1993;
  car1.make = "Buick";
  car1.model = "Regal";
  car1.color = "Champagne";

  printCar();
}

void printCar(struct Car inCar){
  printf("Car Summary:\n\tYear: %d\n\tMake: %s\n\tColor: %s\n",
  inCar.year, inCar.make, inCar.model, inCar.color);
}

//char > 'c' > Cat > ['c','a','t',\0]
//char * > 2 things > the address to a char OR a address that points to a string
//Determine > we have to  use context

//char * firstName = malloc(4*sizeof(char))
//char * letter;
//* letter = 'c'
//pintiness

//char
//char *
//char **n = malloc(10 * sizeof(char *));
//char ***m = malloc(10 *sizeof(char**));
//char **** o = molloc(10*sizeof(char***));
