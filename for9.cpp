#include <stdio.h>

int main() {
    int n, i;
    float S = 0;

    printf("Nhap n = ");
    scanf("%d", &n);

    if (n < 1) {
        printf("n khong hop le");
        return 0;
    }

    for (i = 1; i <= n; i++) {
        S = S + 1.0 / i;
    }

    printf("S = %f", S);

    return 0;
}