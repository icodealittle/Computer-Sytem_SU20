// Compile with: gcc fileread.c -o fileread
// Run with: ./fileread

// Fill in the code!
#include <stdio.h>
#include <stdlib.h>

int main(){

        FILE* my_fileRead;

        my_fileRead = fopen("./data.txt", "r");


        if (my_fileRead == NULL){

                fprintf(stderr, "Not found. Did you run data.sh?\n");
                fprintf(stderr, "Error\n");

                fprintf(stderr, "Terminating the program now\n");

                exit(1);

        }

        char buffer[255];

        while (fscanf(my_fileRead, "%s", buffer) != EOF){

                printf("Wins: %s\n", buffer);

        }

        fclose(my_fileRead);

        return 0;

}
