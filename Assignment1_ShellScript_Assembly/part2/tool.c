// Implement your cycle count tool here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char *word_1 = "mov";
    char *word_2 = "add";
    char *word_3 = "sub";
    char *word_4 = "mul";
    char *word_5 = "div";
    char *word_6 = "lea";
    char *word_7 = "ret";
    char *word_8 = "pop";
    char *word_9 = "push";

    int letter;
    int count, count_I, count_II, count_III, count_IV, count_V, count_VI, count_VII, count_VIII, count_IX;
    count = count_I = count_II = count_III = count_IV = count_V = count_VI = count_VII = count_VIII = count_IX = 0;
    FILE *target_I = fopen(argv[1], "r");
    if (target_I == NULL) {
        exit(1);
    }
    while ((letter = getc(target_I)) != EOF) {
        count++;
    }
    char line[count];
    FILE *target_II = fopen(argv[1], "r");
    if (target_II == NULL) {
        exit(1);
    }
    while (fgets(line, sizeof line, target_II)) {
        char *c;
        c = strstr(line, "#");
        if (c) {
            *c = '\0';
        }
        if (strcasestr(line, word_1)) {
            count_I++;
        }
        if (strcasestr(line, word_2)) {
            count_II++;
        }
        if (strcasestr(line, word_3)) {
            count_III++;
        }
        if (strcasestr(line, word_4)) {
            count_IV++;
        }
        if (strcasestr(line, word_5)) {
            count_V++;
        }
        if (strcasestr(line, word_6)) {
            count_VI++;
        }
        if (strcasestr(line, word_7)) {
            count_VII++;
        }
        if (strcasestr(line, word_8)) {
            count_VIII++;
        }
        if (strcasestr(line, word_9)) {
            count_IX++;
        }
    }
    
    
    printf("%s %d\n", word_1, count_I);
    printf("%s %d\n", word_2, count_II);
    printf("%s %d\n", word_3, count_III);
    printf("%s %d\n", word_4, count_IV);
    printf("%s %d\n", word_5, count_V);
    printf("%s %d\n", word_6, count_VI);
    printf("%s %d\n", word_7, count_VII);
    printf("%s %d\n", word_8, count_VIII);
    printf("%s %d\n", word_9, count_IX);
    int total = count_I + count_II + count_III + count_IV + count_V + count_VI + count_VII + count_VIII + count_IX;
    printf("Total instructions = %d\n", total);
    int c1, c2, c3, c4, c5, c6, c7, c8, c9;
    c1 = c2 = c3 = c4 = c5 = c6 = c7 = c8 = c9 = 0;
    c1 = count_I * 1;
    c2 = count_II * 1;
    c3 = count_III * 1;
    c4 = count_IV * 2;
    c5 = count_V * 1;
    c6 = count_VI * 1;
    c7 = count_VII * 1;
    c8 = count_VIII * 3;
    c9 = count_IX * 2;
    int sum_cycle = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8 + c9;
    printf("Total cycles = %d\n", sum_cycle);
    fclose(target_I);
    fclose(target_II);
    return 0;
}


