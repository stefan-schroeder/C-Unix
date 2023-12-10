#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


union WeatherData{
    double temp;
    double humidity;
    double windSpeed;
    double windDirection;
};

int main(void){
    int choice;
    union WeatherData data;
    printf("What type of data do you want to collect?\n");
    printf("1. Temperature\n");
    printf("2. Humidity\n");
    printf("3. Wind Speed\n");
    printf("4. Wind Direction\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter the temperature: ");
        scanf("%lf", &data.temp);
        printf("Temperature: %.2lf", data.temp);
        break; 
    case 2: 
        printf("Enter the humidity: ");
        scanf("%lf", &data.humidity);
        printf("Wind Humidity: %.2lf", data.humidity);
        break;
    case 3:
        printf("Enter the Wind Speed: ");
        scanf("%lf",&data.windSpeed);
        printf("Wind Speed: %.2lf", data.windSpeed);
        break;
    case 4:
        printf("Enter the Wind Direction: ");
        scanf("%lf", &data.windDirection);
        printf("Wind Direction: %.2lf", data.windDirection);
        break;
    default:
        return 1;
        break;
    }
}