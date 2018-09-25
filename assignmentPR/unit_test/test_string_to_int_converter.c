/*
 * @file test_string_to_int_converter.c
 *
 * @author Jasque Saydyk
 *
 * @brief Unit tests for the string_to_int_converter.c
 */
#include <stdlib.h>
#include <stdio.h>
#include "../src/string_to_int_converter.h"

// @brief testing mantissa floating point string (2.351)
void test_mantissa_Success1(void){
    char test_string[] = "2.351";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 351 && denominator == 10000){
        printf("Success: test_mantissa_Success1\n");
    } else {
        printf("Error: test_mantissa_Success1\n");
    }
}

// @brief testing mantissa floating point string (2.0)
void test_mantissa_Success2(void){
    char test_string[] = "2.0";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 0 && denominator == 0){
        printf("Success: test_mantissa_Success2\n");
    } else {
        printf("Error: test_mantissa_Success2\n");
    }
}

// @brief testing mantissa floating point string (2.)
void test_mantissa_Success3(void){
    char test_string[] = "2.";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 0 && denominator == 0){
        printf("Success: test_mantissa_Success3\n");
    } else {
        printf("Error: test_mantissa_Success3\n");
    }
}

// @brief testing mantissa floating point string (-2)
void test_mantissa_Success4(void){
    char test_string[] = "-2";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 0 && denominator == 0){
        printf("Success: test_mantissa_Success4\n");
    } else {
        printf("Error: test_mantissa_Success4\n");
    }
}

// @brief testing mantissa floating point string (2.123000)
void test_mantissa_Success5(void){
    char test_string[] = "2.123000";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 123 && denominator == 1000){
        printf("Success: test_mantissa_Success5\n");
    } else {
        printf("Error: test_mantissa_Success5\n");
    }
}

// @brief testing mantissa floating point string (2.123   )
void test_mantissa_Success6(void){
    char test_string[] = "2.123   ";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 123 && denominator == 1000){
        printf("Success: test_mantissa_Success6\n");
    } else {
        printf("Error: test_mantissa_Success6\n");
    }
}

// @brief testing mantissa floating point string (2.12300  )
void test_mantissa_Success7(void){
    char test_string[] = "2.12300  ";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == true && numerator == 123 && denominator == 1000){
        printf("Success: test_mantissa_Success7\n");
    } else {
        printf("Error: test_mantissa_Success7\n");
    }
}

// @brief testing mantissa floating point string (2.351.0)
void test_mantissa_Fail1(void){
    char test_string[] = "2.351.0";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == false){
        printf("Success: test_mantissa_Fail1\n");
    } else {
        printf("Error: test_mantissa_Fail1\n");
    }
}

// @brief testing mantissa floating point string (2.351.0)
void test_mantissa_Fail2(void){
    char *test_string = NULL;
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == false){
        printf("Success: test_mantissa_Fail2\n");
    } else {
        printf("Error: test_mantissa_Fail2\n");
    }
}

// @brief testing mantissa floating point string ( )
void test_mantissa_Fail3(void){
    char test_string[] = " ";
    int numerator = 0;
    int denominator = 0;

    bool output = mantissa(test_string, &numerator, &denominator);

    if(output == false){
        printf("Success: test_mantissa_Fail3\n");
    } else {
        printf("Error: test_mantissa_Fail3\n");
    }
}

// @brief testing characteristic floating point string (02.351)
void test_characteristic_Success1(void){
    char test_string[] = "02.351";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == true && c == 2){
        printf("Success: test_characteristic_Success1\n");
    } else {
        printf("Error: test_characteristic_Success1\n");
    }
}

// @brief testing characteristic floating point string (   02.351)
void test_characteristic_Success2(void){
    char test_string[] = "   02.351";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == true && c == 2){
        printf("Success: test_characteristic_Success2\n");
    } else {
        printf("Error: test_characteristic_Success2\n");
    }
}

// @brief testing characteristic floating point string (2)
/*void test_characteristic_Success3(void){
    char test_string[] = "2";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == true && c == 2){
        printf("Success: test_characteristic_Success3\n");
    } else {
        printf("Error: test_characteristic_Success3\n");
    }
}*/

// @brief testing characteristic floating point string (02.351)
void test_characteristic_Success4(void){
    char test_string[] = " .351";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == true && c == 0){
        printf("Success: test_characteristic_Success4\n");
    } else {
        printf("Error: test_characteristic_Success4\n");
    }
}

// @brief testing characteristic floating point string (2.2.351)
void test_characteristic_Fail1(void){
    char test_string[] = "2.2.351";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == false){
        printf("Success: test_characteristic_Fail1\n");
    } else {
        printf("Error: test_characteristic_Fail1\n");
    }
}

// @brief testing characteristic floating point string (NULL)
void test_characteristic_Fail2(void){
    char *test_string = NULL;
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == false){
        printf("Success: test_characteristic_Fail2\n");
    } else {
        printf("Error: test_characteristic_Fail2\n");
    }
}

// @brief testing characteristic floating point string ( )
void test_characteristic_Fail3(void){
    char test_string[] = " ";
    int c = 0;

    bool output = characteristic(test_string, &c);

    if(output == false){
        printf("Success: test_characteristic_Fail3\n");
    } else {
        printf("Error: test_characteristic_Fail3\n");
    }
}
