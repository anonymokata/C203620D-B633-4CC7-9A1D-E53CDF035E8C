/*Helper function for decimal_value_to_roman_string*/

#include "decimal_value_to_roman_string.h"

//storing the post digits
char* post_roman_digit_characters(const char character,const int count,char* buffer)
{
	/*this function stores the post digits of the roman character in temproary memory buffer*/
	static int character_count;
	for(character_count = 0;character_count < count;character_count++){
		*buffer = character;
	}
	buffer++;
	return buffer;
}
