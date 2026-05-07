#include <stdio.h>
#define m 10
int main() {
    int n;
    float a[m];
    do {
        printf("Nhap n (n < 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 10);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
    printf("\nDay vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", a[i]);
    }
    float tongDuong = 0;
    float tongAm = 0;
    int demAm = 0;
    int dem0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) tongDuong += a[i];
        if (a[i] < 0) {
            tongAm += a[i];
            demAm++;
        }
        if (a[i] == 0) dem0++;
    }
    printf("\n\nTong cac so duong = %.1f", tongDuong);
    if (demAm > 0)
        printf("\nTrung binh cong cac so am = %.2f", tongAm / demAm);
    else
        printf("\nKhong co so am");
    printf("\nSo luong so 0 = %d", dem0);
    float x;
    printf("\n\nNhap x: ");
    scanf("%f", &x);
    int found = 0;
    printf("Vi tri cua x trong day: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co");
    }
    return 0;
}