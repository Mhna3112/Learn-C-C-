#include <stdio.h>
int main(){
    int a,b;
    printf("\nNhap so a: ");
    scanf("%d", &a);
	printf("\nNhap so b: ");
	scanf("%d", &b);
	if (a > b) {
        printf("so lon nhat la: %d\n", a);
    } else if (b > a) 
	{
        printf("so lon nhat la: %d\n", b);
    }
return 0;
}