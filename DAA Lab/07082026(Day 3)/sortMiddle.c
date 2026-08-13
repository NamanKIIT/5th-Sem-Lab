//4.3 Write a program to read from a disk file into an array. Sort the array in ascending order and implement the algorithm to search for a given key. Print the during the search.

#include <stdio.h>

int main()
{
    int a[100], n, i, j, temp, key;
    int low, high, mid;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nMiddle elements examined:\n");

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("%d ", a[mid]);

        if (a[mid] == key)
        {
            printf("\nElement found at position %d", mid + 1);
            return 0;
        }
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    printf("\nElement not found");

    return 0;
}