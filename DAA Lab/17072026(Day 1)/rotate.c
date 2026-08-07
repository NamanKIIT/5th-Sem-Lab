//1.4 Aim of the program: Write a function to ROTATE_RIGHT (p1, p2) right an array for first p2 elements by 1 position using EXCHANGE (p, q) function that swaps/exchanges the numbers p &amp; q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.

#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int a[], int n) {
    for(int i = n - 1; i > 0; i--)
        EXCHANGE(&a[i], &a[i - 1]);
}

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the data in array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int p2;

    printf("Enter number of elements to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    ROTATE_RIGHT(a, p2);

    printf("\nAfter ROTATE: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}