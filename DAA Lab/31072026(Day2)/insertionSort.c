//2.2 Aim of the Program: Insertion Sort Write a program to read . Modify the  to find and print the  to reach its correct sorted position.

#include <stdio.h>

int main() {
    int n, i, j, key;
    int maxShifts = 0, element;

    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];

    printf("Enter the data in array: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]); 

    printf("Before SORT: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    for(i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        int shifts = 0;

        while(j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
            shifts++;
        }

        a[j + 1] = key;

        if(shifts > maxShifts) {
            maxShifts = shifts;
            element = key;
        }
    }

    printf("After SORT: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nMaximum shifts for a single element = %d\n", maxShifts);
    printf("Element with maximum shifts = %d\n", element);

    return 0;
}