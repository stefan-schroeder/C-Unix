#include <stdio.h>
#include <stdlib.h>


int sum(int *arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
   return sum;
}

int main(void){
    int i =0;
    int tot = 0;
    int size;
    int nsize;
    printf("Enter the length of the int array: ");
    scanf("%d", &size);
    int *arr = (int *) malloc(size * sizeof(int));

    for(i = 0; i<size; i++){
        printf("Enter the %d integer: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    tot = sum(arr, size);

    printf("The sum of the 1st array is: %d\n", tot);
    

    printf("Enter how many numbers you want to add: ");
    scanf("%d", &nsize);
    nsize += size;
    arr = (int *) realloc(arr, nsize * sizeof(int));

    for(i = size; i<nsize; i++){
        printf("Enter the %d integer: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Sum of the 2nd array is: %d\n", sum(arr, nsize));
}