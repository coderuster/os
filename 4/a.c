#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int currentTime = 0;
    int completedProcesses = 0;

    printf("Process Execution Order (First Round Robin Scheduling):\n");
    while (completedProcesses < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime <= quantum) {
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    printf("Process ID: %d, Completion Time: %d\n", processes[i].id, currentTime);
                    completedProcesses++;
                } else {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                }
            }
        }
    }
}

int main() {
    struct Process processes[] = {{1, 10, 10}, {2, 5, 5}, {3, 8, 8}};
    int n = sizeof(processes) / sizeof(processes[0]);
    int quantum = 3;
    roundRobinScheduling(processes, n, quantum);
    return 0;
}
