/*
 * @file main.c
 *
 * @author Jasque Saydyk [contribute your name when you add]
 *
 * @brief Runs the main loop of the program, taking in input
 *        and displaying the output
 *
 * @note This file may or may not be necessary, not required by
 *       the requirements, but added for completeness and usability
 */
#include <stdlib.h>
#include <stdio.h>
#include "string_to_int_converter.h"
#include "parser.h"

#define AVG_STR 60

int main(int argc, char *argv[]){
    char *userFloat = calloc(1, (sizeof(char) * AVG_STR));
    int c, n, d;
    bool charOutput = false;
    bool mantOutput = false;

    while(true){

        // Take in program input
        printf("Input float(quit): ");
        fgets(userFloat, AVG_STR, stdin);

        // Clear buffer
        // Some other day, strchr() is in string.h

        // Quit if user types in quit
        if(strCmp(userFloat, "quit") == 0){
            break;
        }

        // Run functions
        charOutput = characteristic(userFloat, &c);
        mantOutput = mantissa(userFloat, &n, &d);

        // Print output
        if(charOutput == false || mantOutput == false){
            printf("Functions failed to interpet input\n");
        } else {
            printf("The characteristic is %d, numerator is %d, denominator is %d\n", c, n, d);
        }
    }

    return 0;
}
