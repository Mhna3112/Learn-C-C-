#include<stdio.h>
int main (){
	int a,b,c,kq1,kq2;
	printf("a=");scanf("%d",&a);
	printf("b=");scanf("%d",&b);
	printf("c=");scanf("%d",&c);
	kq1 = a++ + ++a;
	kq2 = --a - b-- * ++c;
	printf("ket qua 1:%d\n", kq1);
	printf("ket qua 2: %d\n", kq2);
return 0;
}

