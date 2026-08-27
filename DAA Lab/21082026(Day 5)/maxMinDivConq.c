//6.1 WAP to find out maximum minimum using divide and conquer approach.

#include <stdio.h>

void findMinMax(int a[], int low, int high, int *min, int *max) {
    int mid, min1, max1, min2, max2;

    if (low == high) {
        *min = *max = a[low];
        return;
    }

    mid = (low + high) / 2;

    findMinMax(a, low, mid, &min1, &max1);
    findMinMax(a, mid + 1, high, &min2, &max2);

    *min = min1 < min2 ? min1 : min2;
    *max = max1 > max2 ? max1 : max2;
}

int main() {
    int n, i, min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    findMinMax(a, 0, n - 1, &min, &max);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    return 0;
}