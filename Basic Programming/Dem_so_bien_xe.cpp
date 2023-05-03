#include <stdio.h>
int main()
{
    int n,n1,n2,n3,n4,i;
    scanf("%d",&n);
    n4 = n % 10; n = n / 10;
    n3 = n % 10; n = n / 10;
    n2 = n % 10; n = n / 10;
    n1 = n;
    i = (n1 + n2 + n3 + n4) % 10;
    printf("%d",i);
}