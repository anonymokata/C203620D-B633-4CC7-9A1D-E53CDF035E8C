/*function to return decimal value of the roman digit*/
int roman_to_decimal_digit_value(char roman_character)
{
	int decimal_value=0;
	/*switch case to return the decimal value based on the character passed to it*/
	switch(roman_character){
	case 'I': decimal_value = 1;
	break;
	case 'V': decimal_value = 5;
	break;
	case 'X': decimal_value = 10;
	break;
	case 'L': decimal_value = 50;
	break;
	case 'C': decimal_value = 100;
	break;
	case 'D': decimal_value = 500;
	break;
	case 'M': decimal_value = 1000;
	break;
	case '\0': decimal_value = 0;
	break;
	default: decimal_value = -1;
	}
	return decimal_value;
}
