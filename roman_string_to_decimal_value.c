/*


*/

# include "single_roman_char_conversion.h"
# include <stdio.h>
# include <string.h>
#define FAILURE -1

/*function to return the decimal value based on the input roman string*/

int roman_string_to_decimal_value(char roman_string[50])
{
	
	int roman_string_index = 0;
	int decimal_number = 0; // value to store the decimal value
	
	while(roman_string[roman_string_index])
	{
		/*if condition check the order of the string. If first digit is greater than the second digit it add the value else 
		it subtracts the value  */
	if(roman_to_decimal_digit_value(roman_string[roman_string_index]) < 0){
             return FAILURE;
         }
	if((strlen(roman_string) -roman_string_index) > 2){
             if(roman_to_decimal_digit_value(roman_string[roman_string_index]) < roman_to_decimal_digit_value(roman_string[roman_string_index + 2])){
                 
                 return FAILURE;
             }
         }
	if(roman_to_decimal_digit_value(roman_string[roman_string_index]) >= roman_to_decimal_digit_value(roman_string[roman_string_index+1])) 
			decimal_number = decimal_number + roman_to_decimal_digit_value(roman_string[roman_string_index]);
		else{
			decimal_number = decimal_number+ (roman_to_decimal_digit_value(roman_string[roman_string_index+1]) - roman_to_decimal_digit_value(roman_string[roman_string_index]));
			roman_string_index++;
			
		}
		roman_string_index++;
	}
	return decimal_number;
}
