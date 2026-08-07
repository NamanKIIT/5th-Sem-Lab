//2.1 Aim of the Program: Bubble Sort Write a program to read . Implement the  to sort the elements in ascending order. Also find and print the  during sorting.

#include<stdio.h>

int main(){
    int n,temp,sort=0;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the data in array: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);  
    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(a[j-1]>a[j]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                sort++;
            }
        }
    }
    printf("The resultant array is: \n");
    for(int i=0;i<n;i++)
        printf("%d\n",a[i]);
    printf("Total number of swaps = %d\n",sort);
    return 0;
}