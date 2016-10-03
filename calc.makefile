CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o validation.o limit.o toUpperString.o
	gcc -o calc main.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o validation.o limit.o toUpperString.o

main.o: main.c roman_string_to_decimal_value.h decimal_value_to_roman_string.h calculator.h validation.h limit.h toUpperString.h
	gcc $(CFLAGS) -c main.c

calculator.o: roman_string_to_decimal_value.c roman_string_to_decimal_value.h decimal_value_to_roman_string.c decimal_value_to_roman_string.h calculator.c calculator.h validation.c validation.h limit.c limit.h toUpperString.c toUpperString.h
	gcc $(CFLAGS) -c roman_string_to_decimal_value.c decimal_value_to_roman_string.c calculator.c validation.c limit.c toUpperString.c

test: calc-test
	./calc-test

calc-test: calculator-test.o roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o validation.o limit.o toUpperString.o
	gcc -o calc-test roman_string_to_decimal_value.o decimal_value_to_roman_string.o calculator.o validation.o limit.o toUpperString.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c roman_string_to_decimal_value.h decimal_value_to_roman_string.h calculator.h validation.h limit.h toUpperString.h
	gcc $(CFLAGS) -c calculator-test.c
