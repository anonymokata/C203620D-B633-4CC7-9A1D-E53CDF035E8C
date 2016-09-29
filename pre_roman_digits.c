/*helper function for decinal_value_to_roman_string*/

#include "decimal_value_to_roman_string.h"

char* pre_roman_digit_characters(char character1,char character2,char* buffer)
{
/*this function stores the previous digits of the roman character in temproary memory buffer*/
	*buffer = character1;
	*(buffer++);
	*buffer = character2;
	*(buffer++);
	return buffer;
}
