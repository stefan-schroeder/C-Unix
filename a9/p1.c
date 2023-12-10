#include <stdio.h>
#include <stdlib.h>

int main(void){
    int len = 0;
    int wid = 0;
    int sum = 0;

    printf("Enter the length of the length in meters: ");
    scanf("%d", &len);
    printf("Enter the width of the length in meters: ");
    scanf("%d", &wid);

    int *ptr = calloc(len*wid, sizeof(int));

    printf("Enter in the amount of waste found in each square meter: \n");
    
    for(int i = 0; i< len*wid; i++){
        printf("Square meter %d: \n",i+1);
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < len*wid; i++){
        sum += ptr[i];
    }
    double finalTot = (double) sum / (len*wid);
    printf("The amount of plastic per square meter is %f", finalTot);
    return 0;
}