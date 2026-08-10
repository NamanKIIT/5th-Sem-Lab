//4. Write a C Program to enter a number and store the number across the following structure and print the content of each member of the structure. Then aggregate each member of the structure to form the original number and print the same.
// struct pkt{
// char ch1;
// char ch2[2];
// char ch3;
// };

#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    unsigned int n, m;
    struct pkt p;

    printf("Enter a 32-bit number: ");
    scanf("%u", &n);

    p.ch1 = n & 255;
    p.ch2[0] = (n >> 8) & 255;
    p.ch2[1] = (n >> 16) & 255;
    p.ch3 = (n >> 24) & 255;

    printf("\nContents of structure:\n");
    printf("ch1 = %u\n", (unsigned char)p.ch1);
    printf("ch2[0] = %u\n", (unsigned char)p.ch2[0]);
    printf("ch2[1] = %u\n", (unsigned char)p.ch2[1]);
    printf("ch3 = %u\n", (unsigned char)p.ch3);

    m = (unsigned char)p.ch1;
    m |= (unsigned char)p.ch2[0] << 8;
    m |= (unsigned char)p.ch2[1] << 16;
    m |= (unsigned char)p.ch3 << 24;

    printf("\nOriginal number after aggregation = %u\n", m);

    return 0;
}