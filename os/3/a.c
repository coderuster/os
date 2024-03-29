#include<stdio.h>

struct Process {
    int id;
    int priority;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sortProcesses(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void priorityScheduling(struct Process processes[], int n) {
    sortProcesses(processes, n);
    printf("Process Execution Order (Priority Scheduling):\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID: %d, Priority: %d\n", processes[i].id, processes[i].priority);
    }
}

int main() {
    struct Process processes[] = {{1, 3}, {2, 1}, {3, 2}};
    int n = sizeof(processes) / sizeof(processes[0]);
    priorityScheduling(processes, n);
    return 0;
}
