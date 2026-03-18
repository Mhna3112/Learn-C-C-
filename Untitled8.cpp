#include<stdio.h>
#include <math.h>
int main (){
	int a,b,c,d,e,f ;
	printf("nhap so dien:");
	scanf("%d", &a);
	b=(a<50)?a:50;
	c=(a<100)?((a>50)?(a-50):0):50;
	d=(a<150)?((a>100)?(a-100):0):50;
	e=(a>150)?(a-150):0;
	printf("b=%d c=%d d=%d e=%d\n" , b,c,d,e);
	printf("so tien tieu thu trong thang la %d \n",a);
	f=b*500+c*1000+d*1200+e*1600;
	printf("so tien phai tra la %d\n ",f);
return 0;
}
