#include<stdio.h>
#include<math.h>
struct PhanSo
{
	int TuSo,MauSo;
};
int GCD(int a,int b)
{
	int r;
	if(b==0)return a;
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
	a->TuSo=(a->TuSo)/u;a->MauSo=(a->MauSo)/u;
}
void inPhanSo(struct PhanSo a)
{
	printf("%d/%d\n",a.TuSo,a.MauSo);
}
int main()
{
	struct PhanSo a;
	printf("Nhap tu so: \n");
	scanf("%d",&a.TuSo);
	printf("Nhap mau so: \n");
	scanf("%d",&a.MauSo);
	printf("----------------------------\n");
	printf("Phan so vua nhap la: \n");
	inPhanSo(a);
	chuanhoa(&a);
	printf("Phan so sau khi chuan hoa la: \n");
	inPhanSo(a);
}
