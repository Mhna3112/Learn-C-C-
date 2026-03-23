#include <stdio.h>

int main() {
    int choice;
    float a, b;

    printf("CHUONG TRINH MAY TINH DIEN TU\n");
    printf("An phim 1 - Phep cong\n");
    printf("An phim 2 - Phep tru\n");
    printf("An phim 3 - Phep nhan\n");
    printf("An phim 4 - Phep chia\n");
    printf("Thoat: an phim khac\n");

    printf("Moi ban chon phep tinh: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        printf("Thoat chuong trinh.\n");
        return 0;
    }

    printf("Nhap 2 so thuc: ");
    scanf("%f %f", &a, &b);

    if (choice == 1) {
        printf("Ket qua: %.2f\n", a + b);
    }
    else if (choice == 2) {
        printf("Ket qua: %.2f\n", a - b);
    }
    else if (choice == 3) {
        printf("Ket qua: %.2f\n", a * b);
    }
    else if (choice == 4) {
        if (b == 0) {
            printf("Khong the chia cho 0!\n");
        } else {
            printf("Ket qua: %.2f\n", a / b);
        }
    }

    return 0;
}