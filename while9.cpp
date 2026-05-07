#include <stdio.h>

int main() {
int choice;
float a, b;
char tieptuc;

do {
printf("\n===== CHUONG TRINH TINH =====\n");
printf("1- Phep cong\n");
printf("2- Phep tru\n");
printf("3- Phep nhan\n");
printf("4- Phep chia\n");
printf("An phim khac: Thoat\n");

printf("Moi ban lua chon chuong trinh: ");
scanf("%d", &choice);

if (choice >= 1 && choice <= 4) {
printf("Nhap so thu 1: ");
scanf("%f", &a);
printf("Nhap so thu 2: ");
scanf("%f", &b);
}

switch (choice) {
case 1:
printf("Ban da chon phep cong\n");
printf("Tong hai so la: %.2f\n", a + b);
break;
case 2:
printf("Ban da chon phep tru\n");
printf("Hieu hai so la: %.2f\n", a - b);
break;
case 3:
printf("Ban da chon phep nhan\n");
printf("Tich hai so la: %.2f\n", a * b);
break;
case 4:
printf("Ban da chon phep chia\n");
if (b == 0) {
printf("Loi: Khong the chia cho 0!\n");
} else {
printf("Thuong hai so la: %.2f\n", a / b);
}
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