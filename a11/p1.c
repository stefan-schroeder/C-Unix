#include <stdio.h>

int main(void){
    FILE *file;
    char ch;
    int pos;
    int count[5] = {0,0,0,0,0};
    file = fopen("input.txt", "r");
    if (file == NULL){
        printf ("Error opening file\n");
        return 1;
    }

    while(ch!= EOF){
        ch = fgetc(file);
        pos = ftell(file);
        switch (ch){
            case 'a':
                count[0]++;
                break;
            case 'e':
                count[1]++;
                break;
            case 'i':
                count[2]++;
                break;            
            case 'o':
                count[3]++;
                break;
            case 'u':
                count[4]++;
                break;
        }
        fseek(file, pos, SEEK_SET);    
    }
    fclose(file);

    printf("a: %d\n", count[0]);
    printf("e: %d\n", count[1]);
    printf("i: %d\n", count[2]);
    printf("o: %d\n", count[3]);
    printf("u: %d\n", count[4]);
    



    return 0;
}