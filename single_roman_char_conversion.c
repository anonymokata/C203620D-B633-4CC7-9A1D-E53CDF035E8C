#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
#define Zero 0
#define negative -1

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
	default: decimal_value = negative;
	}
	return decimal_value;
}
