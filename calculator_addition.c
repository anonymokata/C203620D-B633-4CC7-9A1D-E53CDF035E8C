#include "calculator.h"
#include "decimal_value_to_roman_string.h"
#define MAX_VALUE 3999
#define FAILURE "-1"


char* addition_of_roman_numbers(int first_number,int second_number,char* buffer)
{
	
	if((first_number + second_number) > MAX_VALUE)
		{
			return FAILURE;
		}
		else{
			//printf("first = %d \n",first_number);
			//printf("second = %d \n",second_number);
			//printf("buffer = %s",buffer);
			printf("final value from addition function= %s \n",decimal_number_to_roman_string((first_number + second_number),buffer));
			/*calculate function calls decimal_number_to_roman_string function to convert decimal to roman value*/
			 return decimal_number_to_roman_string((first_number + second_number),buffer);
	} /* END of addition operation*/


}
