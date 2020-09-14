// Write a C program using a switch statement

#include <stdio.h>

int main(){
  
  int grade = 85;
  
  switch(grade){
    case 100 :
      printf("Excellent\n");
      break;
    case 95 :
      printf("Asian B\n");
      break;
    case 90 : 
      printf("Asian C\n");
      break;
    case 85 :
      printf("No dinner!\n");
      break;
    case 80 :
      printf("You're a disgrace\n");
      break;
    default :
      printf("Why are you like this?\n");
  }
  
  printf("Your grade is: %d\n", grade);
  
  return 0;
}
