#include <stdio.h>

int main() {
    int n, i, j;

    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("n khong thoa man dieu kien");
        return 0;
    }

    // Khung in ma tran n x n
    for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
        printf("%d ", j);
    }
    printf("\n");
}

    return 0;
}