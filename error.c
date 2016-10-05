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
#include "error.h"

/*switch case to handle errors*/
char* error(ERRORS error_value)
{
	char* error_string;	
	
	switch(error_value)
	{
	case INVALID_OPERATION:
		error_string = "INVALID_OPERATION";
		break;
	case LIMIT_OVERFLOW:
		error_string = "LIMIT_OVERFLOW";
		break;
	case INVALID_STRING:
		error_string =  "INVALID_STRING";
		break;
	}
	return error_string;
}
