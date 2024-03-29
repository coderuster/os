#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int frames[MAX_FRAMES];
int pageQueue[MAX_PAGES];
int rear = -1, front = -1;

void enqueue(int page) {
    if (rear == MAX_PAGES - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    pageQueue[rear] = page;
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    }
    front++;
}

int isInFrames(int page) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == page) {
            return i;
        }
    }
    return -1;
}

void displayFrames() {
    printf("Frames after page replacement:\n");
    for (int i = 0; i < MAX_FRAMES; i++) {
        if (frames[i] == -1) {
            printf("Empty ");
        } else {
            printf("%d ", frames[i]);
        }
    }
    printf("\n");
}

void lruPageReplacement(int pages[], int n) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames with -1 (empty)
    }

    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        if (isInFrames(pages[i]) == -1) {
            if (rear == MAX_FRAMES - 1) {
                int lruPage = pageQueue[front];
                dequeue();
                for (int j = 0; j < MAX_FRAMES; j++) {
                    if (frames[j] == lruPage) {
                        frames[j] = pages[i];
                        break;
                    }
                }
            } else {
                enqueue(pages[i]);
                frames[rear] = pages[i];
            }
            pageFaults++;
            displayFrames();
        }
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {2, 3, 1, 4, 3, 1, 2, 4, 1, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    lruPageReplacement(pages, n);
    return 0;
}
