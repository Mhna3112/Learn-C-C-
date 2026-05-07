#include <stdio.h>
#include <math.h>

int main() {
int choice;
double x;
char tieptuc;

do {
	printf("\n===== CHUONG TRINH TINH =====\n");
	printf("1- So pi\n");
	printf("2- So e\n");
	printf("3- sin(x)\n");
	printf("An phim khac: Thoat\n");
	printf("Moi ban lua chon chuong trinh: ");
	scanf("%d", &choice);
	
switch (choice) {
case 1:
printf("Ban da chon chuong trinh 1\n");
printf("So pi = %.5f\n", M_PI); 
break;
case 2:
printf("Ban da chon chuong trinh 2\n");
printf("So e = %.5f\n", M_E); 
break;
case 3:
printf("Ban da chon chuong trinh 3\n");
printf("Nhap gia tri x (radian): ");
scanf("%lf", &x);
printf("sin(%.2f) = %.5f\n", x, sin(x));
break;
default:
printf("Thoat chuong trinh.\n");
return 0;
}

printf("Ban co muon tiep tuc chuong trinh? (y/n): ");
scanf(" %c", &tieptuc); 

} while (tieptuc == 'y' || tieptuc == 'Y');

printf("Cam on ban da su dung chuong trinh!\n");
return 0;
}