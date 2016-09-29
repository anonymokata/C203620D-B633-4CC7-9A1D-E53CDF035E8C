CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o post_roman_digits.o pre_roman_digits.o calculator.o calculator_addition.o
	gcc -o calc main.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o post_roman_digits.o pre_roman_digits.o calculator.o calculator_addition.o

main.o: main.c single_roman_char_conversion.h roman_string_to_decimal_value.h decimal_value_to_roman_string.h post_roman_digits.h pre_roman_digits.h calculator.h calculator_addition.h
	gcc $(CFLAGS) -c main.c

calculator.o: single_roman_char_conversion.c single_roman_char_conversion.h roman_string_to_decimal_value.c roman_string_to_decimal_value.h decimal_value_to_roman_string.c decimal_value_to_roman_string.h post_roman_digits.c post_roman_digits.h pre_roman_digits.c pre_roman_digits.h calculator.c calculator.h calculator_addition.c calculator_addition.h
	gcc $(CFLAGS) -c single_roman_char_conversion.c roman_string_to_decimal_value.c decimal_value_to_roman_string.c post_roman_digits.c pre_roman_digits.c calculator.c calculator_addition.h

test: calc-test
	./calc-test

calc-test: calculator-test.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o post_roman_digits.o pre_roman_digits.o calculator.o calculator_addition.o
	gcc -o calc-test single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o post_roman_digits.o pre_roman_digits.o calculator.o calculator_addition.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c single_roman_char_conversion.h roman_string_to_decimal_value.h decimal_value_to_roman_string.h post_roman_digits.h pre_roman_digits.h calculator.h calculator_addition.h
	gcc $(CFLAGS) -c calculator-test.c
