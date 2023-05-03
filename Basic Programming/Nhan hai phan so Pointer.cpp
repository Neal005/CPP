#include<stdio.h>
#include<math.h>
struct PhanSo
{
	int TuSo,MauSo;
};
int GCD(int a, int b)
{
	int r;
	if(b==0) return a;
	else
	{
		r=a%b;
		return GCD(abs(b),abs(r));
	}
}
void chuanhoa(struct PhanSo *a)
{
	int u;
	u=GCD(a->TuSo,a->MauSo);
	a->TuSo=a->TuSo/u;a->MauSo=a->MauSo/u;
}
void nhan(struct PhanSo a,struct PhanSo b,struct PhanSo *c)
{
	c->TuSo=a.TuSo*b.TuSo;c->MauSo=a.MauSo*b.MauSo;
	chuanhoa(c);
}
void inPhanSo(struct PhanSo a)
{
	printf("%d/%d\n",a.TuSo,a.MauSo);
}
int main()
{
	struct PhanSo a;
	printf("Nhap phan so thu nhat: \nTu so: ");
	scanf("%d",&a.TuSo);
	printf("Mau so: ");
	scanf("%d",&a.MauSo);
	struct PhanSo b;
	printf("Nhap phan so thu hai: \nTu so: ");
	scanf("%d",&b.TuSo);
	printf("Mau so: ");
	scanf("%d",&b.MauSo);
	printf("----------------------------\n");
	struct PhanSo c;
	printf("Phan so thu nhat la:\n");
	inPhanSo(a);
	printf("Phan so thu hai la:\n");
	inPhanSo(b);
	printf("Ket qua sau khi nhan 2 phan so la:\n");
	nhan(a,b,&c);
	inPhanSo(c);
}