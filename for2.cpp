#include <stdio.h>

int main() {
    double tienGui, laiSuat;
    double dauThang, tienLai, cuoiThang;
    int thang;

    printf("Nhap so tien gui ban dau: ");
    scanf("%lf", &tienGui);

    printf("Nhap lai suat hang thang (%%): ");
    scanf("%lf", &laiSuat);

    if (tienGui <= 0 || laiSuat < 0) {
        printf("Du lieu nhap khong hop le.\n");
        return 0;
    }

    dauThang = tienGui;

    printf("\n===== BANG THEO DOI SO TIET KIEM =====\n\n");
    printf("%-6s %-18s %-18s %-18s\n", "Thang", "Dau thang", "Tien lai", "Cuoi thang");
    printf("--------------------------------------------------------------------\n");

    for (thang = 1; thang <= 12; thang++) {
        tienLai = dauThang * laiSuat / 100;
        cuoiThang = dauThang + tienLai;

        printf("%-6d %-18.2lf %-18.2lf %-18.2lf\n", thang, dauThang, tienLai, cuoiThang);

        dauThang = cuoiThang;
    }

    return 0;
}