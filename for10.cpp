#include <stdio.h>

int main() {
    int i, n;
    int kiem_tra = 0;

    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("%d khong phai la so nguyen to\n", n);
        return 0;
    }

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            kiem_tra = 1;
            break;
        }
    }

    if (kiem_tra == 1) {
        printf("%d khong phai la so nguyen to\n", n);
    } else {
        printf("%d la so nguyen to\n", n);
    }

    return 0;
}