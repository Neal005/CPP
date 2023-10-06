#include "../lib/struct.h"

void Swap(recordtype *x, recordtype *y)
{
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}