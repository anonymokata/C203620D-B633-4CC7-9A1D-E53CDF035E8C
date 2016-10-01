#include "string.h"
#include "calculator.h"
#define NEGATIVE -1

int isRomanNumberValid(char roman_value[])
{
	int roman_string_pointer = 0;
if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
	{
            return NEGATIVE;
	}
if((strlen(roman_value) -roman_string_pointer) > 2)
	if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
	return NEGATIVE;
}
