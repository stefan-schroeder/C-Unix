#include <stdio.h>
#include <stdlib.h>

struct RGB{
    unsigned int red: 8;
    unsigned int green: 8;
    unsigned int blue: 8;
};

int main(void){
    struct RGB color;
    int tempRed = 0;
    int tempGreen = 0;
    int tempBlue = 0;

    printf("Enter the red value (0-255): ");
    scanf("%d", &tempRed);
    printf("\n");
    printf("Enter the green value (0-255): ");
    scanf("%d", &tempGreen);
    printf("\n");
    printf("Enter the blue value (0-255): ");
    scanf("%d", &tempBlue);
    printf("\n");

    color.red = tempRed;
    color.green = tempGreen;
    color.blue = tempBlue;

    printf("Your color is: #%02x%02x%02x", color.red, color.green, color.blue);
    return 0;
}