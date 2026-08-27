//

#include <stdio.h>

#define C 10

void insertionSort(int a[], int low, int high) {
    int i, j, key;

    for (i = low + 1; i <= high; i++) {
        key = a[i];
        j = i - 1;

        while (j >= low && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

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

void quickSort(int a[], int low, int high) {
    int p;

    if (high - low + 1 <= C)
        return;

    p = partition(a, low, high);

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);
    insertionSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}