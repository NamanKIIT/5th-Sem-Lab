//5.5 Aim of the program: Write a program in C to find GCD of two numbers using recursion. Read all pair of numbers from a file and store the result in a separate file. Note# Source file name and destination file name taken from command line arguments. The source file must contain at least 20 pairs of numbers.

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    int a, b;
    char line[200];

    if (argc != 3) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    source = fopen(argv[1], "r");

    if (source == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    destination = fopen(argv[2], "w");

    if (destination == NULL) {
        printf("Error opening output file.\n");
        fclose(source);
        return 1;
    }

    while (fscanf(source, "%d %d", &a, &b) == 2)
        fprintf(destination, "The GCD of %d and %d is %d\n", a, b, gcd(a, b));

    fclose(source);
    fclose(destination);

    destination = fopen(argv[2], "r");

    if (destination == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    printf("Display the GCD stored in the output file %s:\n", argv[2]);

    while (fgets(line, sizeof(line), destination) != NULL)
        printf("%s", line);

    fclose(destination);

    return 0;
}