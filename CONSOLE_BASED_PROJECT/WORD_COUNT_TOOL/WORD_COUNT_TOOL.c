#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void countFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return;
    }

    int lines = 0, words = 0, characters = 0;
    int inWord = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    if (characters > 0 && ch != '\n') {
        lines++;
    }

    fclose(file);

    printf("File: %s\n", filename);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
}

int main() {
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    countFile(filename);

    return 0;
}
