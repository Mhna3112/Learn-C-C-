#include <stdio.h>

int main() {
    float a, b, c;

    printf("Nhap so a: ");
    scanf("%f", &a);

    printf("Nhap so b: ");
    scanf("%f", &b);

    printf("Nhap so c: ");
    scanf("%f", &c);

    if (a <= b && a <= c) {
        printf("So nho nhat la: %.2f\n", a);
    }
    else if (b <= a && b <= c) {
        printf("So nho nhat la: %.2f\n", b);
    }
    else {
        printf("So nho nhat la: %.2f\n", c);
    }

    return 0;
}