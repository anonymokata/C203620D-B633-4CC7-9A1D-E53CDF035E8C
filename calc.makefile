CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o
	gcc -o calc main.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o

main.o: main.c single_roman_char_conversion.h roman_string_to_decimal_value.h decimal_value_to_roman_string.h calculator.h
	gcc $(CFLAGS) -c main.c

calculator.o: single_roman_char_conversion.c single_roman_char_conversion.h roman_string_to_decimal_value.c roman_string_to_decimal_value.h decimal_value_to_roman_string.c decimal_value_to_roman_string.h calculator.c calculator.h
	gcc $(CFLAGS) -c single_roman_char_conversion.c roman_string_to_decimal_value.c decimal_value_to_roman_string.c calculator.c

test: calc-test
	./calc-test

calc-test: calculator-test.o single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o
	gcc -o calc-test single_roman_char_conversion.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c single_roman_char_conversion.h roman_string_to_decimal_value.h decimal_value_to_roman_string.h calculator.h
	gcc $(CFLAGS) -c calculator-test.c
