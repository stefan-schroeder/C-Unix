#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void replaceAll(const char * string, char * target, char * replacement, char * destination);

int main(void){
    char str[100];
    char targ[100];
    char repl[100];

    const char *string;
    char *target;
    char *replacement;
    char *destination;

    printf("Enter a string: ");
    scanf("%100s \n", &str);
    printf("Enter a target: ");
    scanf("%100s \n", &targ);
    printf("Enter a replacement: ");
    scanf("%100s \n", &repl);

    string = &str;
    target = &targ;
    replacement = &repl;

    replaceAll(string, target, replacement, destination);

    printf("The new string is: %s", destination);

}

void replaceAll(const char * string, char * target, char * replacement, char * destination){
    int len = strlen(string);
    int target_len = strlen(target);
    int replacement_len = strlen(replacement);
    int dest_index = 0;

    for(int i = 0; i < len; i++){
        if(string[i] == target[0]){
            //if str and targ are same
            if(strncmp(&string[i], target,target_len) == 0){
                // copy replacement to destination
                strncpy(&destination[dest_index], replacement, replacement_len);
                dest_index += replacement_len;
                i += target_len - 1;
            }
            else{
                destination[dest_index] = string[i];
                dest_index++;
            }
        }
        else{
            destination[dest_index] = string[i];
            dest_index++;
        }
    }
    destination[dest_index] = '\0';
}