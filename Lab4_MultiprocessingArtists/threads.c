// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int colors[64][64 * 3];
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

//void paint(int workID);

void *thread(void *vargp) {
    pthread_mutex_lock(&mutex1);
    paint(count);
    count++;
    pthread_mutex_unlock(&mutex1);
}

void paint(int workID) {

    printf("Artist %d is painting\n", workID);
    int i;
    for (i = 0; i < 64 * 3; i++) {
        colors[workID][i] = workID; // Try doing something more interesting with the colors!
    }
}

int main(int argc, char **argv) {
    int numberOfArtists = 64;
    pthread_t pthread[numberOfArtists];
    int i;
    for (i = 0; i < numberOfArtists; ++i) {
        pthread_create(&pthread[i], NULL, thread, NULL);
    }
    int j;
    for (j = 0; j < numberOfArtists; ++j) {
        pthread_join(pthread[j], NULL);
    }
    printf("Masterpiece(vfork.ppm) is being assembled\n");
    FILE *fp;
    fp = fopen("threads.ppm", "w+");
    fputs("P3\n", fp);
    fputs("64 64\n", fp);
    fputs("255\n", fp);
    int k;
    int l;
    for (k = 0; k < 64; k++) {
        for (l = 0; l < 64 * 3; l++) {
            fprintf(fp, "%d", colors[k][l]);
            fputs(" ", fp);
        }
        fputs("\n", fp);
    }
    fclose(fp);

    return 0;
}
