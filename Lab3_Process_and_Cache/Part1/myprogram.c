// Take a look at some of the previous examples to create your own program!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
 
  //Copied from example 5
  char* myargv[16];	// We can store up to 16 arguments.
	myargv[0]="/bin/ls";	// Our first argument is the program we want to launch.
	myargv[1]="-F";		// Any additional arguments (i.e. flags) we want to make use of.
	myargv[2]=NULL; 	// Terminate the argument list--similar to how we would terminate a character string.
				// (i.e. Set the last argument to NULL if we have no more flags.)
  
  char* myargv_I[16];
	myargv_I[0] = "/bin/tree";
	myargv_I[1] = "-C";
	myargv_I[2] = NULL;
  
  char* myargv_II[16];
	myargv_II[0] = "/bin/echo";
	myargv_II[1] = "Execution of command line 'ls' and 'tree'\n";
	myargv_II[2] = NULL;
        
	if (fork() == 0){
		execve(myargv[0], myargv, NULL);
		printf("Child: Should never get here\n");
		exit(1);
	} 
  else {
		if (fork() == 0){
			execve(myargv_I[0], myargv_I, NULL);
			printf("Child: Should never get here\n");
               		exit(1);
    }
		else {
			if (fork() == 0){
				 execve(myargv_II[0], myargv_II, NULL);
				 printf("Child: Should never get here\n");
              			 exit(1);
			}
      else {
				wait(NULL);
        printf("\n");
			}
			wait(NULL);
			printf("\n");
		}
		wait(NULL);
		printf("This always prints last\n");
  }
  return 0;
}
