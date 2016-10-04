#include <string.h>

char* error(int error_number)
{
	switch(error_number)
	{
		case 1:
			return "INVALID_OPERATION";
			break;
		case 2:
			return "LIMIT_OVERFLOW";
			break;
		case 3:
			return "INVALID_STRING";
			break;
	}
return NULL;
}
