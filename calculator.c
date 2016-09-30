#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#define FAILURE -1
#define INVALID "-1"
#define MAX_VALUE 3999
#define MIN_VALUE -3999

ROMAN_TYPE* calculate_roman_numbers(ROMAN_TYPE first_roman_number, ROMAN_TYPE first_roman_number, ROMAN_OPERATION Add_subtract, ROMAN_TYPE *result)

	{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	 int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	 int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	char* final_answer; // to store the final result
	//char* addition_of_roman_numbers(int first_sum_number,int second_sum_number,char* buffer);	
	//char* subtraction_of_roman_numbers(int first_roman_integer,int second_roman_integer,char* sub_buffer);
	
	if (first_number == FAILURE || second_number == FAILURE)	
	{
	return INVALID;
	}
	int total_value;
	int limitation_check_addition(int first_number, int second_number);
	int limitation_check_subtraction(int first_number, int second_number);	
	if(Add_Subtract == ADD) // check for the addition operation
	{
		total_value = limitation_check_addition(int first_number, int second_number); 		
		final_answer = decimal_number_to_roman_string(total_value,result)
		return final_answer;
	}
	else if (Add_Subtract == SUBTRACT) // check for the addition operation
	{
		total_value = limitation_check_subtraction(int first_number, int second_number); 		
		final_answer = decimal_number_to_roman_string(total_value,result)
		return final_answer;
	}
	else
	{
		return INVALID;		
	}


}

int limitation_check_addition(int first_number, int second_number){

	if((first_number + second_number) > MAX_VALUE)
		{
			return INVALID;
		}
		else
			
			  return (first_number + second_number);
	 /* END of addition operation*/


}

int limitation_check_addition(int first_number, int second_number){

	if((first_number - second_number) > MAX_VALUE || (first_number - second_number) < MIN_VALUE)
		{
			return INVALID;
		}
		else
			
			return (abs(first_number - second_number);
		/*Note: As there are no negative numbers in roman
		  onsidering the absolute value of the negative number*/
}




