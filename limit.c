


#define MAXIMUM_POSITIVE_VALUE 3999
#define MANIMUM_NEGATIVE_VALUE -3999

char* is_Limit_Of_Add_Is_Not_Exceeded(int total_sum_value)
{
	if(total_sum_value > MAXIMUM_POSITIVE_VALUE)
	
		return "FALSE" ;	
	else
		return "TRUE";
}


char* is_Limit_Of_Subtract_Is_Not_Exceeded(int total_subtracted_value)
{
	if(total_subtracted_value > MAXIMUM_POSITIVE_VALUE || total_subtracted_value < MANIMUM_NEGATIVE_VALUE)
		
			return "FALSE";
		else
			return "TRUE";
}

