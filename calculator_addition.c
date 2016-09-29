#include "calculator.h"
#include "decimal_value_to_roman_string.h"
#define MAX_VALUE 3999
#define FAILURE -1

char* addition_of_roman_numbers(int first_number,int second_number)
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
