/* 
Roman calculator: performs addition and subtraction of roman values
Author		: Vinay vittal Karagod
File dependents	: main.c, calculator.h, calculator.c,calculator-test.c,
		  roman_string_to_decimal_value.c, roman_string_to_decimal_value.h, decimal_value_to_roman_string.c,
		  decimal_value_to_roman_string.h, error.c, error.h, validation.h, validation.c, limit.h , limit.c
		  toUpperString.h, toUpperString.c 
Date		: 10/4/2016
 */
#include "decimal_value_to_roman_string.h"
#define zero 0
#define M_VALUE 1000
#define D_VALUE 500
#define CM 900
#define C_VALUE 100
#define CD 400
#define L_VALUE 50
#define XC 90 
#define X_VALUE 10
#define XL 40
#define V_VALUE 5
#define IX 9
#define IV 4
#define I 1

static char* post_roman_digit_characters(char character,int count,char* result_memory);
static char* pre_roman_digit_characters(char character1,char character2,char* result_memory);

/*Store digits for post-digit case*/
/*Helper function for decimal_value_to_roman_string*/
static char* post_roman_digit_characters(char character,int count,char* result_memory)
{
	/*this function stores the post digits of the roman character in temporary memory result_memory*/
	static int character_count;
	for(character_count = 0;character_count < count;character_count++){
		*result_memory = character;
		result_memory++;
	}
	return result_memory;
}
/*Store digits for pre-digit case*/
/*Helper function for decimal_value_to_roman_string*/
static char* pre_roman_digit_characters(char character1,char character2,char* result_memory)
{
	/*this function stores the previous digits of the roman character in temporary memory result_memory*/
	*result_memory = character1;
	result_memory++;
	*result_memory = character2;
	result_memory++;
	return result_memory;
}

char* decimal_number_to_roman_string(int decimal_number,char* result_memory)
{
	char *final_roman_string = result_memory;
	/*while loop to return the roman string of the passed decimal number. Inside the loop it calls either post_roman_digit_characters 
or pre_roman_digit_characters depending on the input */
	while(decimal_number != zero)
	{
		if(decimal_number >= M_VALUE){ // converstion for 1000
			result_memory = post_roman_digit_characters('M',decimal_number/M_VALUE,result_memory);
			decimal_number = decimal_number - (decimal_number/M_VALUE) * M_VALUE;		
		}/*End of 1000 VALUE*/
		else if(decimal_number >=D_VALUE){ // conversion for 500
			if(decimal_number <(CM)){
				result_memory = post_roman_digit_characters('D',decimal_number/D_VALUE,result_memory);
				decimal_number = decimal_number - (decimal_number/D_VALUE) * D_VALUE;
			}
			else{
				result_memory = pre_roman_digit_characters('C','M',result_memory);
				decimal_number = decimal_number - (CM);
			}
		}/*End of 500*/
		else if(decimal_number >=C_VALUE){ // conversion for 100
			if(decimal_number < (CD)){
				result_memory = post_roman_digit_characters('C',decimal_number/C_VALUE,result_memory);
				decimal_number = decimal_number - (decimal_number/C_VALUE) * C_VALUE;
			}
			else{
				result_memory = pre_roman_digit_characters('L','D',result_memory);
				decimal_number = decimal_number - (CD);
			}
		}/* end of if(decimal_number >=100) */
		else if(decimal_number >=L_VALUE){ // conversion for 50
			if(decimal_number < (XC)){
				result_memory = post_roman_digit_characters('L',decimal_number/L_VALUE,result_memory);
				decimal_number = decimal_number - (decimal_number/L_VALUE) * L_VALUE;
			}
			else{
				result_memory = pre_roman_digit_characters('X','C',result_memory);
				decimal_number = decimal_number - (XC);
			}
		} /*end of if(decimal_number >=50) */
		else if(decimal_number >=X_VALUE){ //conversion for 10
			if(decimal_number < (XL)){
				result_memory = post_roman_digit_characters('X',decimal_number/X_VALUE,result_memory);
				decimal_number = decimal_number - (decimal_number/X_VALUE) * X_VALUE;
			}
			else{
				result_memory = pre_roman_digit_characters('X','L',result_memory);
				decimal_number = decimal_number - (XL);
			}
		}/*end of if(decimal_number >=10) */
		else if(decimal_number >= V_VALUE){ //conversion for 5
			if(decimal_number < (IX)){
				result_memory = post_roman_digit_characters('V',decimal_number/V_VALUE,result_memory);
				decimal_number = decimal_number - (decimal_number/V_VALUE) * V_VALUE;
			}
			else{
				result_memory = pre_roman_digit_characters('I','X',result_memory);
				decimal_number = decimal_number - (IX);
			}
		}/*end of if(decimal_number >=5) */
		else if(decimal_number >=I){ // conversion for 1
			if(decimal_number < IV)
			{
				result_memory = post_roman_digit_characters('I',decimal_number/I,result_memory);
				decimal_number = decimal_number - (decimal_number/I) * I;
			}
			else{
				result_memory = pre_roman_digit_characters('I','V',result_memory);
				decimal_number = decimal_number - (IV);
			}
		}/*end of if(decimal_number >=1) */
	}/*End of while loop*/
	*result_memory = '\0';
	return final_roman_string;
}/*End of main function*/
