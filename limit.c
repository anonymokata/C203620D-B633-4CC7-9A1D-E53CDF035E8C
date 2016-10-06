/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#include "limit.h"
#define MAX_VALUE 3999 // maximum positive number for the roman string
#define MIN_VALUE -3999 //minimum negative number for the roman string 

/*------------------------------------*/
/*function to check weather the subtraction result of two decimal numbers is greater than the limit.
total_subtracted_value: this will hold the decimal value after subtracting the two decimal values
 */
BOOL check_limit_of_subtracted_numbers(int total_subtracted_value)
{
	bool validate;	
	if(total_subtracted_value > MAX_VALUE || total_subtracted_value < MIN_VALUE)
		validate =  TRUE;
	else
		validate =  FALSE;
return validate;
}

/*----------------------------------------*/
/*function to check weather the added result of two decimal numbers is greater than the limit
total_sum_value: this will hold the decimal value after adding the two decimal values
 */
BOOL check_limit_of_added_numbers(int total_sum_value)
{	
	bool validate;
	if(total_sum_value > MAX_VALUE)
		validate =  TRUE;
	else
		validate = FALSE;
return validate;
}
/*function to check weather the subtracted result of two decimal number is NULL*/
BOOL is_subtracted_number_null(int total_subtracted_value)
{
	bool validate;	
	if(total_subtracted_value == 0)
		validate = FALSE;
	else
		validate = TRUE;
return validate;
}
