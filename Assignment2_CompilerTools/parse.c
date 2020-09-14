// Implement a working parser in this file that splits text into individual tokens.

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]){
 
  char str[strlen(argv[1])];
  int i = 0;
  for (i = 0; i < strlen(argv[1]); i++){
    str[i] = argv[1][i];
  }
  
  char* print_char;
  print_char = strtok(str, " ");
  while (print_char != NULL){
    printf("%s\n", print_char);
    print_char = strtok(NULL, " ");
  }
  
  return 0;
}
