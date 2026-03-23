#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c;
    int r1, r2, r3;

    // Nhập dữ liệu
    printf("Nhap 3 so tu 0 den 9: ");
    scanf("%d %d %d", &a, &b, &c);

    // Kiểm tra từng số (không dùng ||)
    if (a < 0) {
        printf("Nhap sai!\n");
        return 0;
    }
    if (a > 9) {
        printf("Nhap sai!\n");
        return 0;
    }

    if (b < 0) {
        printf("Nhap sai!\n");
        return 0;
    }
    if (b > 9) {
        printf("Nhap sai!\n");
        return 0;
    }

    if (c < 0) {
        printf("Nhap sai!\n");
        return 0;
    }
    if (c > 9) {
        printf("Nhap sai!\n");
        return 0;
    }

    // Random
    srand((unsigned)time(NULL));
    r1 = rand() % 10;
    r2 = rand() % 10;
    r3 = rand() % 10;

    // In kết quả
    printf("So quay: %d %d %d\n", r1, r2, r3);

    // Xét kết quả (không dùng ||)
    if (a == r1 && b == r2 && c == r3) {
        printf("Chuc mung! Ban trung giai DAC BIET!\n");
    }
    else if (a == r1 && b == r2) {
        printf("Chuc mung! Ban trung giai NHAT!\n");
    }
    else if (a == r1 && c == r3) {
        printf("Chuc mung! Ban trung giai NHAT!\n");
    }
    else if (b == r2 && c == r3) {
        printf("Chuc mung! Ban trung giai NHAT!\n");
    }
    else if (a == r1) {
        printf("Ban trung giai KHUYEN KHICH!\n");
    }
    else if (b == r2) {
        printf("Ban trung giai KHUYEN KHICH!\n");
    }
    else if (c == r3) {
        printf("Ban trung giai KHUYEN KHICH!\n");
    }
    else {
        printf("Chuc ban may man lan sau!\n");
    }

    return 0;
}