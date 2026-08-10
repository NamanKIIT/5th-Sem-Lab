//1. Write a C program to swap the content of 2 variables entered through the command line using function and pointer.

#include<stdio.h>

void swap(int *p1,int *p2){
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    return;
}

int main(){
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    swap(&a,&b);
    printf("Numbers after swapping is: %d\t%d\n",a,b);
}