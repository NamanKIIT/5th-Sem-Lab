//2.5 Aim of the program: Write a program to read ‘n’ integers from a disc file into an array. Modify the Insertion Sort algorithm to find and print the maximum number of positions any element had to shift backward to reach its correct sorted spot.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the data in array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before SORT: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int maxShift = 0, element;

    for(int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        int shift = 0;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shift++;
        }

        a[j + 1] = key;

        if(shift > maxShift) {
            maxShift = shift;
            element = key;
        }
    }

    printf("\nAfter SORT: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nMaximum shifts for a single element = %d (for element %d)\n", maxShift, element);

    return 0;
}