
#include <stdio.h>
#include <stdlib.h>
#include "limit.h"
#define MAX_VALUE 3999
#define MIN_VALUE -3999
#define INVALID 0
#define VALID 1

/*------------------------------------*/
int is_Limit_Of_Subtract_Is_Not_Exceeded(int total_subtracted_value)
{
	if(total_subtracted_value > MAX_VALUE || total_subtracted_value < MIN_VALUE || total_subtracted_value == INVALID)
		{
			return INVALID;
		}
		else
			
			return VALID;
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


