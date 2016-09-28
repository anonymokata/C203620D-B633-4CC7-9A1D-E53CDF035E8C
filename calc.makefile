CFLAGS=-Wall
LIBS=-lcheck -lpthread -lm -lrt

all: calc

calc: main.o single_roman_char_conversion.o 
	gcc -o calc main.o single_roman_char_conversion.o 

main.o: main.c single_roman_char_conversion.h
	gcc $(CFLAGS) -c main.c

calculator.o: single_roman_char_conversion.c single_roman_char_conversion.h
	gcc $(CFLAGS) -c single_roman_char_conversion.c

test: calc-test
	./calc-test

calc-test: calculator-test.o single_roman_char_conversion.o
	gcc -o calc-test single_roman_char_conversion.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c single_roman_char_conversion.h
	gcc $(CFLAGS) -c calculator-test.c
