//5. Write a C program to check whether the Host machine is in Little Endian or Big Endian. Enter a number, print the content of each byte location and Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.

#include <stdio.h>

int main() {
    unsigned int n, m;
    unsigned char *p;
    int i;

    printf("Enter a number: ");
    scanf("%u", &n);

    p = (unsigned char *)&n;

    if (p[0] == (n & 255))
        printf("Host machine is Little Endian\n");
    else
        printf("Host machine is Big Endian\n");

    printf("\nContents of each byte:\n");
    for (i = 0; i < 4; i++)
        printf("Byte %d = %u\n", i + 1, p[i]);

    m = ((n & 0x000000FF) << 24) |
        ((n & 0x0000FF00) << 8) |
        ((n & 0x00FF0000) >> 8) |
        ((n & 0xFF000000) >> 24);

    printf("\nNumber after changing Endianness = %u\n", m);

    return 0;
}