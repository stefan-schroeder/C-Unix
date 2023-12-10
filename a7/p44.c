#include <stdio.h>
#include <string.h>

void replaceAll(const char *string, char *target, char *replacement, char *destination);

int main() {
    char string[101], target[101], replacement[101], destination[101];

    printf("Enter a string: ");
    fgets(string, 101, stdin);
    string[strcspn(string, "\n")] = '\0'; // remove newline character

    printf("Enter the target: ");
    fgets(target, 101, stdin);
    target[strcspn(target, "\n")] = '\0'; // remove newline character

    printf("Enter replacement: ");
    fgets(replacement, 101, stdin);
    replacement[strcspn(replacement, "\n")] = '\0'; // remove newline character

    replaceAll(string, target, replacement, destination);

    printf("Output: %s\n", destination);

    return 0;
}

void replaceAll(const char *string, char *target, char *replacement, char *destination) {
    int i, j, k, n = strlen(string), m = strlen(target), l = strlen(replacement);

    for (i = 0, j = 0; i < n; ) {
        if (strncmp(&string[i], target, m) == 0) {
            for (k = 0; k < l; k++) {
                destination[j++] = replacement[k];
            }
            i += m;
        } else {
            destination[j++] = string[i++];
        }
    }

    destination[j] = '\0';
}
