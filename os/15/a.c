#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void sjfScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int completed = 0;
    int minBurst = 9999;
    int shortest = 0;
    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    while (completed != n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst && processes[i].burstTime > 0) {
                minBurst = processes[i].burstTime;
                shortest = i;
            }
        }

        processes[shortest].burstTime--;
        minBurst = processes[shortest].burstTime;

        if (minBurst == 0) {
            completed++;
            processes[shortest].completionTime = currentTime + 1;
            processes[shortest].waitingTime = processes[shortest].completionTime - processes[shortest].arrivalTime - processes[shortest].burstTime;
            processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;

            totalWaitingTime += processes[shortest].waitingTime;
            totalTurnaroundTime += processes[shortest].turnaroundTime;
        }

        currentTime++;
    }

    printf("Process Execution Order (Shortest Job First):\n");
    printf("ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime,
               processes[i].burstTime + 1, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

int main() {
    struct Process processes[] = {{1, 0, 6, 0, 0, 0}, {2, 2, 3, 0, 0, 0}, {3, 4, 4, 0, 0, 0}};
    int n = sizeof(processes) / sizeof(processes[0]);
    sjfScheduling(processes, n);
    return 0;
}
