#ifndef calculator_H
#define calculator_H


typedef char* ROMAN_TYPE;
typedef enum{ ADD, SUBTRACT} ROMAN_OPERATION;
ROMAN_TYPE calculate_roman_numbers(ROMAN_TYPE first_roman_number,ROMAN_TYPE second_roman_number,ROMAN_OPERATION Add_Subtract, ROMAN_TYPE result);

#endif
