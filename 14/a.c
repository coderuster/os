#include <stdio.h>

#define PAGE_SIZE 4096  // Page size in bytes

int main() {
    int logicalAddress, pageNumber, offset;

    printf("Enter a logical address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / PAGE_SIZE;
    offset = logicalAddress % PAGE_SIZE;

    printf("Logical Address: %d\n", logicalAddress);
    printf("Page Number: %d\n", pageNumber);
    printf("Offset: %d\n", offset);

    return 0;
}
