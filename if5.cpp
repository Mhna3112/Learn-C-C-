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
	if (delta>0) {
	x1 = (-y + sqrt(delta))/(2*x);
    x2 = (-y - sqrt(delta))/(2*x);
	printf("x1 = %f\n", x1);
    printf("x2 = %f\n", x2);
    } else 
	if (delta==0) {
	x1 = (-y/2*x);
	printf("x1 = x2 %f\n", x1);

	} else {
        printf("Phuong trinh vo nghiem\n");
    }
return 0;
}

