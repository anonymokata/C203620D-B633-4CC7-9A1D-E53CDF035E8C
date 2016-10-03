#include <ctype.h>

char* stringUpper(char roman_value[])
{
  int roman_pointer = 0;
  while (roman_value[roman_pointer]) {
	roman_value[roman_pointer] = (toupper(roman_value[roman_pointer]));
	roman_pointer++;
  }
  return roman_value;
}
