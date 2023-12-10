#include <stdio.h>


void printUniqueElements(int elements[], int lenArray){
//lenArray = length of the input array
// elements[] = input array
// prints unique elements e.g.: 2 3 4 5

int uniqueCnt = 0;

//print the size of the array
printf("Input size of Array: %d \n",lenArray);

//print input array
puts("Input: ");
for(int i = 0; i < lenArray; i++){
    printf("%d ", elements[i]);
}

puts("\n");

//loop through the array and check up until the 2nd to last elem
for(int i = 0; i < lenArray-1; i++){
    //loop through the array checking the last element 
    for(int j = i+1; j < lenArray; j++){
        //check to see if element at i == j;
        if(elements[i]==elements[j]){
            //remove the element by setting it equal to non practical value -12344321            
            elements[i] = -12344321;
        }
    }

}

puts("Output: ");
//print output 
for(int i = 0; i<lenArray; i++){
    //check the element, if not -12344321 print the element
    if(elements[i] != -12344321){
        printf("%d ", elements[i]);
        uniqueCnt++;
    }
}
printf("\nUnique Count: %d",uniqueCnt);
}

int main(void){
    int arr[] = {1,1,2,3,4,5,5,6,7,7,12,13,14,14};

    printUniqueElements(arr,14);
}