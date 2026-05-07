#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
//1.1
int kiemtraham(char s[]) {
int viet_hoa = 0, viet_thuong = 0, ky_tu_dac_biet = 0,chu_so = 0;
for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
        viet_hoa = 1;
    } else if (s[i] >= 'a' && s[i] <= 'z') {
        viet_thuong = 1;
    } else if (s[i] >= '0' && s[i] <= '9') {
        chu_so = 1;
    } else if ((s[i] >= 32 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 64) ||
               (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126)) {
        ky_tu_dac_biet = 1;
    }
}
return viet_hoa && viet_thuong && ky_tu_dac_biet && chu_so;
}
void xoaVaThemKyTu(char s[]) {
    char kytu[] = "@#$%^&*";
    int soLoai = strlen(kytu);   /* tinh 1 lan, khong goi lai trong vong lap */

    for (int i = 0; s[i]; i++) {
        if (islower(s[i])) {
            /* Thay truc tiep tai vi tri i – giu dung cho */
            s[i] = kytu[rand() % soLoai];
        }
        /* Neu khong phai chu thuong -> giu nguyen */
    }
}
int main() {
    char s[100];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0'; // Loại bỏ ký tự newline nếu có
    if (kiemtraham(s)) {
        printf("Chuoi hop le.\n");
    } else {
        printf("Chuoi khong hop le.\n");
    }
    xoaVaThemKyTu(s);
    printf("Chuoi sau khi thay doi: %s\n", s);
    return 0;
}