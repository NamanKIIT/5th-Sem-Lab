//2.3 Aim of the Program: Selection Sort Write a program to read . Implement the  to arrange the elements in ascending order. Also find and print the .

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

    printf("\n");

    for(int i = 0; i < n - 1; i++) {
        int min = i;

        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }

        printf("Minimum selected in Pass %d: %d\n", i + 1, a[min]);

        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("After SORT: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}