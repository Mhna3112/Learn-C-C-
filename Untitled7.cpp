#include<stdio.h>
#include <math.h>
int main (){
		float x,y,z,f ;
	printf("nhap x:");
	scanf("%f", &x);
	printf ("nhap y:");
	scanf("%f", &y);
	printf ("nhap z:");
	scanf("%f", &z);
	f =(x*y + z*z) / (x - y) + sin(x*z) + cos(y);
	printf("F = %.f", f);
return 0;
}
