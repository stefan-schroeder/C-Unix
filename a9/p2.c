#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Price{
    double usd;
    double gbp;
    double eur;
};

int convert(struct Price *Price, const char *currency){

    const double usd_to_gbp = 0.81;
    const double usd_to_eur = 0.92;
    
    if (tolower(currency[0]) == 'u'){
        Price->gbp = Price->usd * usd_to_gbp;
        Price->eur = Price->usd * usd_to_eur;
        Price->usd = Price->usd;
    }
    else if (tolower(currency[0])=='g'){
        Price->usd = Price->gbp / usd_to_gbp;
        Price->eur = Price->usd * usd_to_eur;
        Price->gbp = Price->gbp;
    }
    else if (tolower(currency[0])=='e'){
        Price->usd = Price->eur / usd_to_eur;
        Price->gbp = Price->usd * usd_to_gbp;
        Price->eur = Price->eur;
    }
    else{
        printf("Invalid currency\n");
        return 1;
    }
    return 0;
}

int main(void){
    double price;
    char currency[4];

    printf("Enter the price of the product: ");
    scanf("%lf", &price);
    printf("Enter the currency (USD, EUR, or GBP): ");
    scanf("%s", currency);
    struct Price Price;
    Price.usd = 0;
    Price.gbp = 0;
    Price.eur = 0;    
    
    if (tolower(currency[0]) == 'u'){
        Price.usd = price;
        convert(&Price, currency);
    }
    else if(tolower(currency[0]) == 'g'){
        Price.gbp = price;
        convert(&Price, currency);
    }
    else if(tolower(currency[0]) == 'e'){
        Price.eur = price;
        convert(&Price, currency);
    }
    else{
        printf("Invalid currency\n");
        return 0;
    }
    
    printf("Price in USD: %.2lf\n", Price.usd);
    printf("Price in EUR: %.2lf\n", Price.eur);
    printf("Price in GBP: %.2lf\n", Price.gbp);
    return 0;   
}