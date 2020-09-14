// Write a C program that swaps two integers in a function

#include <stdio.h>

//Helper method
void swap(int* a, int* b){
  
  int a1 = *a;
  int b1 = *b;
  *a = b1;
  *b = a1;
}

int main(){
  
  int a = 1;
  int b = -2;
  
  printf("a: %d, b: %d\n", a, b);
  printf("====== swap ======\n");
  swap(&a, &b);
  printf("a: %d, b: %d\n", a, b);
  return 0;
  
}
