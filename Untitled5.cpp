#include<stdio.h>
int main (){
		float x,y,z,delta ;
	printf("nhap x:");
	scanf("%f", &x);
	printf ("nhap y:");
	scanf("%f", &y);
	printf ("nhap z:");
	scanf("%f", &z);
	delta = y*y - 4*x*z ;
	printf ("delta= %f", delta);
return 0;
}

