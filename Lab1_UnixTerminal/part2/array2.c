// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.

#include <stdio.h>
#include <stdlib.h>

int main(){
  int* a_int = (int*) malloc(sizeof(int) * 400);
  
  a_int[0] = 70;
	a_int[100] = 100;
	a_int[400] = 444;
	free(a_int);
  return 0;
  
}
  
