#include <stdio.h>
int main()
{
	int d,m,y;
	scanf("%d",&d);scanf("%d",&m);scanf("%d",&y);
	if(y%400==0||(y%4==0&&y%100!=0)){
		if(m==1) printf("%d",d);else{
		if(m==2) printf("%d",d+31);else{
		if(m==3) printf("%d",d+60);else{
		if(m==4) printf("%d",d+91);else{
		if(m==5) printf("%d",d+121);else{
		if(m==6) printf("%d",d+152);else{
		if(m==7) printf("%d",d+182);else{
		if(m==8) printf("%d",d+213);else{
		if(m==9) printf("%d",d+244);else{
		if(m==10) printf("%d",d+274);else{
		if(m==11) printf("%d",d+305);else{
		if(m==12) printf("%d",d+335);}}}}}}}}}}}}
	else{
		if(m==1) printf("%d",d);else{
		if(m==2) printf("%d",d+31);else{
		if(m==3) printf("%d",d+59);else{
		if(m==4) printf("%d",d+90);else{
		if(m==5) printf("%d",d+120);else{
		if(m==6) printf("%d",d+151);else{
		if(m==7) printf("%d",d+181);else{
		if(m==8) printf("%d",d+212);else{
		if(m==9) printf("%d",d+243);else{
		if(m==10) printf("%d",d+273);else{
		if(m==11) printf("%d",d+304);else{
		if(m==12) printf("%d",d+334);}}}}}}}}}}}}
}