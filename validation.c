#include <string.h>
#include "calculator.h"
#include "roman_string_to_decimal_value.h"
#define NEGATIVE -1

int isRomanNumberValid(char roman_value[])
{	
	int roman_to_decimal_digit_value(char roman_character);
	int roman_string_pointer = 0;
	int invalid_roman_string = 0;
	while(roman_value[roman_string_pointer])
	{
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
		return NEGATIVE;
	
if((strlen(roman_value) -roman_string_pointer) > 2)
	if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
	return NEGATIVE;
	}
return invalid_roman_string;
}
