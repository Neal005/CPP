#include<stdio.h>
#include<math.h>
int main()
{
	char str[500];
	int dem;
	fgets (str, 500, stdin);
	printf("%s", str);
	int k=0;
	{
		if (str[k]==' ') k++;
	} 
	while (str[k]==' ');
	for(int i=k;i<strlen(str);i++)
	{
		if(str[i]-32 && str[i+1]!=32)
		{
			dem=0;
		}
		else dem=1;
		for(int i-k; i<strlen(str); i++)
		{
			if(str[i]=32 && str[i+1]!=32)
			{
				dem+ 1;
			}
		}
	}
}