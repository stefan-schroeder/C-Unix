#include <stdio.h>


//swap grades

void swapgrades(int *studentA, int *studentB){
    *studentA = *studentA + *studentB;
    *studentB = *studentA - *studentB;
    *studentA = *studentA - *studentB;
}
//main 
int main(void){
    int studentA = 5;
    int studentB = 4;

    int *ptrA = &studentA;
    int *ptrB = &studentB;

    swapgrades(ptrA,ptrB);
    
    puts("Student A after swap: ");
    printf("%d \n", *ptrA); 
    
    puts("Student B after swap: ");
    printf("%d \n", *ptrB); 
}

// Using pointers in this situation makes the code more efficient and saves memory
// because we do not need to create another temporary integer variable that takes up four bytes
// It will also decrease the runtime of the program. 