#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

double convTemp(double input, char unit) {
    if (unit == 'C' || unit == 'c') {
        return (input * (9.0/5.0)) + 32;
    } else if (unit == 'F' || unit == 'f') {
        return (input - 32) * (5.0/9.0);
    } else {
        printf("Invalid unit, please us C or F. \n");
        return 0;
    }
    
}

int main() {
    char unit;
    double input, res;

    //read operator
    printf("Enter a unit (C or F): ");
    scanf(" %c", &unit);

    //read inputs
    printf("Enter temperature reading: ");
    scanf("%lf", &input);

    res = convTemp(input, unit);

    //print result

    if (unit =='C' || unit == 'c') {
        printf("%.2lf°C is %.2lf°F\n", input, res);
    } else if (unit == 'F' || unit == 'f') {
        printf("%.2lf°F is %.2lf°C\n", input, res);
    }

    return 0;
}