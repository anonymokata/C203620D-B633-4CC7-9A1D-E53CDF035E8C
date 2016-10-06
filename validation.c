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
#include "validation.h"
#include "roman_string_to_decimal_value.h"
#define FAILURE 0
#define SUCCESS 1

/*this function is used to check for invalid roman characters*/
int is_roman_number_valid(char roman_value[])
{
	int roman_string_pointer = 0; // initializing the pointer to the first element of the string
	int validity_check = SUCCESS; // initializing the variable as valid 
	/*while condition runs until all the characters in the string is verified*/	
	while(roman_value[roman_string_pointer]) 
	{
		/*if condition to check if the value of the string is less than zero. If yes, returns failure and exits out of the loop*/
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
		{
			validity_check = FAILURE; 
			break;
		}
		/*if condition to check the order of the string*/
		if((strlen(roman_value) -roman_string_pointer) > 2)
		{
			if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
			{
				validity_check = FAILURE;
				break;
			}
		}
		roman_string_pointer++;
	}/*End of while loop*/
	return validity_check;
} /*End of Function*/
