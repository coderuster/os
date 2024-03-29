#include <stdio.h>
# cp
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (!source) {
        perror("Error opening source file");
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (!destination) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    printf("File copied successfully\n");

    fclose(source);
    fclose(destination);

    return 0;
}
----------------------------------------------------------------
# ls
#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *dirEntry;
    DIR *directory = opendir(".");

    if (directory) {
        while ((dirEntry = readdir(directory)) != NULL) {
            printf("%s\n", dirEntry->d_name);
        }
        closedir(directory);
    } else {
        perror("Error opening directory");
        return 1;
    }

    return 0;
}
-----------

# grep
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s search_string file_name\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, argv[1])) {
            printf("%s", line);
        }
    }

    fclose(file);

    return 0;
}
