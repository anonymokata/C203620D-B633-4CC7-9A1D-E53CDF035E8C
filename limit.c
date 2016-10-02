
#include <stdio.h>
#include <stdlib.h>
#include "limit.h"
#define MAX_VALUE 3999
#define MIN_VALUE -3999
#define INVALID 0
#define VALID 1

/*------------------------------------*/
int limitation_check_subtraction(int first_number_1, int second_number_2)
{
	if((first_number_1 - second_number_2) > MAX_VALUE || (first_number_1 - second_number_2) < MIN_VALUE)
		{
			return (int)NULL;
		}
		else
			
return (abs(first_number_1 - second_number_2));
}

/*----------------------------------------*/
int is_Limit_Of_Add_Is_Not_Exceeded(int total_sum_value)
{
if(total_sum_value > MAX_VALUE)
	{
		return INVALID;
	}
	else
		  return VALID;
}



/*#define MAXIMUM_POSITIVE_VALUE 3999
#define MANIMUM_NEGATIVE_VALUE -3999
#define FALSE 0
#define TRUE 1

int is_Limit_Of_Add_Is_Not_Exceeded(int total_sum_value)
{
	int add_valid_invalid;
	printf("total sum in limit function : %d \n",total_sum_value);	
	if(total_sum_value > MAXIMUM_POSITIVE_VALUE)
	{
		add_valid_invalid = TRUE;	
	}	
	else
	{
		add_valid_invalid =  FALSE;
	}	
return add_valid_invalid; 
}


int is_Limit_Of_Subtract_Is_Not_Exceeded(int total_subtracted_value)
{
	int subtract_valid_invalid;
	if(total_subtracted_value > MAXIMUM_POSITIVE_VALUE || total_subtracted_value < MANIMUM_NEGATIVE_VALUE)
		{
			subtract_valid_invalid =  TRUE;
		}		
	else	
		{
			subtract_valid_invalid =  FALSE;
		}
return subtract_valid_invalid;		
}

*/

