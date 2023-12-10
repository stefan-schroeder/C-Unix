#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Address{
    int number;
    char streetname[20];
    char streettype[5];
};
struct Student{
    char stud_name[30];
    struct Address address;

};


int main(void){

    int n;
    printf("*/How many students do you want to enter*/\n");
    printf("Enter limit : ");
    scanf("%d", &n);
    printf("\n");

    //initialize students array and populate
    struct Student *students = malloc(n * sizeof(struct Student));
    for(int i = 0; i < n; i++){
        printf("Enter Student - %d Details\n",i+1);
        printf("--------------------------\n");
        printf("Enter Name: ");
        scanf("%s", students[i].stud_name);
        printf("Address\n");
        printf("Number: ");
        scanf("%d",&students[i].address.number);
        printf("\n");
        printf("Street Name: ");
        scanf("%s",students[i].address.streetname);
        printf("\n");
        printf("Street Type: ");
        scanf("%s",students[i].address.streettype);
        printf("\n");
    }

    //print data pre-arrangement
    printf("\tData before arrangement\n");
    printf("--------------------------\n");
    printf("Student Name     Address\n");
    printf("--------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%s\t\t%d %s %s\n",students[i].stud_name,students[i].address.number,students[i].address.streetname,students[i].address.streettype);
    }

    //sort students
    struct Student temp = students[0];
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j<n;j++){
            if(students[j].stud_name[0] < students[i].stud_name[0]){
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    //print out sorted students
    printf("\tData after arrangement\n");
    printf("--------------------------\n");
    printf("Student Name     Address\n");
    printf("--------------------------\n");
    for(int i = 0; i < n; i++){
        printf("%s\t\t%d %s %s\n",students[i].stud_name,students[i].address.number,students[i].address.streetname,students[i].address.streettype);
    }

}