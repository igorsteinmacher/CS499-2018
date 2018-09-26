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
#include <stdio.h>
#include "parser.h"

/*
 * @brief Determines if char is a integer
 *
 * @param curr Is a single char
 *
 * @return Bool indicating success or failure
 */
bool isDigit(char curr){
    if (curr >= '0' && curr <= '9') return true;
    return false;
}

/*
 * @brief Determines if inputted string contains only numbers and a single "."
 *
 * @param numString[] Null terminated string containing a floating
 *        point number
 *
 * @return Bool indicating success or failure
 */
bool isValid(char *numString){
    if(numString == NULL){
        return false;
    }

    int index = 0;
    int decimal_occured = 0;

    if(numString[0] == '-'){
        index = 1;
    }

    for(int i = index; numString[i] != '\0'; i++) {
        if(!isDigit(numString[i]) && numString[i] != '.'){
            return false;
        }
        else if (numString[i] == '.'){
            if (decimal_occured == 1){
                return false;
            } else {
                decimal_occured = 1;
            }
        }
    }
    return true;
}

/*
 * @brief Determines the length of a given string
 *
 * @param *str Null terminated string to be measured
 *
 * @return The number of char's in the string, not
 *         including the terminating null. 0 if null or
 *         first char is null
 */
int strLength(char *str){
    int strLen = 0;

    if(str == NULL){
        return 0;
    }

    while( *str != '\0'){
        strLen++;
        str++;
    }

    return strLen;
}

/*
 * @brief Removes any leading zeros from the given string
 *
 * @param *numString The str representing the floating point num
 *
 * @return Bool stating whether leading zeros were removed or not
 */
bool removeLeadingZeros(char *numString){
    char * numStrIter = numString;
    int numZeros = 0;
    bool isNegative = false;

    if(numString == NULL){
        return false;
    }

    // Skip the -
    if(*numStrIter == '-'){
        numStrIter++;
        isNegative = true;
    }

    // Determine if and how many 0's to remove
    while(*numStrIter == '0'){
        numZeros++;
        numStrIter++;
    }

    // Move chars down str for the # of zeros
    char *numStrBase = numString;
    numStrIter = numString;

    if(isNegative){
        numStrBase++;
        numStrIter++;
    }

    numStrIter += numZeros;

    if(numZeros != 0){
        while(*numStrIter != '\0'){
            *numStrBase = *numStrIter;
            numStrBase++;
            numStrIter++;
        }

        *numStrBase = '\0';

        return true;
    } else {
        return false;
    }
}

/*
 * @brief Removes any trailing zeros from the given string
 *
 * @param *numString The str representing the floating point num
 *
 * @return Bool stating whether trailing zeros were removed or not
 */
bool removeTrailingZeros(char *numString){
    if(numString == NULL){
        return false;
    }

    int strLen = strLength(numString);
    int numZeros = 0;

    for(int i = strLen - 1; numString[i] == '0'; i--){
        numZeros++;
        numString[i] = '\0';
    }

    if(numZeros > 0){
        return true;
    } else {
        return false;
    }
    return true;
}

/*
 * @brief Removes any leading spaces from a string
 *
 * @param The str representing the floating point num
 *
 * @return Bool indicating whether leading spaces where removed or not
 */
bool removeLeadingSpaces(char *numString){
    char * numStrIter = numString;
    int numSpaces = 0;

    if(numString == NULL){
        return false;
    }

    // Determine if and how many spaces to remove
    while(*numStrIter == ' '){
        numSpaces++;
        numStrIter++;
    }

    // Move chars down str for the # of zeros
    char *numStrBase = numString;
    numStrIter = numString;

    numStrIter += numSpaces;

    if(numSpaces != 0){
        while(*numStrIter != '\0'){
            *numStrBase = *numStrIter;
            numStrBase++;
            numStrIter++;
        }

        *numStrBase = '\0';

        return true;
    } else {
        return false;
    }
}

/*
 * @brief Removes any trailing spaces from the given string
 *
 * @param *numString The str representing the floating point num
 *
 * @return Bool stating whether trailing spaces were removed or not
 */
bool removeTrailingSpaces(char *numString){
    if(numString == NULL){
        return false;
    }

    int strLen = strLength(numString);
    int numSpaces = 0;

    for(int i = strLen - 1; numString[i] == ' '; i--){
        numSpaces++;
        numString[i] = '\0';
    }

    if(numSpaces > 0){
        return true;
    } else {
        return false;
    }
    return true;
}

/*
 * @brief Function to add a leading 0 if there is no number in
 *        front of ".", i.e. ".01"
 *
 * @param numString[] Null terminated string containing a floating
 *        point number, newString[] is the updated string with leading zero.
 *        If a zero is not needed the numString will not be changed
 *
 * @return new char array with added 0
 */
bool addLeadingZero(char *numString, char *new_string){
    if(numString[0] != '.'){
        return false;
    } else {
        strCat(new_string, numString);
    }
    return true;
}

/*
 * @brief function to return string left of  "."
 *
 * @param numString[] Null terminated string containing a floating
 *        point number, newString[] is placeholder where the Characteristic
 *        will be stored into
 *
 * @return char array of characteristic
 */
char *getCharacteristic(char *numString, char *newString){
    for(int i = 0; numString[i] != '.'; i++){
        newString[i] = numString[i];
    }
    return newString;
}

/*
 * @brief function to return string right of  "."
 *
 * @param numString[] Null terminated string containing a floating
 *        point number, newString[] is placeholder where the Mantissa
 *        will be stored into
 *
 * @return char array of mantissa
 */
char *getMantissa(char *numString, char *newString){
    int numStringIndex = 0;
    int newStringIndex = 0;
    while(numString[numStringIndex] != '.'){
        numStringIndex++;
    }
    for(int i = numStringIndex+1; numString[i] != '\0'; i++){
        newString[newStringIndex] = numString[i];
        newStringIndex++;
    }
    return newString;
}

/*
 * @brief Func to return the length of the mantissa
 *
 * @param numString[] Null terminated string containing a floating
 *        point number
 *
 * @return Int of mantissa length
 */
int getMantissaLength(char *numString){
    int mantissaIndex = 0;
    int length = 0;
    while(numString[mantissaIndex] != '.'){
        mantissaIndex++;
    }
    for(int i = mantissaIndex+1; numString[i] != '\0'; i++){
        length++;
    }
    return length;
}

/*
 * @brief Takes two strs and combines them, putting the source at the
 *        end of the destination string
 *
 * @detail Ensure the destination str is big enough for the two str
 *
 * @param *dest Str that source will be combined into
 *
 * @param *source Str that will be put at the end of the dest
 *
 * @return Str containing dest and source combined
 */
char * strCat(char *dest, char *source){
    char *copyPtr = dest + strLength(dest);

    while(*source != '\0'){
        *copyPtr++ = *source++;
    }

    *copyPtr = '\0';

    return dest;
}

/*
 * @brief Compares two strings, 0 if they are equal
 *
 * @param *str1 Str that will be compared
 *
 * @param *str2 Str that will be compared
 *
 * @return 0 indicates the two str are the same
 */
int strCmp(char *str1, char *str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

/*
 * @brief Copies an str from source into dest
 *
 * @param dest[] Str that will hold copied array
 *
 * @param source[] Str that will be copied into dest
 */
char *strCpy(char *destination, char *source)
{
    char *start = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // add '\0' at the end
    return start;
}


#endif  // PARSER_C
