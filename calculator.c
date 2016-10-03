#include <stdio.h>
#include <string.h> // to handle string objects
#include <stdlib.h> // to handle pre-defined function: abs()
#include <ctype.h>
#include "calculator.h"
#include "roman_string_to_decimal_value.h" // this files is used to call functions to convert roman_string to decimal_value
#include "decimal_value_to_roman_string.h" // this files is used to call functions to convert decimal value to roman string
#include "validation.h" // to check the validation of the roman string
#include "limit.h" // to check the limitation of maximum roman cahracter
#include "toUpperString.h"
#define FALSE 0 // to check the condition if condition failes it returns false
#define TRUE 1  //to check the constion is condition passes it will return true

/*add function to perform addition of roman numbers:
const ROMAN_TYPE first_roman_number : to store the first roman string 
const ROMAN_TYPE second_roman_number: to store the second roman string
ROMAN_TYPE result: to store the result after the roman operation*/
static ROMAN_TYPE add(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result);

/*subtract function to perform addition of roman numbers:
const ROMAN_TYPE first_roman_number : to store the first roman string 
const ROMAN_TYPE second_roman_number: to store the second roman string
ROMAN_TYPE result: to store the result after the roman operation*/
static ROMAN_TYPE subtract(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result);

/* calculate_roman_numbers function is used to receieve first string, second string operation to perform add/subtract and buffer to store the result :
const ROMAN_TYPE first_roman_number : to store the first roman string 
const ROMAN_TYPE second_roman_number: to store the second roman string
ROMAN_OPERATION Add_Subtract: add/subtract operation will be passed in the variable
ROMAN_TYPE result: to store the result after the roman operation*/
ROMAN_TYPE calculate_roman_numbers(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_OPERATION Add_Subtract, ROMAN_TYPE result)
{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	/*switch case is used to choose addtion or subtraction operation based on the input provided by the user*/
			ROMAN_TYPE f_roman_number = stringUpper(first_roman_number);
			ROMAN_TYPE s_roman_number = stringUpper(second_roman_number);	
	switch(Add_Subtract)
	{
	case ADD:
		result = add(first_roman_number,second_roman_number,result); // this function passes parameters to perform the addition operation
		break;
	case SUBTRACT:
		result = subtract(first_roman_number,second_roman_number,result); // this function passes parameters to perform the subtraction operation
		break;
	default:
		return "INVALID"; // default case returns the invalid 	
	}
	return result;
}		
/*-----------------------------------------*/
/* function to perform roman addition*/
ROMAN_TYPE add(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	/* isRomanNumberValid functions is used to check the valid roman character if the roman number is valid it returns true else returns false
	   if both roman numbers are valid it will performs further operation else it will return INVALID*/
	if( isRomanNumberValid(first_roman_number) != 0 && isRomanNumberValid(second_roman_number) != 0 )
	{	
		/* int variable first_number is used to store decimal value of the first roman number
			roman_string_to_decimal_value function is called here to convert roman string to decimal value*/
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		/* int variable second_number is used to store decimal value of the second roman number
			roman_string_to_decimal_value function is called here to convert roman string to decimal value*/
		int second_number = roman_string_to_decimal_value(second_roman_number);
		/*is_Limit_Of_Add_Is_Not_Exceeded is used to check the maximum limit of the decimal value afer addtion of two numbers
			if condition retrurns true it will execute decimal_number_to_roman_string function to convert back to roma string of the tolta number
			else results returns invalid string  */
		if(is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number) == TRUE)
		{	

			result = decimal_number_to_roman_string((first_number + second_number),result);
		}
		else // else condition is used for "if(is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number) == TRUE)" 
		{
			result =  "INVALID";
		}
	}	

	else  // else condition is used for if( isRomanNumberValid(first_roman_number) != 0 && isRomanNumberValid(second_roman_number) != 0 ) 
	{
		result =  "INVALID";

	}
	return result; // to return the final result after addtion operation	
}


ROMAN_TYPE subtract(const ROMAN_TYPE first_roman_number,const ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{

	/* isRomanNumberValid functions is used to check the valid roman character if the roman number is valid it returns true else returns false
	   if both roman numbers are valid it will performs further operation else it will return INVALID*/
	if(isRomanNumberValid(first_roman_number) != 0  && isRomanNumberValid(second_roman_number) != 0)
	{
		/* int variable first_number is used to store decimal value of the first roman number
			roman_string_to_decimal_value function is called here to convert roman string to decimal value*/		
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		/* int variable second_number is used to store decimal value of the second roman number
			roman_string_to_decimal_value function is called here to convert roman string to decimal value*/		
		int second_number = roman_string_to_decimal_value(second_roman_number);
		/*is_Limit_Of_Subtract_Is_Not_Exceeded function is used to check the maximum limit of the decimal value here abs() function is 
			used as there are no negative numers or zero value in roman characters */		

		if(is_Limit_Of_Subtract_Is_Not_Exceeded(abs(first_number - second_number)) == TRUE)
		{
			/* decimal_number_to_roman_string function is used to convert decimal value to roman string and returns the result
			 */			
			result = decimal_number_to_roman_string(abs(first_number - second_number),result);
		}
		else 
		{
			result =  "INVALID"; // else condition is used for if(is_Limit_Of_Subtract_Is_Not_Exceeded(abs(first_number - second_number)) == TRUE)
		}		
	}
	else
	{		
		result = "INVALID";// esle conditions used for if(isRomanNumberValid(first_roman_number) != 0  && isRomanNumberValid(second_roman_number) != 0) 
	}
	return result;
}

