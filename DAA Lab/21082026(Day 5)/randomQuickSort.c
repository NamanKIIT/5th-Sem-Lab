//6.3 WAP to implement Randomized quick sort

#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1, j, temp;

    for (j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

int randomizedPartition(int a[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    int temp = a[r];

    a[r] = a[high];
    a[high] = temp;

    return partition(a, low, high);
}

void randomizedQuickSort(int a[], int low, int high) {
    if (low < high) {
        int p = randomizedPartition(a, low, high);
        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    randomizedQuickSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}