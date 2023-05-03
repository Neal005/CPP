#include<stdio.h>
#include<string.h>
void reverse(char str[])
{
	int n=strlen(str);
	int i=0,i1=n-1;
	char B[500];
	while(i<=n-1)
	{
		B[i]=str[i1];
		i++;
		i1--;
	}
	for(i=0;i<=n-1;i++)
	str[i]=B[i];
}
int main()
{
	char str[500];
	int len;
	fgets(str,500,stdin);
	//Remove '\n' in fgets
	len = strlen(str);
	if (str[len-1]=='\n') 
	{
   		len--;
  		str[len]='\0';
	}
	reverse(str);
	puts(str);
}