#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#include "calculator.h"
#include "validation.h"
#define MAX_VALUE 3999
#define MIN_VALUE -3999
#define NEGATIVE -1


//static int limitation_check_addition(int first_number, int second_number);
//static int limitation_check_subtraction(int first_number, int second_number);	

static ROMAN_TYPE add(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static ROMAN_TYPE subtract(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static int limitation_check_subtraction(int first_number_1, int second_number_2);
static int limitation_check_addition(int first_number1, int second_number2);

ROMAN_TYPE calculate_roman_numbers(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_OPERATION Add_Subtract, ROMAN_TYPE result)
{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	//int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	//int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	
	ROMAN_TYPE final_answer; // to store the final result
	ROMAN_TYPE temp_result;
	switch(Add_Subtract)
	{
	case ADD:
	temp_result = add(first_roman_number,second_roman_number,result);
	break;
	case SUBTRACT:
	final_answer = subtract(first_roman_number,second_roman_number,result);
	break;
	default:
	   return NULL;	
	}
return final_answer;
}		
/*-----------------------------------------*/

ROMAN_TYPE add(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	ROMAN_TYPE final_added_answer = NULL;
if( isRomanNumberValid(first_roman_number) == NEGATIVE && isRomanNumberValid(second_roman_number)== NEGATIVE )
	{	
		return NULL;
	}
else
	{
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		int second_number = roman_string_to_decimal_value(second_roman_number);
		int total_value = limitation_check_addition(first_number,second_number);
		final_added_answer = decimal_number_to_roman_string(total_value,result);
	}
return final_added_answer; 	
}
/*----------------------------------------*/
int limitation_check_addition(int first_number1, int second_number2)
{
if((first_number1 + second_number2) > MAX_VALUE)
	{
		return (int)NULL;
	}
	else
		  return (first_number1 + second_number2);
}


ROMAN_TYPE subtract(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	ROMAN_TYPE final_subtracted_answer = NULL;
if(isRomanNumberValid(first_roman_number) == NEGATIVE && isRomanNumberValid(second_roman_number) == NEGATIVE)
{	
	return NULL;
}
else
	{
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		int second_number = roman_string_to_decimal_value(second_roman_number);
		int total_value = limitation_check_subtraction(first_number,second_number);
		final_subtracted_answer = decimal_number_to_roman_string(total_value,result);
	}
return final_subtracted_answer; 
}

/*------------------------------------*/
int limitation_check_subtraction(int first_number_1, int second_number_2)
{
	if((first_number_1 - second_number_2) > MAX_VALUE || (first_number_1 - second_number_2) < MIN_VALUE)
		{
			return (int)NULL;
		}
		else
			
return (abs(first_number_1 - second_number_2));
}














/*int total_value;	
	if (first_number == FAILURE || second_number == FAILURE)	
	{
	return INVALID;
	}
	
	
	if(Add_Subtract == ADD) // check for the addition operation
	{
		total_value = limitation_check_addition(first_number,second_number); 		
		final_answer = decimal_number_to_roman_string(total_value,result);
		return final_answer;
		
	}
	else if (Add_Subtract == SUBTRACT) // check for the addition operation
	{
		total_value = limitation_check_subtraction(first_number,second_number); 		
		final_answer = decimal_number_to_roman_string(total_value,result);
		return final_answer;
		
	}
	else
	{
		return INVALID;		
	}


}

int limitation_check_addition(int first_number1, int second_number2)
{

	if((first_number1 + second_number2) > MAX_VALUE)
		{
			return (int)NULL;
		}
		else
			
			  return (first_number1 + second_number2);
	 


}

int limitation_check_subtraction(int first_numbera, int second_numberb)
{

	if((first_numbera - second_numberb) > MAX_VALUE || (first_numbera - second_numberb) < MIN_VALUE)
		{
			return (int)NULL;
		}
		else
			
			return (abs(first_numbera - second_numberb));
		
}*/

