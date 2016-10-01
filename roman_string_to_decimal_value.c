# include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculator.h"
#include "decimal_value_to_roman_string.h"
#include "roman_string_to_decimal_value.h"
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
#define Zero 0
#define NEGATIVE -1


//static int isRomanNumberValid(Roman roman_value);
//static int roman_to_decimal_digit_value(char roman_character);
//static int limitation_check_subtraction(int first_number_1, int second_number_2);
//static int limitation_check_addition(int first_number1, int second_number2);
//static Roman add(Roman first_roman_number,Roman second_roman_number,Roman result);
//static Roman subtract(Roman first_roman_number,Roman second_roman_number,Roman result);

/*function to return decimal value of the roman digit*/
int roman_to_decimal_digit_value(char roman_character)
{
	static int decimal_value = 0;
	/*switch case to return the decimal value based on the character passed to it*/
	switch(roman_character){
	case 'I': decimal_value = I;
	break;
	case 'V': decimal_value = V;
	break;
	case 'X': decimal_value = X;
	break;
	case 'L': decimal_value = L;
	break;
	case 'C': decimal_value = C;
	break;
	case 'D': decimal_value = D;
	break;
	case 'M': decimal_value = M;
	break;
	case '\0': decimal_value = Zero;
	break;
	default: decimal_value = NEGATIVE;
	}
	return decimal_value;
}

/*function to return the decimal value based on the input roman string*/

int roman_string_to_decimal_value(char roman_string[])
{
	int roman_to_decimal_digit_value(char roman_character);
	int roman_string_index = 0;
	int decimal_number = 0; // value to store the decimal value
	
	while(roman_string[roman_string_index])
	{
		/*if condition check the order of the string. If first digit is greater than the second digit it add the value else 
		it subtracts the value  */
	
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

/*-----------------------------------*/
int isRomanNumberValid(char roman_value[])
{
	int roman_string_pointer = 0;
if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < 0)
	{
            return NEGATIVE;
	}
if((strlen(roman_value) -roman_string_pointer) > 2)
	{
		if(roman_to_decimal_digit_value(roman_value[roman_string_pointer]) < roman_to_decimal_digit_value(roman_value[roman_string_pointer + 2]))
		{
	                return NEGATIVE;
	        }
         }
}




