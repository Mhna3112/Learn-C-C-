#include <stdio.h>

int main() {
    char tenPhim[50];
    int soLuong;
    int loaiVe;
    int ngayXem;
    float giaVe, tongTien;
    printf("Ten phim: ");
    gets(tenPhim);
    printf("So luong ve: ");
    scanf("%d", &soLuong);
    printf("Loai ve (Nhap 1- Tre em, khac- Nguoi lon): ");
    scanf("%d", &loaiVe);
    printf("Ngay xem (Nhap 1- Chu nhat, khac- Ngay thuong): ");
    scanf("%d", &ngayXem);
    if (ngayXem == 1)
        giaVe = 10;
    else
        giaVe = 7;
    if (loaiVe == 1)
        giaVe = giaVe * 0.5;
    tongTien = giaVe * soLuong;
    printf("\nThong tin ve:\n");
    printf("- Ten phim: %s\n", tenPhim);
    if (ngayXem == 1)
        printf("- Ngay xem: Chu nhat\n");
    else
        printf("- Ngay xem: Ngay thuong\n");
    printf("- So luong ve: %d\n", soLuong);
    printf("- So tien thanh toan: %.0f\n", tongTien);
    return 0;
}