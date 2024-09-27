//determine neccessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input;
    //prerun ------------------------------------------
    //generate number on init, seeded from current time
    srand(time(NULL));
    // num range
    int upper_bound = 100;
    int lower_bound = 0;
    int correctNum = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    
    //running------------------------------------------
    printf("Guess a number between 0 - 100: ");
    while (scanf("%d", &input) == 1) {
        //if user guess is higher, printf, too high
        if (input < correctNum) {
            printf("Guess Higher! Try again:");
        //else if user guess is lower, printf, too low
        } else if(input > correctNum) {
            printf("Guess Lower! Try again:");
        //else user is correct    
        } else {
            printf("Correct!\n");
            break;
        }
    }
    return 0;
}


    
    
        
    
    



//----------------



//main
    //user selected number

    //call prerun

    //return result

