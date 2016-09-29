#include "post_roman_digits.h"
#include "pre_roman_digits.h"
#define zero 0
#define M_value 1000
#define D_value 500
#define Nine_hundred 900

char* decimal_number_to_roman_string(int decimal_number,char* buffer)
{

	char *final_roman_string = buffer;
	/*while loop to return the roman string of the passed decimal number. Inside the loop it calls either post_roman_digit_characters 
or pre_roman_digit_characters depending on the input */
	while(decimal_number != zero)
	{
	
		if(decimal_number >= M_value){ // converstion for 1000
			buffer = post_roman_digit_characters('M',decimal_number/M_value,buffer);
			decimal_number = decimal_number - (decimal_number/M_value) * M_value;
		}/*End of 1000 value*/
	else if(decimal_number >=D_value){ // conversion for 500
			if(decimal_number <(Nine_hundred)){
				buffer = post_roman_digit_characters('D',decimal_number/D_value,buffer);
				decimal_number = decimal_number - (decimal_number/D_value) * D_value;
			}
	else{
				buffer = pre_roman_digit_characters('C','M',buffer);
				decimal_number = decimal_number - (Nine_hundred);
			}
	}/*End of 500*/




	}/*End of while loop*/

	*buffer = '\0';
	return final_roman_string;
}/*End of main function*/
