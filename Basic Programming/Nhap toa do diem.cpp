#include<stdio.h>
struct Point
{
    double x,y;
};
Point readPoint()
{
	Point a;
	printf("Nhap toa do diem A: \n");
    scanf("%lf%lf",&a.x,&a.y);
    return a;
}
void printPoint(Point a)
{
    printf("Toa do diem A la: (%.3lf, %.3lf)\n",a.x,a.y);
}
int main()
{
	Point a,b;
	a=readPoint();
	printPoint(a);
}