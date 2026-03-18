#include<stdio.h>
int main (){
	float a,b,c,max;
	printf("a=");scanf("%f",&a);
	printf("b=");scanf("%f",&b);
	printf("c=");scanf("%f",&c);
	max=(a>b)?a:b;
	max=(max>c)?max:c;
	printf("so lon nhat la %f",max);
}
