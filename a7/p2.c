#include <stdio.h>

//prototype 
int tax1(int income);
int tax2(int income);
int tax3(int income);

//main
int main(void){
    int income = 0;
    int aftIncome = 0;

    //get input
    printf("Enter income: ");
    scanf("%d",&income);

    int (*tax1Ptr)(int) = tax1;
    int (*tax2Ptr)(int) = tax2;
    int (*tax3Ptr)(int) = tax3;

    if (income >80000)
    {
        aftIncome = income - ((*tax3Ptr)(income-80000)
                            + (*tax2Ptr)(60000)
                            + (*tax1Ptr)(20000));
    }
    else if (income<=80000 && income >=20000)
    {
        aftIncome = income - ((*tax2Ptr)(income-20000)
                            + (*tax1Ptr)(20000));
    }
    else if (income<20000)
    {
        aftIncome = income - (*tax1Ptr)(income);
    }

    printf("Income after tax: %d",aftIncome);
}

//function definitions

int tax1(int income){
    return .1 * income;
}
int tax2(int income){
    return .25 * income;
}
int tax3(int income){
    return .4 * income;
}