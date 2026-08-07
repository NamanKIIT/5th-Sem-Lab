//2.6 Aim of the program: Write a program to read ‘n’ integers from a disc file into an array. Implement the Bubble Sort algorithm to sort only the even numbers in ascending order, while keeping all odd numbers exactly in their original positions.

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

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(a[j] % 2 == 0) {
                int k = j + 1;

                while(k < n && a[k] % 2 != 0)
                    k++;

                if(k < n && a[j] > a[k]) {
                    int temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }
            }
        }
    }

    printf("\nAfter SORT: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}