/*
 * @file string_to_int_converter.h
 *
 * @author Jasque Saydyk
 *
 * @brief Converts a null terminated string containing a floating
 *        point number into integers representing the
 *        characteristic, numbers before the ".", and the
 *        mantissa, numbers after the "."
 *
 *        The mantissa will be divided into two separate numbers,
 *        the numerator and the denominator, which are used to
 *        construct the number as a float
 *
 * @note Design around edge cases like "10", "0.01", ".01"
 */
#ifndef STRING_TO_INT_CONVERTER_H
#define STRING_TO_INT_CONVERTER_H

// Struct Declarations, if needed
typedef enum {
	false,
	true
} bool;

// Function Prototypes
bool characteristic(char numString[], int *c);
bool mantissa(char numString[], int *numerator, int *denominator);

#endif  // STRING_TO_INT_CONVERTER_H
