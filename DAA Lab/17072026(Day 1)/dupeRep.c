//1.3 Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.

#include <stdio.h>

int main() {
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the data in array:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("The content of the array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int duplicate = 0;
    int maxCount = 0, element;

    for(int i = 0; i < n; i++) {
        int count = 1;

        for(int j = i + 1; j < n; j++)
            if(a[i] == a[j])
                count++;

        int first = 1;
        for(int j = 0; j < i; j++)
            if(a[i] == a[j])
                first = 0;

        if(first) {
            if(count > 1)
                duplicate++;

            if(count > maxCount) {
                maxCount = count;
                element = a[i];
            }
        }
    }

    printf("\nTotal number of duplicate values = %d", duplicate);
    printf("\nThe most repeating element in the array = %d\n", element);

    return 0;
}