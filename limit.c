
#include <stdio.h>
#include <stdlib.h>
#include "limit.h"
#define MAX_VALUE 3999 // maximum positive number for the roman string
#define MIN_VALUE -3999 //minimum negative number in case of roman string 
#define INVALID 0 // defined macro returns 0 if condition fails
#define VALID 1 // defined macro retruns 1 if condition satisfies 

/*------------------------------------*/
/*function to check the maxium value of the roman string after subtracting the two decimal numbers
total_subtracted_value: this will hold the decimal value after subtracting the two decimal values
*/
int is_Limit_Of_Subtract_Is_Not_Exceeded(int total_subtracted_value)
{
	/* if condition is used checks for the maximum value , mainimum value and subtraction of the two numbers is 0. 
		If any of the condition fails returns invalid */
	if(total_subtracted_value > MAX_VALUE || total_subtracted_value < MIN_VALUE || total_subtracted_value == INVALID)
	{
		return INVALID;
	}
	else
		return VALID;
}

/*----------------------------------------*/
/*function to check the maxium value of the roman string after adding the two decimal numbers
total_sum_value: this will hold the decimal value after adding the two decimal values
*/
int is_Limit_Of_Add_Is_Not_Exceeded(int total_sum_value)
{
	/*if condition to check the maxium value if condition satisfies return invalid else
		 returns valid limit for the decimal value*/
	if(total_sum_value > MAX_VALUE)
	{
		return INVALID;
	}
	else
		return VALID;
}


