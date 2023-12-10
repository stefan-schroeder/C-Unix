#include <stdio.h>

int main(void){
    int n, count = 0, i = 0;
    printf("Enter an integer: ");
    scanf("%d",&n);

    //check input
    if(n > 0 && n < 255){
        // reverse loop
        for(i = 7; i >= 0; i--){
            //check for bit at n
            if(n & (1<<i)){
                count++;
            }
        }
        printf("The number of bits set to 1 in the binary representation of %d is %d. \n", n, count);
        printf("The binary representation of %d is ",n);
        for(i = 7; i >= 0 ; i--){
            if(n & (1 << i)){
                printf("1");
            }
            else{
                printf("0");
            }
        }
    }

    return 0;
}