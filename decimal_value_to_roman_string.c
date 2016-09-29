#include "post_roman_digits.h"
#include "pre_roman_digits.h"
#define zero 0
#define M_value 1000
#define D_value 500
#define Nine_hundred 900
#define C_value 100
#define Four_hundred 400
#define L_value 50
#define Ninty 90 
#define X_value 10
#define Forty 40
#define V_value 5
#define Nine 9

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
	else if(decimal_number >=C_value){ // conversion for 100
			if(decimal_number < (Four_hundred)){
				buffer = post_roman_digit_characters('C',decimal_number/C_value,buffer);
				decimal_number = decimal_number - (decimal_number/C_value) * C_value;
			}
			else{
				buffer = pre_roman_digit_characters('L','D',buffer);
				decimal_number = decimal_number - (Four_hundred);
			}
		}/* end of if(decimal_number >=100) */
	else if(decimal_number >=L_value){ // conversion for 50
			if(decimal_number < (Ninty)){
				buffer = post_roman_digit_characters('L',decimal_number/L_value,buffer);
				decimal_number = decimal_number - (decimal_number/L_value) * L_value;
			}
			else{
				buffer = pre_roman_digit_characters('X','C',buffer);
				decimal_number = decimal_number - (Ninty);
			}
		} /*end of if(decimal_number >=50) */
	
	else if(decimal_number >=X_value){ //conversion for 10
			if(decimal_number < (Forty)){
				buffer = post_roman_digit_characters('X',decimal_number/X_value,buffer);
				decimal_number = decimal_number - (decimal_number/X_value) * X_value;
			}
			else{
				buffer = pre_roman_digit_characters('X','L',buffer);
				decimal_number = decimal_number - (Forty);
			}
		}/*end of if(decimal_number >=10) */
	else if(decimal_number >= V_value){ //conversion for 5
			if(decimal_number < (Nine)){
				buffer = post_roman_digit_characters('V',decimal_number/V_value,buffer);
				decimal_number = decimal_number - (decimal_number/V_value) * V_value;
			}
			else{
				buffer = pre_roman_digit_characters('I','X',buffer);
				decimal_number = decimal_number - (Nine);
			}
		}/*end of if(decimal_number >=5) */

	}/*End of while loop*/

	*buffer = '\0';
	return final_roman_string;
}/*End of main function*/
