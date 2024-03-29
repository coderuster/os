#include <stdio.h>
#include <stdlib.h>

struct Node {
    int blockNumber;
    struct Node *next;
};

struct File {
    int fileId;
    struct Node *head;
};

struct File *files = NULL;

void addBlock(struct File *file, int blockNumber) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->blockNumber = blockNumber;
    newNode->next = NULL;

    if (file->head == NULL) {
        file->head = newNode;
    } else {
        struct Node *current = file->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void displayBlocks(struct File *file) {
    struct Node *current = file->head;
    printf("Blocks allocated for File ID %d:\n", file->fileId);
    while (current != NULL) {
        printf("%d ", current->blockNumber);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create files
    struct File file1 = {1, NULL};
    struct File file2 = {2, NULL};

    // Add blocks to files
    addBlock(&file1, 5);
    addBlock(&file1, 10);
    addBlock(&file2, 3);

    // Display allocated blocks for files
    displayBlocks(&file1);
    displayBlocks(&file2);

    return 0;
}
