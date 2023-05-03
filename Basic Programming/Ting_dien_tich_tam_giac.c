#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,CV,P,S,s,Max,Canh1,Canh2;
	printf("Nhap do dai canh a: ");scanf("%f",&a);
	printf("Nhap do dai canh b: ");scanf("%f",&b);
	printf("Nhap do dai canh c: ");scanf("%f",&c);
	if(a>=b&&a>=c) {Max=a;Canh1=b;Canh2=c;}
	if(b>=a&&b>=c) {Max=b;Canh1=c;Canh2=a;}
	if (c>=a&&c>=b){Max=c;Canh1=a;Canh2=b;}
	if (Max>=Canh1+Canh2)
	printf("Do dai 3 canh %.3f, %.3f, %.3f khong phai la do dai 3 canh cua 1 tam giac.",a,b,c);
	else{
	CV=a+b+c;
	P=CV/2;
	S=sqrt(P*(P-a)*(P-b)*(P-c));
	printf("Dien tich tam giac la: %.5fcm2",S);}
}