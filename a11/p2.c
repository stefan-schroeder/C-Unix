#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *inputFile, *oddFile, *evenFile;
    int number;
    int countOdd = 0, countEven = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    oddFile = fopen("output_even.txt", "w");
    evenFile = fopen("output_odd.txt", "w");
    if (oddFile == NULL || evenFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        if (oddFile != NULL) fclose(oddFile);
        if (evenFile != NULL) fclose(evenFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &number) == 1) {
        if (number % 2 == 0) {
            countEven++;
        } else {
            countOdd++;
        }
    }
    rewind(inputFile);
    rewind(oddFile);
    rewind(evenFile);
    fprintf(oddFile, "This file contains a list of %d odd numbers\n", countOdd);
    fprintf(evenFile, "This file contains a list of %d even numbers\n", countEven);

    while (fscanf(inputFile, "%d", &number) == 1) {
        if (number % 2 == 0) {
            fprintf(evenFile, "%d\n", number);
        } 
        else {
            fprintf(oddFile, "%d\n", number);
        }
    }

    fclose(inputFile);
    fclose(oddFile);
    fclose(evenFile);

    return 0;
}
