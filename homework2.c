#include<stdio.h>
#include<stdlib.h>

void parse(char, char *);
int stringLength(char *);

int main(int argc, char ** argv){

  if(argc == 3){
    parse(argv[1][0], argv[2]);
  } else{
    printf("Enter the right number of args. ");
  }

}

void parse(char delim, char * parseString){
  int start = 0;
  int end = 0;
  int length = 0;

  while(parseString[end] != '\0'){
    if(parseString[end] == delim){
      length = end - start;
      char *substring = malloc((length + 1) * sizeof(char));
      substring[length] = '\0';

      for(int i = 0; i < length; i++){
        substring[i] = parseString[start + i];
      }
      printf("%s Length %d\n", substring, length);
      free(substring);

      start = end + 1;
    }
    end++;
  }
  if (start < end){
    length = end - start;
    char *substrings = malloc((length + 1) * sizeof(char));
    substrings[length] = '\0';

    for(int i = 0; i < length; i++){
      substrings[i] = parseString[start + i];
    }
    printf("%s Length %d\n", substrings, length);
    free(substrings);
  }
}

// int stringLength(char * string){
//   int count = 0;
//   while(string[count] != '\0'){
//     count++;
//   } return count;
// }
