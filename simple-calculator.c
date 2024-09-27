#include<stdio.h>
#include<float.h>

double basicCalc(double num1, double num2, char op){
    double res;

    switch(op){
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2; 
        break;
    case '/':
        res = num1 / num2;
        break;
    default:
        printf("Operator not defined ./n");
        return -DBL_MAX;
    }
    return res;
}



int main() {
    char op;
    double num1, num2, res;

    //read operator
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &op);

    //read inputs
    printf("Enter two inputs: ");
    scanf("%lf %lf", &num1, &num2);

    res = basicCalc(num1, num2, op);

    //print result

    if (res != -DBL_MAX)
        printf("%.lf\n", res);

        return 0;
    }