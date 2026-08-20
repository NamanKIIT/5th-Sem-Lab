//5.2 Write a program to implement a modified Merge Sort algorithm in which, at every recursive step, the array is divided into two unequal parts: the first part contains one-third (1/3) of the elements, and the second part contains the remaining two-thirds (2/3) of the elements. After recursively sorting both parts, merge them to obtain the final sorted array.

#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int temp[1000];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void modifiedMergeSort(int arr[], int left, int right) {
    int n, mid;

    if (left >= right)
        return;

    n = right - left + 1;
    mid = left + n / 3 - 1;

    if (mid < left)
        mid = left;

    modifiedMergeSort(arr, left, mid);
    modifiedMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main() {
    int arr[1000];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    modifiedMergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}