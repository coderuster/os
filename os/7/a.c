#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100

struct IndexBlock {
    int blockPointers[MAX_BLOCKS];
};

struct File {
    int fileId;
    struct IndexBlock indexBlock;
};

struct File files[MAX_FILES];

void initFiles() {
    for (int i = 0; i < MAX_FILES; i++) {
        files[i].fileId = i + 1;
        for (int j = 0; j < MAX_BLOCKS; j++) {
            files[i].indexBlock.blockPointers[j] = -1; // Initialize all pointers to -1 (unallocated)
        }
    }
}

void allocateBlock(int fileId, int blockNumber) {
    if (fileId >= 1 && fileId <= MAX_FILES && blockNumber >= 0 && blockNumber < MAX_BLOCKS) {
        files[fileId - 1].indexBlock.blockPointers[blockNumber] = 1; // Allocate block by setting pointer to 1
    } else {
        printf("Invalid file ID or block number.\n");
    }
}

void displayAllocatedBlocks(int fileId) {
    if (fileId >= 1 && fileId <= MAX_FILES) {
        printf("Allocated blocks for File ID %d:\n", fileId);
        for (int i = 0; i < MAX_BLOCKS; i++) {
            if (files[fileId - 1].indexBlock.blockPointers[i] == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    } else {
        printf("Invalid file ID.\n");
    }
}

int main() {
    initFiles();

    // Allocate blocks for files
    allocateBlock(1, 5);
    allocateBlock(1, 10);
    allocateBlock(2, 3);

    // Display allocated blocks for files
    displayAllocatedBlocks(1);
    displayAllocatedBlocks(2);

    return 0;
}
