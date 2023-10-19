#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "./lib/struct.h"
#include "./lib/function.h"
#include "./lib/sort.h"

int main()
{
	char chose='0';
	do
	{
		int stop=0;
		do
		{
			printf("1. Bubble Sort\t2. Selection Sort\t3. Insertion Sort\n4. Quick Sort\t5. Variant Quick Sort\t6. Heap Sort\n\t\t  *E. Exit*\nChose: ");
			scanf("%c",&chose);
			if(chose=='e'||chose=='E') stop=1;
			system("cls");
		} while((chose>'6'||chose<'1')&&!stop);
		if(chose<'7'&&chose>'0')
		{
			int mod=atoi(&chose);
			char name[][100] = {
			    "Bubble",
			    "Selection",
			    "Insertion",
			    "Quick",
			    "Variant quick",
			    "Heap"
			};
			recordtype a[100];
			int n;
			readData(a,&n);
			printf("*\"%s sort\" algorithm*\n",name[mod-1]);
			printf("\nBefore sorting:\n");
			printData(a,n);
			printf("\nAfter sorting:\n");
			if(mod==1) bubbleSort(a,n);
			if(mod==2) selectionSort(a,n);
			if(mod==3) insertionSort(a,n);
			if(mod==4) quickSort(a,0,n-1);
			if(mod==5) variantQuickSort(a,0,n-1);
			if(mod==6) heapSort(a,n);
			printData(a,n);
		}
		if(chose!='e'&&chose!='E')
		{
			char ctn='0';
			do
			{
				printf("\n*Continue?\n\t1. Yes\t2. No\n");
				fflush(stdin);
				scanf("%c",&ctn);
				if(ctn=='2') chose='e';
			}while(ctn!='1'&&ctn!='2');			
		}
	}while(chose!='e'&&chose!='E');
	return 0;
}