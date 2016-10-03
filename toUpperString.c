#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*char* stringUpper(char r_value[])
{
	char ch; 
	int string_counter;
	for(string_counter = 0;r_value[string_counter] != '\0';string_counter++)
	{
		printf("each characer %c \n",r_value[string_counter]);
	switch(ch = r_value[string_counter])
	{
	case 'i':
		r_value[string_counter] = 'I';
		break;
	case 'v':
		r_value[string_counter] = 'V';
		break;
	case 'x':
		r_value[string_counter] = 'X';
		break;
	case 'c':
		r_value[string_counter] = 'C';
		break;
	case 'd':
		r_value[string_counter] = 'D';
		break;
	case 'm':
		r_value[string_counter] = 'M';
		break;
	}

}
return r_value;
}*/		

char* stringUpper(char roman_value[])
{
  int roman_pointer = 0;
  
 
  while (roman_value[roman_pointer]) {
	if (isupper(roman_value[roman_pointer]))
	{
		roman_pointer++;
	}
	else
	{
	roman_value[roman_pointer] = (toupper(roman_value[roman_pointer]));
	}
	roman_pointer++;
  }
	printf("after conversion of roman %s \n",roman_value);
  return roman_value;
}
