#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
};

void fcfsScheduling(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }

    printf("Process Execution Order (First Come First Serve):\n");
    printf("ID\tArrival Time\tBurst Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime,
               processes[i].burstTime, processes[i].completionTime);
    }
}

int main() {
    struct Process processes[] = {{1, 0, 5, 0}, {2, 2, 3, 0}, {3, 4, 4, 0}};
    int n = sizeof(processes) / sizeof(processes[0]);
    fcfsScheduling(processes, n);
    return 0;
}
