#include <stdio.h>

#define MAX_BLOCKS 5

struct Block {
    int id;
    int size;
    int allocated;
};

void worstFit(struct Block blocks[], int n, int processId, int processSize) {
    int largestBlockIndex = -1;
    int largestBlockSize = 0;

    for (int i = 0; i < n; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            if (blocks[i].size > largestBlockSize) {
                largestBlockSize = blocks[i].size;
                largestBlockIndex = i;
            }
        }
    }

    if (largestBlockIndex != -1) {
        blocks[largestBlockIndex].allocated = processId;
        printf("Process %d allocated to Block %d\n", processId, blocks[largestBlockIndex].id);
    } else {
        printf("Process %d cannot be allocated\n", processId);
    }
}

int main() {
    struct Block blocks[MAX_BLOCKS] = {{1, 100, 0}, {2, 200, 0}, {3, 50, 0}, {4, 300, 0}, {5, 150, 0}};
    int n = sizeof(blocks) / sizeof(blocks[0]);

    // Example processes to allocate
    worstFit(blocks, n, 1, 120);
    worstFit(blocks, n, 2, 80);
    worstFit(blocks, n, 3, 200);

    return 0;
}
