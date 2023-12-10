#include <stdio.h>//for io
#include <stdlib.h> //for malloc
#include <time.h>//for randomnum
#include <ctype.h> //for toupper

int main(void){
    //initialize count 
    int n = 0;
    printf("Input the number of words: ");
    scanf("%d", &n);
    // create a double pointer that points to a character array(another pointer)
    char **words = (char **) malloc(n * sizeof(char *));
    //loop through n words that the user enters
    for(int i = 0; i<n; i++){
        // allocate a space of 21 for each word +1 for null term
        words[i] = (char *) malloc(21 * sizeof(char)); 
        //store the word into the index of words
        printf("Enter word %d: ",i+1);
        scanf("%20s",words[i]);
    }
    //seed random number generator with null
    srand(time(NULL));
    
    
    
    puts("Generated sentence: ");
    //print the first word capitalized, then convert that word back to a lowercase word
    int num = rand() % n;
    words[num][0] = toupper(words[num][0]);
    printf("%s ",words[num]);
    words[num][0] = tolower(words[num][0]);

   
    //print next 9 random words
    for(int j = 1; j < 10; j++){
    //generate random number between 0 and n and print the random word
        int num = rand() % n;
        printf("%s",words[num]);
        printf(" ");
    }
    //print period after the words 
    printf(".");
    // print newline for clarity and return 0 
    printf("\n");
    return 0;
}