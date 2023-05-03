#include<stdio.h>
#include<string.h>
int main()
{
	char str[500];
	fgets(str,500,stdin);
	int a=0,b=0,n=strlen(str);
	int i,i1=n-2;
	i=0;
	while(b==0)
	{
		if((str[i]==' ')&&(str[i+1]!=' ')) b=i+1;
		i++;
	}
	if(str[0]!=' ')
	{
		for(i=0;i<=(n-2)/2;i++)
		{
			if(str[i]==str[i1]) a++;
			i1--;
		}
	}
	else
	{
		for(i=b;i<=((n-2)/2)+b;i++)
		{
			if(str[i]==str[i1]) a++;
			i1--;
		}
	}
	printf("%s",str);
	if(a==n/2) printf("YES");
	else printf("NO");
}