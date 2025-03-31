#include <stdio.h>
#include <stdlib.h>

char ** parse(char, char *);
int stringLength(char *);
char * stringCopy(Char *, int, int);

int main(int argc, char ** argv){
  // char * this = (char*)'c';
  // printf("%c\n", this);
  // printf("this");
  if(argc == 3){
    printf("Yay!");
    char ** substings = parse(argv[1][0], argv[2]);
  } else{
    printf("Enter the right number of args. ");
  }

}

char ** parse(char delim, char * parseString){
  printf("Delim: %c --> String: %s\n", delim, parseString);
  int len = stringLength(parseString);
  printf("len %d\n", len);
  int i;
  int start = 0;
  for(i=0; i<len; i++){
    printf("char %d -- > %c\n", i, parseString[i]);
    if(parseString[i] == delim){
      stringCopy(parseString, start, i-1);
      printf("FOUND!\n");
      printf("bottom of substring: %d\n", start);
      printf("top of substring %d\n", i-1);
    }
  }
  printf("bottom of substring: %d\n", start);
  printf("top of substring: %d\n", i-1);

}

int stringLength(char * string){
  int count = 0;
  while(string[count] != '\0'){
    count++;
  } return count;
}

char * stringCopy(Char * toCopy, int start, int end){
  printf("this");
  int len = end - start +1;
  //char * copy = malloc(len * sizeof(char));
  //int i;
  //for(i = 0; i < len; i++){
  //  copy[i] = toCopy[i];
  //} return copy;
}
// char = character
// char * = string
// char ** = array of strings
//Take in a delimiter and strings
//split the string at the delims
//put the substings in a char **
//return the char**
