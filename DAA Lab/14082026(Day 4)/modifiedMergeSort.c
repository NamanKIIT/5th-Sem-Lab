//5.1 Design and implement a modified Merge Sort algorithm in which, instead of recursively dividing the array until each subarray contains only one element, the algorithm switches to Insertion Sort whenever the size of a subarray becomes less than or equal to a given threshold k. After sorting these small subarrays using Insertion Sort, merge them using the standard Merge Sort merge procedure.

#include <stdio.h>

void insertionSort(int arr[], int left, int right) {
    int i, j, key;

    for (i = left + 1; i <= right; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

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

void modifiedMergeSort(int arr[], int left, int right, int threshold) {
    int mid;

    if (right - left + 1 <= threshold) {
        insertionSort(arr, left, right);
        return;
    }

    mid = (left + right) / 2;

    modifiedMergeSort(arr, left, mid, threshold);
    modifiedMergeSort(arr, mid + 1, right, threshold);

    merge(arr, left, mid, right);
}

int main() {
    int arr[1000];
    int n, threshold, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the threshold k: ");
    scanf("%d", &threshold);

    modifiedMergeSort(arr, 0, n - 1, threshold);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}