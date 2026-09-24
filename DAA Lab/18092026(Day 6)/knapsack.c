#include <stdio.h>

struct ITEM {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
};

void heapify(struct ITEM a[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    struct ITEM temp;

    if (l < n && a[l].profit_weight_ratio > a[largest].profit_weight_ratio)
        largest = l;

    if (r < n && a[r].profit_weight_ratio > a[largest].profit_weight_ratio)
        largest = r;

    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void heapSort(struct ITEM a[], int n) {
    int i;
    struct ITEM temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }

    for (i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

int main() {
    struct ITEM a[100];
    int n, i;
    float capacity, remaining, profit = 0, amount;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &a[i].item_profit, &a[i].item_weight);
        a[i].profit_weight_ratio = a[i].item_profit / a[i].item_weight;
    }

    printf("Enter the capacity of knapsack:");
    scanf("%f", &capacity);

    heapSort(a, n);

    remaining = capacity;

    printf("\nItem No\tprofit\t\tWeight\t\tAmount to be taken\n");

    for (i = 0; i < n; i++) {
        if (remaining >= a[i].item_weight) {
            amount = 1.0;
            remaining -= a[i].item_weight;
            profit += a[i].item_profit;
        } else if (remaining > 0) {
            amount = remaining / a[i].item_weight;
            profit += a[i].item_profit * amount;
            remaining = 0;
        } else {
            amount = 0.0;
        }

        printf("%d\t%.6f\t%.6f\t%.6f\n",
               a[i].item_id, a[i].item_profit, a[i].item_weight, amount);
    }

    printf("\nMaximum profit: %.6f\n", profit);

    return 0;
}