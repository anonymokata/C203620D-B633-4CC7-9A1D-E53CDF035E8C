#ifndef decimal_value_to_roman_string_H
#define decimal_value_to_roman_string_H

char* decimal_number_to_roman_string(int decimal_number,char* buffer);
char* post_roman_digit_characters(char character,int count,char* buffer);
char* pre_roman_digit_characters(char character1,char character2,char* buffer);

#endif
