#include<stdio.h>
#include <math.h>
int main (){
		float x,y,z,delta,x1,x2 ;
	printf("nhap x:");
	scanf("%f", &x);
	printf ("nhap y:");
	scanf("%f", &y);
	printf ("nhap z:");
	scanf("%f", &z);
	delta = y*y - 4*x*z ;
	printf ("delta= %f\n", delta);
	x1 = (delta > 0) ? (-y + sqrt(delta))/(2*x) :0 ;
    x2 = (delta > 0) ? (-y - sqrt(delta))/(2*x) :0 ;
    printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
return 0;
}

