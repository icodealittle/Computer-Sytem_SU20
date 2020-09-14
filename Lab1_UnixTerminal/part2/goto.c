// Write a C program using the goto command and a label.


#include<stdio.h>

int main(){
  
  int a = 0;
  printf("String input: ");
    loop: if (getchar() != '\n'){
      a++;
      goto loop;
    }
  
  printf("Output: %d\n", a);
  
  return 0;
  
}
