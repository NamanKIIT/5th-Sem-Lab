//2.4 Aim of the program: Insertion Sort on Strings Write a program to read n names (strings) from a disc file into an array. Implement the Insertion Sort algorithm to sort these names in alphabetical (lexicographical) order.

#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    char a[n][50], temp[50];

    printf("Enter the names:\n");
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);

    printf("Before SORT: ");
    for(int i = 0; i < n; i++)
        printf("%s ", a[i]);

    printf("\n");

    for(int i = 1; i < n; i++) {
        strcpy(temp, a[i]);
        int j = i - 1;

        while(j >= 0 && strcmp(a[j], temp) > 0) {
            strcpy(a[j + 1], a[j]);
            j--;
        }

        strcpy(a[j + 1], temp);
    }

    printf("After SORT: ");
    for(int i = 0; i < n; i++)
        printf("%s ", a[i]);
    printf("\n");
    return 0;
}