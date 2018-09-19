/*
 * @file parser.c
 *
 * @author Jasque Saydyk
 *
 * @brief Provides functions to read numString[] and determine if
 *        it is formatted correctly or not
 *
 * @note Design around edge cases like "10", "0.01", ".01"
 */
#ifndef PARSER_C
#define PARSER_C

#include <stdlib.h>
#include "parser.h"

// TODO: Function to determine if inputted string contains only
//       numbers and a single "."

// TODO: Function to remove leading and trailing 0's from number
//       may need to split into two different functions

// TODO: Function to add a leading 0 if there is no number in
//       front of ".", i.e. ".01"

// TODO: Maybe a function to convert a given string to int

// TODO: Maybe a function to return two strings split along "."

// TODO: Maybe a function to return a string representing the
//       10 to the power of X based on the inputted int/string
//       i.e. input->123 for 0.123 output->"1000"

// Some of the above functions maybe better placed in
// string_to_int_converter.c

// Any other functions necessary for operation of stringtoint

#endif  // PARSER_C
