#include <stdio.h>
#define n 12
float luongMua[n];
void nhap() {
    for (int i = 0; i < n; i++) {
        printf("Nhap luong mua thang %d (mm): ", i + 1);
        scanf("%f", &luongMua[i]);
    }
}
void xuat() {
    printf("\nBang luong mua trong nam:\n");
    printf("Thang\tLuong mua (mm)\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.1f\n", i + 1, luongMua[i]);
    }
}
int main() {
    nhap();
    xuat();
    return 0;
}