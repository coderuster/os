#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available[MAX_RESOURCES];
int max[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
bool finish[MAX_PROCESSES];

void init() {
    // Initialize available resources
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("Enter available resource amount for resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    // Initialize maximum resources required for each process
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter maximum resources required for Process %d:\n", i + 1);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
        finish[i] = false;  // Initialize all processes as unfinished
    }

    // Initialize allocation and need matrices
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter allocated resources for Process %d:\n", i + 1);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool isSafe() {
    int work[MAX_RESOURCES];
    bool finishCopy[MAX_PROCESSES];

    // Initialize work and finishCopy arrays
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < MAX_PROCESSES; i++) {
        finishCopy[i] = finish[i];
    }

    int count = 0;  // Count of finished processes
    while (count < MAX_PROCESSES) {
        bool found = false;
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (!finishCopy[i]) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == MAX_RESOURCES) {
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    finishCopy[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            return false;  // No safe sequence found
        }
    }
    return true;  // Safe sequence found
}

int main() {
    init();

    if (isSafe()) {
        printf("System is in a safe state.\n");
    } else {
        printf("System is in an unsafe state (deadlock may occur).\n");
    }

    return 0;
}
