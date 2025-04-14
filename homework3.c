#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

char ** parse(char delim, char * word);
void pointerPrint(char ** argv);
char * checkString(char ** parsedInput, char ** path, char * input);
void exec(char * pathToFile, char ** parsedInput);
int arraySize(char **arr);
int stringLength(char * string);

int main(int argc, char ** argv, char ** envp){
  char *path = NULL;
  char **parse01 = NULL;

  for (int i = 0; envp[i] != NULL; i++){
    if (strncmp(envp[i], "PATH", 4) == 0){
      path = envp[i] + 4;
      parse01 = parse(':', path);
    }
  }

  pointerPrint(parse01);

  while(1){
    char * input = malloc(100 * sizeof(char));
    printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n");
    printf("SUPER BASH $");
    scanf("%[^\n]%*c", input);
    char **parsedInput = parse(' ', input);
    char* perse02 = checkString(parsedInput, parse01, input);
    pointerPrint(parsedInput);

    exec(perse02,parsedInput);
  }
}



char **parse(char delim, char *parseString) {
  int length = stringLength(parseString);
  char **result = malloc((length + 1) * sizeof(char*)); // 최대 length개 + NULL
  int count = 0;

  int start = 0;
  for (int i = 0; ; i++) {
    if (parseString[i] == delim || parseString[i] == '\0') {
        int tokenLength = i - start;
        if (tokenLength > 0) {
          char *token = malloc((tokenLength + 1) * sizeof(char));
            strncpy(token, &parseString[start], tokenLength);
            token[tokenLength] = '\0';
            result[count++] = token;
          }
        start = i + 1;
    }

    if (parseString[i] == '\0') break;
  }

  result[count] = NULL;
  return result;
}

int arraySize(char **arr) {
    int count = 0;
    while (arr[count] != NULL) count++;
    return count + 1;
}


void pointerPrint(char ** argv){
  printf("Address %p\n", argv);

  for (int i=0; argv[i] != NULL; i++){
    printf("Base[%d] Address %p Pointer Value %p String%s\n", i, (void *)&argv[i], (void *)argv[i], argv[i]);
  }
}

int stringLength(char * string) {
  int count = 0;
  while(string[count] != '\0') {
    count++;
  }
  return count;
}

char * checkString(char ** parsedInput, char ** path, char * input){
  char *command = malloc(1024);

  if (!command) {
    perror("malloc failed");
    exit(1);
 }

 for (int i = 0; path[i] != NULL; i++){
    sprintf(command, "%s/%s", path[i], parsedInput[0]);
    printf("Checking %s\n", command);

    if(access(command, F_OK) != -1){
      printf("FOUND!\nString = '%s'\n", input);
      int size = arraySize(parsedInput);
      printf("Number of pinters = %d\n", size);
      pointerPrint(parsedInput);
      return command;
    }
  }
  free(command);
  return NULL;
}


void exec(char * pathToFile, char ** parsedInput){
  int state;
  if(fork() == 0) {
    execv(pathToFile, parsedInput);
  } else {
    wait(&state);
  }
}
