#include <stdio.h>
#define SIZE 10

// prototype
int* find_max(int *arr, int size);
int* find_min(int *arr, int size);
int find_difference(int *arr, int size);

// main
int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int dif = (find_difference(arr,SIZE));
    printf("Difference: %d",dif);

}

int* find_max(int *arr, int size){
    int *maxPtr = &arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > *maxPtr){
            maxPtr = &arr[i];
        }
    }
    return maxPtr;
}

int* find_min(int *arr, int size){
    int *minPtr = &arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] < *minPtr){
            minPtr = &arr[i];
        }
    }
    return minPtr;
}

int find_difference(int *arr, int size){
    int *maxPtr = find_max(arr,size);
    int *minPtr = find_min(arr,size);
    return *maxPtr - *minPtr;
}
