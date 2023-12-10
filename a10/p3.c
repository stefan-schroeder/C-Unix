#include <stdio.h>
#include <stdlib.h>

// create bitfield for date
struct date{
    unsigned int year: 32;
    unsigned int month: 16;
    unsigned int day: 8;
};

void add_days(struct date *d, int *dp){

    if(d->day + *dp > 30){
        d->day = d->day + *dp - 30;
        if(d->month + 1 > 12){
            d->year++;
            d->month = 1;
        }
        else{
            d->month++;
        }
    }
    else{
        d->day += *dp;
    }
}

int main(void){
    int days = 0;
    int tempDay = 0;
    int tempMonth = 0;
    int tempYear = 0;
    int *dp = &days;
    struct date *d = malloc(sizeof(struct date));

    printf("Enter the date (YYYY/MM/DD): ");
    scanf("%u/%u/%u", &tempYear, &tempMonth, &tempDay);

    d->year = tempYear;
    d->month = tempMonth;
    d->day = tempDay;
    printf("Enter number of days to add: ");
    scanf("%d", &days);
    add_days(d, dp);
    printf("The date after %d days is %u/%u/%u", *dp, d->year, d->month, d->day);
    return 0;
}
