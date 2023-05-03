#include <stdio.h>
int main()
{
    int s,h,m;
    scanf("%d",&s);
    h=s/3600;
    s=s%3600;
    m=s/60;
    s=s%60;
    if (h<10)
        printf("0%d:",h);
    else
        printf("%d:",h);
    if (m<10)
        printf("0%d:",m);
    else
        printf("%d:",m);
    if (s<10)
        printf("0%d",s);
    else
        printf("%d",s);
}