#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculator.h"
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#include "validation.h"
#include "limit.h"
#define NEGATIVE -1
#define FALSE 0
#define TRUE 1


static ROMAN_TYPE add(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static ROMAN_TYPE subtract(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
//static int limitation_check_subtraction(int first_number_1, int second_number_2);
//static int limitation_check_addition(int first_number1, int second_number2);

ROMAN_TYPE calculate_roman_numbers(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_OPERATION Add_Subtract, ROMAN_TYPE result)
{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	ROMAN_TYPE final_result;
	
	switch(Add_Subtract)
	{
	case ADD:
	final_result = add(first_roman_number,second_roman_number,result);
	break;
	case SUBTRACT:
	final_result = subtract(first_roman_number,second_roman_number,result);
	break;
	default:
	   return NULL;	
	}
return final_result;
}		
/*-----------------------------------------*/

ROMAN_TYPE add(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	ROMAN_TYPE roman_added_value;
if( isRomanNumberValid(first_roman_number) != 0 && isRomanNumberValid(second_roman_number) != 0 )
	{	
		
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		int second_number = roman_string_to_decimal_value(second_roman_number);
		//int total_value = limitation_check_addition(first_number,second_number);
		//printf("total sum = %d \n",(first_number + second_number));
		//printf("linit add = %s\n",is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number));
		//printf("value of is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number) = %d \n",is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number));
		//if(is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number) == TRUE)
		if(is_Limit_Of_Add_Is_Not_Exceeded(first_number + second_number) == TRUE)
		{	
						
			roman_added_value = decimal_number_to_roman_string((first_number + second_number),result);
		}
	}	
	
else
	{
		roman_added_value =  "INVALID";
	
	}
 return roman_added_value;	
}


ROMAN_TYPE subtract(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result)
{
	ROMAN_TYPE roman_subtracted_value;
if(isRomanNumberValid(first_roman_number) != 0  && isRomanNumberValid(second_roman_number) != 0)
	{
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		int second_number = roman_string_to_decimal_value(second_roman_number);
		int total_value = limitation_check_subtraction(first_number,second_number);
		//if(is_Limit_Of_Subtract_Is_Not_Exceeded(abs(first_number - second_number)) == TRUE)
		roman_subtracted_value= decimal_number_to_roman_string(total_value,result);	
		
	}
else
	{		
		roman_subtracted_value = "INVALID";
	}
return roman_subtracted_value;
}

/*------------------------------------*/
/*int limitation_check_subtraction(int first_number_1, int second_number_2)
{
	if((first_number_1 - second_number_2) > MAX_VALUE || (first_number_1 - second_number_2) < MIN_VALUE)
		{
			return (int)NULL;
		}
		else
			
return (abs(first_number_1 - second_number_2));
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
*/
