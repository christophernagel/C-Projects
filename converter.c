#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


double convTemp(double input, char unit) {
    double res;

    switch(unit) {
        case 'C':
        res = (input * (9/5)) + 32;
        break;
        case 'F':
        res = (input - 32) * (5/9);
        break;
    }
    return res;
}

int main() {
    char unit;
    double input, res;

    //read operator
    printf("Enter a unit (C or F): ");
    scanf("%c", &unit);

    //read inputs
    printf("Enter temperature reading: ");
    scanf("%lf", &input);

    res = convTemp(input, unit);

    //print result

    printf("Converted Temp: %.lf\n", res);

    return 0;
    }