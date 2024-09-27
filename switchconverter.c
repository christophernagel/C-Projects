#include <stdio.h>
#include <ctype.h>


double fahrenheittoCelsius(double fahrenheit){
    return (fahrenheit * (9.0/5.0)) + 32;
}

double fahrenheittoKelvin(double fahrenheit){
    return ((fahrenheit * (9.0/5.0)) + 32) + 273.15;
}

double kelvintoFahrenheit(double kelvin){
    return  ((kelvin - 273.15) - 32) * (5.0/9.0);
}

double kelvintoCelsius(double kelvin){
    return (kelvin - 273.15);
}

double celsiustoFahrenheit(double celsius) {
    return (celsius - 32) * (5.0/9.0);
}

double celsiustoKelvin(double celsius){
    return (celsius + 273.15);
}

double convTemp(double input, char fromUnit, char toUnit) {

    switch(toupper(fromUnit)) {

        case 'F':
            switch(toupper(toUnit)) {
                case 'F': return input;
                case 'K': return fahrenheittoKelvin(input);
                case 'C': return fahrenheittoCelsius(input);
                default: return 0;
            }
        case 'K':
            switch(toupper(toUnit)) {
                case 'F': return kelvintoFahrenheit(input);
                case 'K': return input;
                case 'C': return kelvintoCelsius(input);
                default: return 0;
            }
        case 'C':
            switch(toupper(toUnit)) {
                case 'F': return celsiustoFahrenheit(input);
                case 'K': return celsiustoKelvin(input);
                case 'C': return input;
                default: return 0;
            }
        default:
            return 0;
    }
 
}

int main() {
    char fromUnit, toUnit;
    double input, result;

    printf("Enter a unit (C, F, K): ");
    scanf(" %c", &fromUnit);

    printf("Enter a unit to convert to (C, F, K): ");
    scanf(" %c", &toUnit);

    printf("Enter temperature value: ");
    scanf("%lf", &input);

    result = convTemp(input, fromUnit, toUnit);


    if (result != 0 || (fromUnit == toUnit)) {
        printf("%.2lf°%c is %.2lf°%c\n", input, toupper(fromUnit), result, toupper(toUnit));
    } else {
        printf("Invalid conversion.\n");
    }

    return 0;
}