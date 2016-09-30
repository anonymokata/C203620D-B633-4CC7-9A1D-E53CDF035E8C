#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#define FAILURE -1
#define INVALID "-1"
#define MAX_VALUE 3999
#define MIN_VALUE -3999

char* calculate_roman_numbers(char first_roman_number[],char second_roman_number[], char Add_Subtract[],char* buffer)

	{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */
	 int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	 int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	char* final_answer; // to store the final result
	char* addition_of_roman_numbers(int first_sum_number,int second_sum_number,char* buffer);	
	char* subtraction_of_roman_numbers(int first_roman_integer,int second_roman_integer,char* sub_buffer);
	if (first_number == FAILURE || second_number == FAILURE)	
	{
	return INVALID;
	}
	
	if((strcmp(Add_Subtract,"ADD") == 0)|| (strcmp(Add_Subtract,"add") == 0)) // check for the addition operation
	{
		final_answer = addition_of_roman_numbers(first_number,second_number,buffer);
		return final_answer;
	}
	else if ((strcmp(Add_Subtract,"SUBTRACT") == 0)|| (strcmp(Add_Subtract,"subtract") == 0)) // check for the addition operation
	{
		final_answer = subtraction_of_roman_numbers(first_number,second_number,buffer);
		return final_answer;
	}
	else
	{
		return INVALID;		
	}


}

char* addition_of_roman_numbers(int first_sum_number,int second_sum_number,char* buffer)
{
	
	if((first_sum_number + second_sum_number) > MAX_VALUE)
		{
			return INVALID;
		}
		else
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			  return decimal_number_to_roman_string((first_sum_number + second_sum_number),buffer);
	 /* END of addition operation*/

}

char* subtraction_of_roman_numbers(int first_roman_integer,int second_roman_integer,char* sub_buffer)
{
	
	if((first_roman_integer - second_roman_integer) > MAX_VALUE || (first_roman_integer - second_roman_integer) < MIN_VALUE)
		{
			return INVALID;
		}
		else
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			return decimal_number_to_roman_string(abs(first_roman_integer - second_roman_integer),sub_buffer);
		/*Note: As there are no negative numbers in roman
		  considering the absolute value of the negative number*/
}



