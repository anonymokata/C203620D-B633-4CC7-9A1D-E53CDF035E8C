#define zero 0
#define M_VALUE 1000
#define D_VALUE 500
#define NINE_HUNDRED 900
#define C_VALUE 100
#define FOUR_HUNDRED 400
#define L_VALUE 50
#define NINTY 90 
#define X_VALUE 10
#define FORTY 40
#define V_VALUE 5
#define NINE 9
#define FOUR 4
#define ONE 1

static char* post_roman_digit_characters(char character,int count,char* buffer);
static char* pre_roman_digit_characters(char character1,char character2,char* buffer);

//storing the post digits
/*Helper function for decimal_value_to_roman_string*/
char* post_roman_digit_characters(char character,int count,char* buffer)
{
	/*this function stores the post digits of the roman character in temproary memory buffer*/
	static int character_count;
	for(character_count = 0;character_count < count;character_count++){
		*buffer = character;
		buffer++;
	}
	return buffer;
}

char* pre_roman_digit_characters(char character1,char character2,char* buffer)
{
/*this function stores the previous digits of the roman character in temproary memory buffer*/
	*buffer = character1;
	buffer++;
	*buffer = character2;
	buffer++;
	return buffer;
}


char* decimal_number_to_roman_string(int decimal_number,char* buffer)
{

	char *final_roman_string = buffer;
	/*while loop to return the roman string of the passed decimal number. Inside the loop it calls either post_roman_digit_characters 
or pre_roman_digit_characters depending on the input */
	while(decimal_number != zero)
	{
	
		if(decimal_number >= M_VALUE){ // converstion for 1000
			buffer = post_roman_digit_characters('M',decimal_number/M_VALUE,buffer);
			decimal_number = decimal_number - (decimal_number/M_VALUE) * M_VALUE;
		}/*End of 1000 VALUE*/
	else if(decimal_number >=D_VALUE){ // conversion for 500
			if(decimal_number <(NINE_HUNDRED)){
				buffer = post_roman_digit_characters('D',decimal_number/D_VALUE,buffer);
				decimal_number = decimal_number - (decimal_number/D_VALUE) * D_VALUE;
			}
	else{
				buffer = pre_roman_digit_characters('C','M',buffer);
				decimal_number = decimal_number - (NINE_HUNDRED);
			}
	}/*End of 500*/
	else if(decimal_number >=C_VALUE){ // conversion for 100
			if(decimal_number < (FOUR_HUNDRED)){
				buffer = post_roman_digit_characters('C',decimal_number/C_VALUE,buffer);
				decimal_number = decimal_number - (decimal_number/C_VALUE) * C_VALUE;
			}
			else{
				buffer = pre_roman_digit_characters('L','D',buffer);
				decimal_number = decimal_number - (FOUR_HUNDRED);
			}
		}/* end of if(decimal_number >=100) */
	else if(decimal_number >=L_VALUE){ // conversion for 50
			if(decimal_number < (NINTY)){
				buffer = post_roman_digit_characters('L',decimal_number/L_VALUE,buffer);
				decimal_number = decimal_number - (decimal_number/L_VALUE) * L_VALUE;
			}
			else{
				buffer = pre_roman_digit_characters('X','C',buffer);
				decimal_number = decimal_number - (NINTY);
			}
		} /*end of if(decimal_number >=50) */
	
	else if(decimal_number >=X_VALUE){ //conversion for 10
			if(decimal_number < (FORTY)){
				buffer = post_roman_digit_characters('X',decimal_number/X_VALUE,buffer);
				decimal_number = decimal_number - (decimal_number/X_VALUE) * X_VALUE;
			}
			else{
				buffer = pre_roman_digit_characters('X','L',buffer);
				decimal_number = decimal_number - (FORTY);
			}
		}/*end of if(decimal_number >=10) */
	else if(decimal_number >= V_VALUE){ //conversion for 5
			if(decimal_number < (NINE)){
				buffer = post_roman_digit_characters('V',decimal_number/V_VALUE,buffer);
				decimal_number = decimal_number - (decimal_number/V_VALUE) * V_VALUE;
			}
			else{
				buffer = pre_roman_digit_characters('I','X',buffer);
				decimal_number = decimal_number - (NINE);
			}
		}/*end of if(decimal_number >=5) */
	else if(decimal_number >=ONE){ // conversion for 1
			if(decimal_number < FOUR)
			{
				buffer = post_roman_digit_characters('I',decimal_number/ONE,buffer);
				decimal_number = decimal_number - (decimal_number/ONE) * ONE;
			}
			else{
				buffer = pre_roman_digit_characters('I','V',buffer);
				decimal_number = decimal_number - (FOUR);
			}
		}/*end of if(decimal_number >=1) */

	}/*End of while loop*/

	*buffer = '\0';
	return final_roman_string;
}/*End of main function*/
