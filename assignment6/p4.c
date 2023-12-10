#include <stdio.h>
#include <stdbool.h>
#define NCOLS 4
#define NSTUD 5

//prototype
void filterstudents(int arr[][NCOLS], int minAge, int minYear, int minGrade);

int main(void){
    int minAge;
    int minYear;
    int minGrade;
    //init hardcoded 2d arr
    int students[5][NCOLS] = {
            {1,16,10,74},
            {2,17,11,99},
            {3,15,10,95},
            {4,18,12,84},
            {5,14,9,70}
        };

    puts("Enter the minimum age of students to filter (-1 to ignore): \n");
    scanf("%d", &minAge);
    puts("Enter the minimum year of students to filter (-1 to ignore): \n");
    scanf("%d", &minYear);
    puts("Enter the minimum grade of students to filter (-1 to ignore): \n");
    scanf("%d", &minGrade);

    filterstudents(students,minAge,minYear,minGrade);
    return 0;
}

void filterstudents(int arr[NSTUD][NCOLS], int minAge, int minYear, int minGrade){
    //initialize array to null for all values
    int matchArr[NSTUD];
    //init match to true 
    bool isMatch = true;
    //loop through each student, set match to false if any of the criteria don't match
    for(int i = 0; i< NSTUD; i++){
        //set to true with each iteration
        bool isMatch = true;
        //check the minage; 2rd element
        if(minAge != -1 && arr[i][1] < minAge){
            isMatch = false;
        }
        
        //check the minYear; 3rd element
        if(minYear != -1 && arr[i][2]<minYear){
            isMatch = false;
        }

        //check the minGrade; 4th element
        if(minGrade != -1 && arr[i][3]<minGrade){
            isMatch = false;
        }
        if(isMatch){
            //if match then, assign the element in the array with the student id number
            matchArr[i] = arr[i][0];
        }
        else{
            matchArr[i] = -1;
        }
    }
    puts("The students matching the criteria are: ");
    for(int i = 0; i<NSTUD; i++){
        //if the array at I is not equal to -1, then print that student
        if(matchArr[i] != -1){
            printf("%d \n",matchArr[i]);
        }
    } 
}