#include<stdio.h>
#include<math.h>
struct Point
{
    double x;
    double y;
};
Point readPointA()
{
	Point A;
	printf("Nhap toa do diem A: \n");
	scanf("%lf%lf",&A.x,&A.y);
	return A;
}
Point readPointB()
{
	Point B;
	printf("Nhap toa do diem B: \n");
	scanf("%lf%lf",&B.x,&B.y);
	return B;
}
void printPoint(Point A, Point B)
{
	printf("(%.3lf, %.3lf) va",A.x,A.y);
	printf(" (%.3lf, %.3lf) la: \n",B.x,B.y);
}
double distance(Point A,Point B)
{
    return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}
int main()
{
	Point A,B;
	A=readPointA();
	B=readPointB();
	printf("Do dai cua 2 diem: ");
	printPoint(A,B);
	printf("%.4f",distance(A,B));
}