#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implementation of 'cp' command
void copyFile(const char *src, const char *dest) {
    FILE *source = fopen(src, "r");
    FILE *destination = fopen(dest, "w");
    char ch;

    if (source == NULL || destination == NULL) {
        printf("Error opening files\n");
        return;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
}

// Implementation of 'ls' command
void listFiles() {
    system("ls");
}

// Implementation of 'grep' command
void grep(const char *pattern, const char *filename) {
    char command[100];
    sprintf(command, "grep '%s' %s", pattern, filename);
    system(command);
}

int main() {
    // Example usage of implemented commands
    copyFile("source.txt", "destination.txt");
    listFiles();
    grep("pattern", "file.txt");

    return 0;
}
