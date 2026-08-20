//5.4 Aim of the program: Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file. Note# Read the value of ‘n’, source file name and destination file name from command line arguments. Display the decimal numbers and their equivalent binary numbers from the output file.

#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(unsigned int n, int binary[], int pos) {
    if (pos < 0)
        return;

    binary[pos] = n % 2;
    decimalToBinary(n / 2, binary, pos - 1);
}

int main(int argc, char *argv[]) {
    FILE *source, *destination;
    int n, num, count = 0;
    int binary[16];
    char line[200];

    if (argc != 4) {
        printf("Usage: %s n source_file destination_file\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);

    source = fopen(argv[2], "r");
    if (source == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    destination = fopen(argv[3], "w");
    if (destination == NULL) {
        printf("Error opening output file.\n");
        fclose(source);
        return 1;
    }

    while (count < n && fscanf(source, "%d", &num) == 1) {
        decimalToBinary(num, binary, 15);

        fprintf(destination, "The binary equivalent of %d is ", num);

        for (int i = 0; i < 16; i++)
            fprintf(destination, "%d", binary[i]);

        fprintf(destination, "\n");
        count++;
    }

    fclose(source);
    fclose(destination);

    destination = fopen(argv[3], "r");
    if (destination == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    printf("Content of the first %d decimal and their equivalent binary numbers:\n", count);

    while (fgets(line, sizeof(line), destination) != NULL)
        printf("%s", line);

    fclose(destination);

    return 0;
}