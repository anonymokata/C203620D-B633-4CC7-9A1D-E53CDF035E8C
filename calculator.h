/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */

#ifndef calculator_H
#define calculator_H

typedef char* ROMAN_TYPE;
typedef enum{ ADD, SUBTRACT} ROMAN_OPERATION;
ROMAN_TYPE calculate_roman_numbers(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_OPERATION operation, ROMAN_TYPE result);

#endif
