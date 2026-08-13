//Write a program to read from a disk file into an array. Implement the algorithm to sort the elements in ascending order. Also find and print the while inserting all elements.

#include <stdio.h>

int main()
{
    int a[100], n, i, j, key, low, high, mid, comparisons = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    for (i = 1; i < n; i++)
    {
        key = a[i];
        low = 0;
        high = i - 1;

        while (low <= high)
        {
            mid = (low + high) / 2;
            comparisons++;

            if (key < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        for (j = i - 1; j >= low; j--)
            a[j + 1] = a[j];

        a[low] = key;
    }

    printf("\nAfter SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTotal binary search comparisons = %d", comparisons);

    return 0;
}