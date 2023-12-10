#include <stdio.h>

int bitwise_multiply(int a, int b);

int main(void){
    int a = 0;
    int b = 0;

    printf("Enter two integers to multiply: ");
    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d x %d = %d",a,b,bitwise_multiply(a,b));
    return 0;
}

int bitwise_multiply(int a, int b){
    int sum = 0;
    //loop through b
    while(b != 0){
        //if least significant bit of b is 1, then add a to the sum
        if(b&1){
            sum +=a;
        }
        //multiply a by two
    a<<=1;

        //divide b by two
    b>>=1;
    }
    return sum;
}