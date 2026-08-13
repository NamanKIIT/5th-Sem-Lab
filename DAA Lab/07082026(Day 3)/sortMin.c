//4.4 Write a program to read from a disk file into an array. Implement the algorithm to arrange the elements in ascending order. Also find and print the .

#include <stdio.h>

int main()
{
    int a[100], n, i, j, min, temp;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        printf("\nPass %d: Minimum element %d found at index %d", i + 1, a[min], min);

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    printf("\nAfter SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}