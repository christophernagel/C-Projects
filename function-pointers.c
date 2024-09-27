#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int foo(int x, int y)
{
    return x + y;
}

bool p(int x) {
    return x % 2 == 0;
}

bool q(int x) {
    return x % 2 != 0;
}

// Function that prints array elements that satisfy a given predicate
// Parameters:
//   xs: Array of integers
//   predicate: Pointer to a boolean function that takes an int as input
void print_if(int xs[10], bool (*predicate)(int))
{
    for (int i = 0; i < 10; i++)
    {
        if (predicate(xs[i]))
            printf("%d\n", xs[i]);
    }
}

int main(void) {
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //int (*f)(int, int) = foo;
    //printf("%d\n", f(3, 4));
    print_if(xs, q);

    return 0;
}