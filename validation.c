#include <string.h>
#include "calculator.h"
#include "roman_string_to_decimal_value.h"
#define NEGATIVE 0

int isRomanNumberValid(char roman_value[])
{	
	int roman_to_decimal_digit_value(char roman_character);
	int roman_string_pointer = 0;
	int invalid_roman_string = 0;
	printf("Roman string in InvalidRoman = %s \n",roman_value);
	while(roman_value[roman_string_pointer] < 0)
	{
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
	{
		 invalid_roman_string = NEGATIVE;
	}	
		if((strlen(roman_value) -roman_string_pointer) > 2){
			if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
				{	
					invalid_roman_string = NEGATIVE;
				}
	}
}/*End of while loop*/
return invalid_roman_string;
} /*End of Function*/
