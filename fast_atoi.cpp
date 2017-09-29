#include "fast_atoi.h"

int fast_atoi(const char* str)
{
	int val = 0;
 	while (*str){
		val = val*10 + (*str++ - '0');
	}
	return val;
}