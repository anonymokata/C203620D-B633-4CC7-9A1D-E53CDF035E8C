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
#define FALSE 0
#define TRUE 1

static ROMAN_TYPE add(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static ROMAN_TYPE subtract(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_TYPE result);
static int limitation_check_subtraction(int first_number_1, int second_number_2);
static int limitation_check_addition(int first_number1, int second_number2);

ROMAN_TYPE calculate_roman_numbers(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_OPERATION Add_Subtract, ROMAN_TYPE result)
{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	
	ROMAN_TYPE final_answer; // to store the final result
	printf("inside calculate_roman_numbers first_roman= %s \n",first_roman_number); 
	printf("inside calculate_roman_numbers second_roman= %s \n",second_roman_number); 
	printf("inside calculate_roman_numbers second_roman= %d \n",Add_Subtract); 
	switch(Add_Subtract)
	{
	case ADD:
	final_answer = add(first_roman_number,second_roman_number,result);
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
	ROMAN_TYPE final_added_answer;
	printf("inside add first_roman= %s \n",first_roman_number); 
	printf("inside add second_roman= %s \n",second_roman_number); 
	printf("roman valid first=  %d \n",isRomanNumberValid(first_roman_number));
	printf("roman valid second=  %d \n",isRomanNumberValid(second_roman_number));
if( isRomanNumberValid(first_roman_number) != 0 && isRomanNumberValid(second_roman_number) != 0 )
	{	
	//printf("return of roman_valid first_roman_numner %d \n",isRomanNumberValid(first_roman_number));
	//printf("return of roman_valid second_roman_numner %d \n",isRomanNumberValid(second_roman_number));		
		int first_number = roman_string_to_decimal_value(first_roman_number); 
			printf("first_roman_number %d \n",first_number);
		int second_number = roman_string_to_decimal_value(second_roman_number);
			printf("second_roman_number %d \n",second_number);
		int total_value = limitation_check_addition(first_number,second_number);
			printf("total_value %d \n",total_value);
		final_added_answer = decimal_number_to_roman_string(total_value,result);
			printf("total_value %s \n",final_added_answer);
		return final_added_answer;
	}	
	
else
	{
		return final_added_answer = "INVALI";
	
	}
 	
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
	ROMAN_TYPE final_subtracted_answer;
if(isRomanNumberValid(first_roman_number) != 0  && isRomanNumberValid(second_roman_number) != 0)
	{
		int first_number = roman_string_to_decimal_value(first_roman_number); 
		int second_number = roman_string_to_decimal_value(second_roman_number);
		int total_value = limitation_check_subtraction(first_number,second_number);
		final_subtracted_answer = decimal_number_to_roman_string(total_value,result);	
	}
else
	{		
		final_subtracted_answer = NULL;
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

