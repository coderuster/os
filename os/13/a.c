#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_PAGES 10

int frames[MAX_FRAMES];
int pageQueue[MAX_PAGES];
int pageFrequency[MAX_PAGES];
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

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    int page = pageQueue[front];
    front++;
    return page;
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

void lfuPageReplacement(int pages[], int n) {
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames with -1 (empty)
    }

    int pageFaults = 0;
    for (int i = 0; i < n; i++) {
        int pageIdx = isInFrames(pages[i]);
        if (pageIdx != -1) {
            // Page hit, update frequency
            pageFrequency[pages[i]]++;
        } else {
            // Page fault, replace least frequently used page
            int replacedPage = dequeue();
            if (replacedPage != -1) {
                printf("Page %d replaced with page %d\n", replacedPage, pages[i]);
            }
            enqueue(pages[i]);
            pageFaults++;
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == replacedPage) {
                    frames[j] = pages[i];
                    pageFrequency[pages[i]]++;
                    break;
                }
            }
            displayFrames();
        }
    }

    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {2, 3, 1, 4, 3, 1, 2, 4, 1, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    lfuPageReplacement(pages, n);
    return 0;
}
