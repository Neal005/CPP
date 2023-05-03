#include<stdio.h>
#include<math.h>
struct Point
{
	double X,Y;
};
struct Point readPointA()
{
	struct Point A;
	printf("Nhap toa do diem A: \n");
	scanf("%lf%lf",&A.X,&A.Y);
	return A;
}
struct Point readPointB()
{
	struct Point B;
	printf("Nhap toa do diem B: \n");
	scanf("%lf%lf",&B.X,&B.Y);
	return B;
}
struct Point readPointC()
{
	struct Point C;
	printf("Nhap toa do diem C: \n");
	scanf("%lf%lf",&C.X,&C.Y);
	return C;
}
double distance(struct Point A,struct Point B)
{
    return sqrt(pow(A.X-B.X,2)+pow(A.Y-B.Y,2));
}
int isTriangle(struct Point A,struct Point B,struct Point C)
{
	double Max,a1,a2;
	if(distance(A,B)>=distance(A,C)&&distance(B,C)) 
	{
		Max=distance(A,B);
		a1=distance(A,C);
		a2=distance(B,C);
	}
	if(distance(A,C)>=distance(A,B)&&distance(B,C)) 
	{
		Max=distance(A,C);
		a1=distance(A,B);
		a2=distance(B,C);
	}
	if(distance(C,B)>=distance(A,C)&&distance(B,A)) 
	{
		Max=distance(C,B);
		a1=distance(A,C);
		a2=distance(B,A);
	}
    if(a1+a2>Max) return 1;
    else return 0;
}
int main()
{
	struct Point A,B,C;
	A=readPointA();
	B=readPointB();
	C=readPointC();
	if (isTriangle(A,B,C))
	printf("3 diem vua nhap la 3 dinh cua 1 tam giac");
	else printf("3 diem vua nhap khong phai la 3 dinh cua 1 tam giac");
}