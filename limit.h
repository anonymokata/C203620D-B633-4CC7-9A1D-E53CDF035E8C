/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#ifndef limit_H
#define limit_H
//typedef enum {TRUE = 1, FALSE = 0} BOOL;
int isSubtractedNumberNull(int total_subtracted_value);
int check_limit_of_added_numbers(int total_sum_value);
int check_limit_of_subtracted_numbers(int total_subtracted_value);
#endif
