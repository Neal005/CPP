#include <stdio.h>
#include <math.h>
int main()
{
int a,b,c,delta;
float x1,x2,x3,x4;
scanf("%d",&a);scanf("%d",&b);scanf("%d",&c);
delta=(b*b)-(4*a*c);
if(delta<0) printf("No real roots");
x1=(-b+sqrt(delta))/(2*a);
x2=(-b-sqrt(delta))/(2*a);
if(x1<x2){x3=x1;x4=x2;}else {x4=x1;x3=x2;}
if(delta==0)printf("x = %.2f",x1);
if(delta>0)printf("x1 = %.2f\nx2 = %.2f",x3,x4);
}