#include <stdio.h>

#define MAX_BLOCKS 5

struct Block {
    int id;
    int size;
    int allocated;
};

void bestFit(struct Block blocks[], int n, int processId, int processSize) {
    int bestFitIndex = -1;
    int minBlockSize = 999999;

    for (int i = 0; i < n; i++) {
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize && blocks[i].size < minBlockSize) {
            bestFitIndex = i;
            minBlockSize = blocks[i].size;
        }
    }

    if (bestFitIndex != -1) {
        blocks[bestFitIndex].allocated = processId;
        printf("Process %d allocated to Block %d\n", processId, blocks[bestFitIndex].id);
    } else {
        printf("Process %d cannot be allocated\n", processId);
    }
}

int main() {
    struct Block blocks[MAX_BLOCKS] = {{1, 100, 0}, {2, 200, 0}, {3, 50, 0}, {4, 300, 0}, {5, 150, 0}};
    int n = sizeof(blocks) / sizeof(blocks[0]);

    // Example processes to allocate
    bestFit(blocks, n, 1, 120);
    bestFit(blocks, n, 2, 80);
    bestFit(blocks, n, 3, 200);

    return 0;
}
