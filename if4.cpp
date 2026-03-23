#include <stdio.h>
int main(){
    float a,b,c;
    printf("\nNhap so a: ");
    scanf("%f", &a);
	printf("\nNhap so b: ");
	scanf("%f", &b);
	printf("\nNhap so c: ");
	scanf("%f", &c);
	if (a < b+c && b<a+c && c<a+b) {
		printf("Day la 3 canh cua tam giac\n");
    } else 
	{
        printf("Khong phai la tam giac\n");
    }
return 0;
}