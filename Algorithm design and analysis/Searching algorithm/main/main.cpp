#include <iostream>
#include "Sequence_search.h"
#include "Binary_search.h"

int main(int argc, char** argv)
{
	int A[11]={1,4,5,3,2,7};
	int i=Sequence_search(30,A,6);
	printf("\n%d",i);
	return 0;
}