#include<stdio.h>
#include<string.h>
void InTuanTu(char a[])
{
	int b,c,i=0;	
	while(i<=strlen(a))
	{
		if(a[i]==' ')
		{
			if(b==1&&c!=1) printf("\n");
			while(a[i]==' ') 
			{
				if(a[i+1]=='\0') c=1;
				i++;
			}
		}
		printf("%c",a[i]);
		b=1;
		i++;
	}
}
int main()
{
	int i;
	char a[100];
	printf("Nhap chuoi ky tu:\n");
	fgets(a,sizeof(a),stdin);
	for(i=1;i<=strlen(a)-1;i++)
	{
		printf("-");
	}
	printf("---\n");
	InTuanTu(a);
}
