#include <stdio.h>

int main() {
    int i = 1, N;

    printf("Nhap N: ");
    scanf("%d", &N);

    do {
        printf("%d ", i);
    } while (++i <= N);

    return 0;
}