#include<stdio.h>
#include<math.h>
struct Point
{
	double x,y;
};
struct Rect
{
	struct Point a;
	struct Point b;
};
struct Rect readRect()
{
	struct Rect r;
	printf("Nhap toa do diem A: \n");
	scanf("%lf%lf",&r.a.x,&r.a.y);
	printf("Nhap toa do diem B: \n");
	scanf("%lf%lf",&r.b.x,&r.b.y);
	return r;
}
double distance(struct Point a, struct Point b)
{
	return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double area(struct Rect r)
{
	struct Point a,b,c;
	a.x=r.a.x;
	a.y=r.a.y;
	b.x=r.b.x;
	b.y=r.b.y;
	c.x=r.a.x;
	c.y=r.b.y;
	return distance(c,b)*distance(a,c);
}
int main()
{
	struct Rect r;
	r=readRect();
	printf("Dien tich hinh chu nhat Rect la: %.5lf",area(r));
}
