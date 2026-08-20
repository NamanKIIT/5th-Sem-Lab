//5.3 Write a program to implement a modified Binary Search algorithm in which, instead of dividing the sorted array into two equal halves, the search always partitions the array into one-fourth (1/4) and three-fourths (3/4). At each step, compare the key with the element located at the one-fourth position of the current search interval and continue the search in the appropriate subarray until the key is found or the search interval becomes empty.

#include <stdio.h>

int modifiedBinarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int pos = low + (high - low) / 4;

        if (arr[pos] == key)
            return pos;

        if (key < arr[pos])
            high = pos - 1;
        else
            low = pos + 1;
    }

    return -1;
}

int main() {
    int arr[1000];
    int n, key, i, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    result = modifiedBinarySearch(arr, n, key);

    if (result != -1)
        printf("Key found at position %d\n", result + 1);
    else
        printf("Key not found\n");

    return 0;
}