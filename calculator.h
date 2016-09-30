#ifndef calculator_H
#define calculator_H


typedef char ROMAN_TYPE;
typedef enum{ADD, SUBTRACT} ROMAN_OPERATION;
ROMAN_TYPE* calculate_roman_numbers(ROMAN_TYPE first_roman_number, ROMAN_TYPE second_roman_number, ROMAN_OPERATION Add_Subtract, ROMAN_TYPE *result);

//char* calculate_roman_numbers(char first_roman_number[],char second_roman_number[],char Add_Subtract[],char* buffer);
//char* addition_of_roman_numbers(int first_sum_number,int second_sum_number,char* buffer);
//char* subtraction_of_roman_numbers(int first_roman_integer,int second_roman_integer,char* sub_buffer);

#endif
