/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#include <string.h>
#include "roman_string_to_decimal_value.h"
#define NEGATIVE 0
#define SUCCESS 1

/*this function is used to check the valid roman characters*/
int isRomanNumberValid(char roman_value[])
{

	int roman_string_pointer = 0; // intitlizing the pointer to the first element of the string
	int invalid_roman_string = SUCCESS; // initlizing the variable as successful 
	/*while condition runs until all the characters in the string is verified*/	
	while(roman_value[roman_string_pointer]) 
	{
		/*if condition to check if the value fo the string is less than zero return negative and exit out of the loop*/
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
		{
			invalid_roman_string = NEGATIVE; 
			break;
		}
		/*if condition */
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

