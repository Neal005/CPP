#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<string.h>
char* subString(char st[], int pos, int number)
{
    char *b=(char*)malloc((number)*sizeof(char));
    int i,i1=0;
    for(i=pos;i<=number+pos-1;i++)
    {
        b[i1]=st[i];
        i1++;
    }
    b[number]='\0';
    return b;
}
int main()
{
	int pos,number;
	char st[1000];
	printf("Nhap chuoi ky tu: \n");
	fgets(st,1000,stdin);
	st[strlen(st)-1]='\0';
	printf("Nhap vi tri can lay: \n");
	scanf("%d",&pos);
	printf("Nhap do rong ky tu can lay: \n");
	scanf("%d",&number);
	printf("----------------------------------\n");
	char *res = subString(st,pos,number);
	printf("(*) Chuoi ky tu da nhap la: \n");
	puts(st);
	printf("(*) Chuoi Ky tu da lay la: \n");
	puts(res);
	free(res);
}