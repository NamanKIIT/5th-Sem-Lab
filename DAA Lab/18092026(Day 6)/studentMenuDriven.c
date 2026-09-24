#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

struct person *p;
int n = 0;

void swap(struct person *a, struct person *b) {
    struct person t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(int i) {
    int l = 2 * i + 1, r = 2 * i + 2, s = i;

    if (l < n && p[l].age < p[s].age)
        s = l;
    if (r < n && p[r].age < p[s].age)
        s = r;

    if (s != i) {
        swap(&p[i], &p[s]);
        minHeapify(s);
    }
}

void maxHeapify(int i, int size) {
    int l = 2 * i + 1, r = 2 * i + 2, s = i;

    if (l < size && p[l].weight > p[s].weight)
        s = l;
    if (r < size && p[r].weight > p[s].weight)
        s = r;

    if (s != i) {
        swap(&p[i], &p[s]);
        maxHeapify(s, size);
    }
}

void createMinHeap() {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(i);
}

void createMaxHeap() {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(i, n);
}

void insertPerson() {
    int i;
    struct person x;

    printf("Enter Id: ");
    scanf("%d", &x.id);

    x.name = malloc(100);
    printf("Enter Name: ");
    scanf(" %[^\n]", x.name);

    printf("Enter Age: ");
    scanf("%d", &x.age);
    printf("Enter Height: ");
    scanf("%d", &x.height);
    printf("Enter Weight(pound): ");
    scanf("%d", &x.weight);

    n++;
    p = realloc(p, n * sizeof(struct person));
    p[n - 1] = x;

    i = n - 1;
    while (i > 0 && p[(i - 1) / 2].age > p[i].age) {
        swap(&p[i], &p[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldest() {
    int i, pos = 0;

    for (i = 1; i < n; i++)
        if (p[i].age > p[pos].age)
            pos = i;

    free(p[pos].name);
    p[pos] = p[n - 1];
    n--;

    if (n > 0) {
        p = realloc(p, n * sizeof(struct person));
        createMinHeap();
    }
}

int main() {
    int choice, i;
    char file[100];
    FILE *fp;

    while (1) {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");

        printf("\nEnter option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter file name: ");
            scanf("%s", file);

            fp = fopen(file, "r");

            if (fp == NULL) {
                printf("Unable to open file.\n");
                continue;
            }

            printf("Enter number of students: ");
            scanf("%d", &n);

            p = malloc(n * sizeof(struct person));

            for (i = 0; i < n; i++) {
                p[i].name = malloc(100);
                fscanf(fp, "%d %[^\n]", &p[i].id, p[i].name);

                sscanf(strrchr(p[i].name, ' ') + 1, "%d", &p[i].weight);
                p[i].name[strlen(p[i].name) - 4] = '\0';
            }

            fclose(fp);
            printf("Data read successfully.\n");
        }
        else if (choice == 2) {
            createMinHeap();
            printf("Min-heap created based on age.\n");
        }
        else if (choice == 3) {
            createMaxHeap();
            printf("Max-heap created based on weight.\n");
        }
        else if (choice == 4) {
            if (n > 0)
                printf("Weight of youngest student: %.2f kg\n", p[0].weight * 0.453592);
            else
                printf("No data available.\n");
        }
        else if (choice == 5) {
            insertPerson();
            printf("Person inserted into Min-heap.\n");
        }
        else if (choice == 6) {
            if (n > 0) {
                deleteOldest();
                printf("Oldest person deleted.\n");
            } else {
                printf("No data available.\n");
            }
        }
        else if (choice == 7) {
            for (i = 0; i < n; i++)
                free(p[i].name);
            free(p);
            break;
        }
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}