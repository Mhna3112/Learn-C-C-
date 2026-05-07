#include <stdio.h>

#define MAX 10

int main() {
    int n;
    float a[MAX], b[MAX], c[MAX];
    int nb = 0, nc = 0;
    do {
        printf("Nhap n (n <= 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 10);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            b[nb++] = a[i];
        } else if (a[i] < 0) {
            c[nc++] = a[i];
        }
    }
    printf("\nMang b (so duong): ");
    for (int i = 0; i < nb; i++) {
        printf("%.1f ", b[i]);
    }
    printf("\nMang c (so am): ");
    for (int i = 0; i < nc; i++) {
        printf("%.1f ", c[i]);
    }
    return 0;
}