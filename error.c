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

/*switch case to handle errors*/
char* error(int error_number)
{
	switch(error_number)
	{
	case 1:
		return "INVALID_OPERATION";
		break;
	case 2:
		return "LIMIT_OVERFLOW";
		break;
	case 3:
		return "INVALID_STRING";
		break;
	}
	return NULL;
}
