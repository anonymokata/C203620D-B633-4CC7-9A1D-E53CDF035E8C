#include <string.h>
#include <ctype.h>

char* stringUpper(char *roman_value)
{
  unsigned char *string_pointer = (unsigned char *)roman_value;

  while (*string_pointer) {
     *string_pointer = toupper(*string_pointer);
      string_pointer++;
  }

  return roman_value;
}
