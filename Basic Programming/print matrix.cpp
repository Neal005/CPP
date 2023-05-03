#include <stdio.h>
#include <math.h>
int main()
{
    int i,n,j,m,a;
    scanf("%d%d",&m,&n);
    a=100;
    for (i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
        	if(i>a)printf("\n");
        	a=i;
            printf("%d ",(j-1)*m + i);
        }
    }
}