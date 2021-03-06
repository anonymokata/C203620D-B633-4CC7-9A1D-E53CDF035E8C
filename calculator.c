/*
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c
Date		: 10/4/2016
 */

#include <string.h> // to handle string objects
#include <stdlib.h> // to handle pre-defined function: abs()
#include "calculator.h"
#include "roman_string_to_decimal_value.h" // this header is used to call functions to convert roman_string to decimal_value
#include "decimal_value_to_roman_string.h" // this header is used to call functions to convert decimal value to roman string
#include "validation.h" // this header is used to validate the roman string
#include "limit.h" // this header is used to check the limitation of maximum roman string
#include "error.h" // this header is used to handle errors in the function
#define FALSE 0 // to check the condition if condition fails it returns false
#define TRUE 1  //to check the condition is condition passes it will return true

static ROMAN_TYPE add(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static ROMAN_TYPE subtract(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result);

/* calculate_roman_numbers function is used to receive first string, second string,
 operation to perform add/subtract and, buffer to store the result :
const ROMAN_TYPE first_roman_number : to hold the pointer of first roman string.
const ROMAN_TYPE second_roman_number: to hold the pointer of second roman string.
ROMAN_OPERATION operation: add/subtract operation will be passed in the variable.
ROMAN_TYPE result: to store the result after the roman operation.*/
ROMAN_TYPE calculate_roman_numbers(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_OPERATION operation, ROMAN_TYPE result)
{
	/*switch case is used to choose addition or subtraction operation based on the input provided by the user*/
	switch(operation)
	{
	case ADD:
		// this function passes parameters to perform the addition operation.
		result = add(first_roman_number,second_roman_number,result);
		break;
	case SUBTRACT:
		// this function passes parameters to perform the subtraction operation.
		result = subtract(first_roman_number,second_roman_number,result);
		break;
	default:
		result = error(INVALID_OPERATION); // default case returns error.
	}
	return result;
}
/*-----------------------------------------*/
/*add function to perform addition of roman numbers:
const ROMAN_TYPE first_roman_number : to hold the pointer of first roman string.
const ROMAN_TYPE second_roman_number: to hold the pointer of second roman string.
ROMAN_TYPE result: to store the result after the roman operation.*/
static ROMAN_TYPE add(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	/* is_roman_number_valid functions is used to check the valid roman character
	   if the roman number is valid it returns true else returns false
	   if both roman numbers are valid it will perform further operations else it will return error*/
	if( is_roman_number_valid(first_roman_number) && is_roman_number_valid(second_roman_number))
	{
		/* int variable first_number is used to store decimal value of the first roman number,
			roman_string_to_decimal_value function is used here to convert roman string to decimal value*/
		int first_number = roman_string_to_decimal_value(first_roman_number);
		/* int variable second_number is used to store decimal value of the second roman number
			roman_string_to_decimal_value function is used here to convert roman string to decimal value*/
		int second_number = roman_string_to_decimal_value(second_roman_number);
		/*check_limit_of_added_numbers is used to check the maximum limit of the decimal value after addition of two numbers.
			If condition returns true it will execute decimal_number_to_roman_string function to convert back to
			roman string of the total number else returns error string  */
		if(check_limit_of_added_numbers(first_number + second_number) == TRUE)
		{
			//function to convert decimal number to roman string
			result = decimal_number_to_roman_string((first_number + second_number),result);
		}
		else 
		{	/*if value is greater than MAX_VALUE*/
			result = error(LIMIT_OVERFLOW);
		}
	}
	else  
	{
		/*for passing invalid strings*/
		result =  error(INVALID_STRING);
	}
	return result; // to return the final result after addition operation
}

/*subtract function to perform subtraction of roman numbers:
const ROMAN_TYPE first_roman_number : to hold the pointer of first roman string
const ROMAN_TYPE second_roman_number: to hold the pointer of second roman string
ROMAN_TYPE result: to store the result after the roman operation*/
static ROMAN_TYPE subtract(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	/* is_roman_number_valid functions is used to check the valid roman string.
	   If the roman number is valid it returns true else returns false.
	   If both roman numbers are valid it will performs further operation else it will return error*/
	if(is_roman_number_valid(first_roman_number) && is_roman_number_valid(second_roman_number))
	{
		/* int variable first_number is used to store decimal value of the first roman number,
			roman_string_to_decimal_value function is used to convert roman string to decimal value*/
		int first_number = roman_string_to_decimal_value(first_roman_number);
		/* int variable second_number is used to store decimal value of the second roman number,
			roman_string_to_decimal_value function is used to convert roman string to decimal value*/
		int second_number = roman_string_to_decimal_value(second_roman_number);
		/*check_limit_of_subtracted_numbers function is used to check 
			the maximum limit of the decimal value. Here abs() function is
			used as there are no negative numbers or zero value in roman characters */
		if(check_limit_of_subtracted_numbers(abs(first_number - second_number)) == TRUE)
		{
			if(is_subtracted_number_null(abs(first_number - second_number)) == FALSE)
			{				
			/* decimal_number_to_roman_string function is used to convert decimal value to roman string and returns the result */
			result = decimal_number_to_roman_string(abs(first_number - second_number),result);
			}
			else
			{
				/*if subtraction if two numbers is NULL*/
				result = error(NULL_VALUE);			
			}
		}
		else
		{  
			/*if subtraction of two numbers is greater than MAX_VALUE or MIN_VALUE*/
			result =  error(LIMIT_OVERFLOW);
		}
	}
	else
	{	/*for passing invalid strings*/
		result = error(INVALID_STRING);
	}
	return result;
}
