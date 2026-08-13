//4.2 Write a program to read from a disk file into an array. Modify the algorithm to find and print the .

#include <stdio.h>

void merge(int a[], int low, int mid, int high, int *maxSize)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    if (k > *maxSize)
        *maxSize = k;

    for (i = low, j = 0; i <= high; i++, j++)
        a[i] = temp[j];
}

void mergeSort(int a[], int low, int high, int *maxSize)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid, maxSize);
        mergeSort(a, mid + 1, high, maxSize);
        merge(a, low, mid, high, maxSize);
    }
}

int main()
{
    int a[100], n, i, maxSize = 0;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Before SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    mergeSort(a, 0, n - 1, &maxSize);

    printf("\nAfter SORT:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nMaximum merged subarray size = %d", maxSize);

    return 0;
}