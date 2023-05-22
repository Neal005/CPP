#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>0;j--)
        {
            printf(" ");
        }
        for(int j1=i+i-1;j1>0;j1--)
        {
            printf("*");
        }
        printf("\n");
    }
}