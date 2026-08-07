//1.2 Aim of the program: Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the data in array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Input Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    printf("Output Array: ");

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        printf("%d ", sum);
    }

    return 0;
}