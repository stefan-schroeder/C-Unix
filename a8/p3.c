#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//prototype 
void stringConcat(const char * str1, const char * str2);

int main(int argc, char *argv[]){
    //initialze vars
    if (argc<3){
        printf("Please enter two arguments");
        return 1;
    }

    stringConcat(argv[1],argv[2]);

}


void stringConcat(const char * str1, const char * str2){
    //allocate memory for nstr
    char * nstr = malloc(strlen(str1) + strlen(str2) +1);
    //add 1st string to nstring
    size_t i = 0;
    for(;i<strlen(str1); i++){
        nstr[i] = str1[i];
    }
    //add space
    nstr[i] = ' ';
    i++;
    // add second string to nstring
    size_t j = 0;
    for(;j<strlen(str2);i++,j++){
        nstr[i] = str2[j];
    }
    nstr[i] = '\0';
    //print nstring
    printf("%s",nstr);
}