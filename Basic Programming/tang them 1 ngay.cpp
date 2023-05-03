#include <stdio.h>
int main()
{
	int d,m,y;
	scanf("%d%d%d",&d,&m,&y);
	if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10)&&m>=9)printf("01/%d/%d",m+1,y);else{
	if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10)&&m<9)printf("01/0%d/%d",m+1,y);else{
	if(d==30&&(m==4||m==6||m==9||m==11)&&m>=9)printf("01/%d/%d",m+1,y);else{
	if(d==30&&(m==4||m==6||m==9||m==11)&&m<9)printf("01/0%d/%d",m+1,y);else{
	if(d==31&&m==12)printf("01/01/%d",y+1);else{
	if(d==29&&m==2)printf("01/03/%d",y);else{
	if(d==28&&m==2)printf("01/03/%d",y);else{
	if(d<10)printf("0%d/%d/%d",d+1,m,y);else{
	if(m<10)printf("%d/0%d/%d",d+1,m,y);else{
	printf("%d/%d/%d",d+1,m,y);}}}}}}}}}  
}