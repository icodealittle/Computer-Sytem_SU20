
//Re-use codes from Lab 1 part 2

#include <stdio.h>

long add(long a, long b){
  long result_value = a + b;
  return result_value;
}

int main(){
  long a = 120;
  long b = 220;
  
  printf("%ld + %ld = %ld\n", a, b, add(a, b));
  
  return 0;
  
}
