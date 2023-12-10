#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct {
    char fname  [50];
    char lname [50];
    int patientId; 
}Patient;

int main(void){


Patient arr[50];
char fname[50];
char lname[50];
int count = 0;
srand(time(NULL));
do{
    
    printf("Enter patient's first name: ");
    scanf("%s", &fname);
    printf("Enter patient's last name: ");
    scanf("%s", &lname);

    
    strcpy(arr[count].fname,fname);
    strcpy(arr[count].lname,lname);
    arr[count].patientId = rand()%1000;
    count++;
    if(count == 50){
        printf("Array is full\n");
        break;
    }
}while(strcmp(arr[count].fname,"-1")!=0);

sortPatients(arr,count);

for(int i=0;i<count;i++){
    printf("%s %s %d\n",arr[i].fname,arr[i].lname,arr[i].patientId);
}

}

void sortPatients(Patient *arr,int count){
    int i,j;
    Patient temp;
    for(i=0; i<count; i++){
        for(j=0;j<count;j++){
            if(arr[i].patientId > arr[j].patientId){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
