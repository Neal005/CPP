#include<stdio.h>
#include<string.h>
int VerifyReverse(char str[])
{
	int a=0,n=strlen(str);
	int i=0,i1=n-1;
	char B[500];
	while(i<=n-1)
	{
		B[i]=str[i1];
		i++;
		i1--;
	}
	for(i=0;i<=n-1;i++)
	{
		if(str[i]==B[i]) a++;
	}
	if(a==n) return 1; else return 0;
}
int main()
{
	char str[500];
	int len;
	fgets(str,500,stdin);
	len = strlen(str);
	if (str[len-1]=='\n') 
	{
   		len--;
		str[len]='\0';
	}
	printf("%s\n",str);
	if(VerifyReverse(str)) printf("Yes");else printf("No");
}