#include <stdio.h>
int main(){
    float a,b,c;
    printf("\nNhap so a: ");
    scanf("%f", &a);
	printf("\nNhap so b: ");
	scanf("%f", &b);
	printf("\nNhap so c: ");
	scanf("%f", &c);
	if (a < b) {
        printf("so lon nhat la: %d\n", a);
    } else 
	if (b < a) 
	{
        printf("so lon nhat la: %d\n", b);
    }
return 0;
}