#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int n;
    printf("Enter the number of words you want to type: ");
    scanf("%d", &n);

    char **words = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *) malloc(21 * sizeof(char));
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }

    srand(time(NULL));
    printf("%c", toupper(words[rand() % n][0]));
    for (int i = 1; i < 10; i++) {
        printf(" %s", words[rand() % n]);
    }
    printf(".");

    for (int i = 0; i < n; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
