// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int colors[64][64 * 3];

// Modify your paint function here
void paint(int workID) {

    printf("Artist %d is painting\n", workID);

    int i = 0;
    for (i = 0; i < 64 * 3; i++) {
        colors[workID][i] = workID;

    }
}

int main(int argc, char **argv) {
    int numberOfArtists = 64; // How many child processes do we want?
    pid_t pid;
    int i;
    for (i = 0; i < numberOfArtists; i++) {
        pid = vfork();
        if (pid == 0) {
            paint(i);
            exit(0);
        }

        printf("Child created: %d\n", pid);
    }
    printf("parent is exiting(last artist out!)\n");

    printf("Masterpiece(vfork.ppm) is being assembled\n");

    FILE *fp;
    fp = fopen("threads.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    int j;
    for (i = 0; i < 64; i++) {
        for (j = 0; j < 64 * 3; j++) {
            fprintf(fp, "%d", colors[i][j]);
            fputs(" ", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);
    return 0;
}
