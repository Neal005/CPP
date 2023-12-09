#include<stdio.h>
#include<windows.h>

#define debug 0

float mapRePa(float x,float head1,float tail1,float head2,float tail2)
{
	if(head1>=tail1||head2>=tail2||x>tail1||x<head1||x<0||head1<0||tail1<0||head2<0||tail2<0) printf("Error!");
	else
	{
		float temp1=tail1,temp2=tail2,solve;
		temp1-=head1;
		if(debug) printf("temp 1: %.5f\n",temp1);
		temp2-=head2;
		if(debug) printf("temp 2: %.5f\n",temp2);
		x-=head1;
		x/=temp1;
		if(debug) printf("%.5f\n",x);
		return (x*temp2)+head2;
	}
	return -1;
}

int main()
{
	FILE *f;
	float tail1,tail2,head1,head2,x,solve;
	printf("\t\t**(head 1 - tail 1), (head 2 - tail 2)**\n\n");
	printf("input number to convert: ");
	scanf("%f",&x);
	printf("Enter head 1, tail 1, head 2, tail 2:\n");
	scanf("%f%f%f%f",&head1,&tail1,&head2,&tail2);
	solve=mapRePa(x,head1,tail1,head2,tail2);
	if(solve!=-1)
	{
    	if(debug) printf("\n*Solve = %.5f",solve);
    	else
    	{
    		f = fopen("MapRePa.txt", "w");
    		fprintf(f,"Input: %.5f\n(%.5f-%.5f)->(%.5f-%.5f)\n\t**Solve = %.5f**",x,head1,tail1,head2,tail2,solve);
    		fclose(f);
    	}
	    if(debug) Sleep(5000);
	}
	return 0;
}