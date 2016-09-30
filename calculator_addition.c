#include <stdlib.h>
#include "calculator.h"
#include "decimal_value_to_roman_string.h"
#define MAX_VALUE 3999
#define MIN_VALUE -3999
#define FAILURE "-1"


char* addition_of_roman_numbers(int first_number,int second_number,char* buffer)
{
	char* sum_of_roman_value;
	if((first_number + second_number) > MAX_VALUE)
		{
			return FAILURE;
		}
		else{
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			  sum_of_roman_value = decimal_number_to_roman_string((first_number + second_number),buffer);
	} /* END of addition operation*/
return sum_of_roman_value;
}

char* subtraction_of_roman_numbers(int first_roman_integer,int second_roman_integer,char* sub_buffer)
{
	char* subtraction_of_roman_value;
	if((first_roman_integer - second_roman_integer) > MAX_VALUE || (first_roman_integer - second_roman_integer) < MIN_VALUE)
		{
			return FAILURE;
		}
		else{
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			subtraction_of_roman_value = decimal_number_to_roman_string(abs(first_roman_integer - second_roman_integer),sub_buffer);
		/*Note: As there are no negative numbers in roman
		  considering the absolute value of the negative number*/
}
return subtraction_of_roman_value;

}
