#include <stdio.h>
//2.1
void nhapMaTran(int a[100][100], int *m, int *n) {
    printf("Nhap m, n: ");
    scanf("%d %d", m, n);

    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
//2.2
float trungBinhChan(int a[100][100], int m, int n) {
    int tong = 0, dem = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 == 0) {
                tong += a[i][j];
                dem++;
            }

    return dem ? (float)tong / dem : 0;
}
//2.3
void inMaTran(int a[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }
}
int main() {
    int a[100][100], m, n;
    nhapMaTran(a, &m, &n);
    printf("Ma tran vua nhap:\n");
    inMaTran(a, m, n);
    printf("Trung binh chan: %.2f\n", trungBinhChan(a, m, n));
    return 0;
}
