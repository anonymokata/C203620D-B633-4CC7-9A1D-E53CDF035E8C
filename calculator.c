#include <stdio.h>
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#include "calculator_addition.h"
#include "calculator_subtraction.h"
# define CHAR_LENGTH 50
# define ADD_SUBTRACT 10

char* calculate_roman_numbers(char first_roman_number[CHAR_LENGTH],char second_roman_number[CHAR_LENGTH], char Add_Subtract[ADD_SUBTRACT],char* buffer)

	{
	/*calculate function reveives the input from test file first_roman number,
 		second roman_number, addition/subtraction operation and temproary memory */

	int first_number = roman_string_to_decimal_value(first_roman_number); // calling roman_decimal function to convert first roman number to decimal
	int second_number = roman_string_to_decimal_value(second_roman_number); // calling roman_decimal function to convert second roman number to decimal
	char * final_answer; // to store the final result
	
	if((strcmp(Add_Subtract,"ADD") == 0)|| (strcmp(Add_Subtract,"add") == 0)) // check for the addition operation
	{
		final_answer = addition_of_roman_numbers(first_number,second_number);		
	}

return final_answer;
}

