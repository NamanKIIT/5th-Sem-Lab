//3. Write a C program to extract each byte from a given number and store them in separate character variables and print the content of those variables.

#include <stdio.h>

int main() {
    unsigned int n;
    unsigned char b1, b2, b3, b4;

    printf("Enter a number: ");
    scanf("%u", &n);

    b1 = n & 255;
    b2 = (n >> 8) & 255;
    b3 = (n >> 16) & 255;
    b4 = (n >> 24) & 255;

    printf("%u\n", b1);
    printf("%u\n", b2);
    printf("%u\n", b3);
    printf("%u\n", b4);

    return 0;
}