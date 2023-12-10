#include <stdio.h>

// Custom strlen function
int my_strlen(char *str) {
    int count = 0;

    while (*str != '\0') {
        count++;
        str++;
    }

    return count;
}

int main(int argc, char **argv) {
    char *str = argv[1]; // Get the 1st command line argument.
    
    // Use the custom my_strlen function to get the length of the string
    int len = my_strlen(str);
    
    // Print the length with double quotes using escape sequences
    printf("Length of \"%s\": %d\n", str, len);

    return 0;
}