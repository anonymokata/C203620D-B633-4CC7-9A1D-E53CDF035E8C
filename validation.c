#include <string.h>
#include "roman_string_to_decimal_value.h"
#define NEGATIVE 0
#define SUCCESS 1

int isRomanNumberValid(char roman_value[])
{

	int roman_string_pointer = 0;
	int invalid_roman_string = SUCCESS;
	while(roman_value[roman_string_pointer])
	{
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
		{
			invalid_roman_string = NEGATIVE;
			break;
		}

		if((strlen(roman_value) -roman_string_pointer) > 2)
		{
			if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
			{
				invalid_roman_string = NEGATIVE;
				break;
			}
		}

		roman_string_pointer++;
	}/*End of while loop*/
	return invalid_roman_string;
} /*End of Function*/

