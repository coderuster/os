#include <stdio.h>

int main() {
    int size = 5;
    int array[size];

    // Allocate memory sequentially in array
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }

    // Display the allocated data
    printf("Sequentially allocated data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
