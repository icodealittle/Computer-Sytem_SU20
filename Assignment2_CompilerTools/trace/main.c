#include <stdio.h>
#include <time.h>

void msg(){
	printf("Hello!\n");
}


int main(){

	extern int count;
	time_t start;
	time_t end;
	start = time(NULL);
	int i;
	for(i= 0;i  < 10; ++i){
		msg();
	}

	end = time(NULL);
	printf("Functions called:%d\n", count);
	printf("Time: %f\n", difftime(end, start)); 
	return 0;
}
