#include <stdio.h>

int main() {
    double epsilon, e, term;
    int n;

    // Nhập epsilon
    do {
        printf("Nhap epsilon (0 < epsilon < 1): ");
        scanf("%lf", &epsilon);
    } while (epsilon <= 0 || epsilon >= 1);

    // Khởi tạo
    e = 1.0;      // số hạng đầu tiên
    term = 1.0;   // 1/1!
    n = 1;

    // Cộng các số hạng cho đến khi 1/n! < epsilon
    while (term >= epsilon) {
        e += term;
        n++;
        term /= n;   // tạo số hạng tiếp theo: 1/n!
    }

    // In kết quả
    printf("Gia tri gan dung cua e = %.10lf\n", e);

    return 0;
}