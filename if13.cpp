#include <stdio.h>

int main() {
    int days;
    float medicine, surgery = 0;
    char type, op;

    printf("Nhap so ngay nam vien: ");
    scanf("%d", &days);

    printf("Nhap tien thuoc: ");
    scanf("%f", &medicine);

    printf("Co phau thuat khong? (y/n): ");
    scanf(" %c", &op);

    if (op == 'y' || op == 'Y') {
        printf("Nhap tien phau thuat: ");
        scanf("%f", &surgery);
    }

    printf("Nhap loai the bao hiem (G/S/C): ");
    scanf(" %c", &type);

    float room = days * 150000;
    float total = room + medicine + surgery;
    float pay;

    if (type == 'G' || type == 'g') {
        pay = total * 0.3;
    }
    else if (type == 'S' || type == 's') {
        pay = total * 0.5;
    }
    else {
        pay = total * 0.7;
    }

    printf("\n===== HOA DON VIEN PHI =====\n");
    printf("Phi noi tru: %.0f\n", room);
    printf("Tien thuoc: %.0f\n", medicine);
    printf("Tien phau thuat: %.0f\n", surgery);
    printf("Tong chi phi: %.0f\n", total);
    printf("So tien phai tra: %.0f\n", pay);

    return 0;
}