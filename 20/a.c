#include <stdio.h>

#define MAX_FILES 5
#define MAX_BLOCKS 10

struct IndexBlock {
    int blockPointers[MAX_BLOCKS];
};

struct File {
    int id;
    int size;
    struct IndexBlock index;
};

void createFile(struct File files[], int fileId, int fileSize) {
    if (fileId < 0 || fileId >= MAX_FILES) {
        printf("Invalid file ID\n");
        return;
    }
    if (files[fileId].size != 0) {
        printf("File with ID %d already exists\n", fileId);
        return;
    }
    if (fileSize > MAX_BLOCKS) {
        printf("File size exceeds maximum block limit\n");
        return;
    }

    files[fileId].id = fileId;
    files[fileId].size = fileSize;

    for (int i = 0; i < fileSize; i++) {
        files[fileId].index.blockPointers[i] = i + 1; // Assign block pointers sequentially
    }

    printf("File with ID %d and size %d created successfully\n", fileId, fileSize);
}

void displayFile(struct File files[], int fileId) {
    if (fileId < 0 || fileId >= MAX_FILES) {
        printf("Invalid file ID\n");
        return;
    }
    if (files[fileId].size == 0) {
        printf("File with ID %d does not exist\n", fileId);
        return;
    }

    printf("File ID: %d\n", files[fileId].id);
    printf("File Size: %d blocks\n", files[fileId].size);
    printf("Index Block Pointers:\n");
    for (int i = 0; i < files[fileId].size; i++) {
        printf("%d ", files[fileId].index.blockPointers[i]);
    }
    printf("\n");
}

int main() {
    struct File files[MAX_FILES] = {0}; // Initialize all files with size 0
    int fileId, fileSize;

    // Example: Create file with ID 1 and size 3 blocks
    fileId = 1;
    fileSize = 3;
    createFile(files, fileId, fileSize);

    // Example: Display file with ID 1
    displayFile(files, fileId);

    return 0;
}
