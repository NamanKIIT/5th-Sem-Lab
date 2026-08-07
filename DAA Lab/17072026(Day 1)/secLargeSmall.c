//1.1 Aim of the program: Write a program to find out the second smallest and second largest element stored in an array of n integers.

#include <stdio.h>

int main()
{
    int n;
    int smallest, secondSmallest;
    int largest, secondLargest;

    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    int a[n];

    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    smallest = secondSmallest = 999999;
    largest = secondLargest = -999999;

    for(int i = 0; i < n; i++)
    {
        if(a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if(a[i] < secondSmallest && a[i] != smallest)
        {
            secondSmallest = a[i];
        }

        if(a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if(a[i] > secondLargest && a[i] != largest)
        {
            secondLargest = a[i];
        }
    }

    printf("Second Smallest = %d\n", secondSmallest);
    printf("Second Largest = %d\n", secondLargest);

    return 0;
}