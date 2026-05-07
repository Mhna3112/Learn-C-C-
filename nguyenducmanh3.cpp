#include <stdio.h>
#include <string.h>
//3.1
typedef struct {
    char  ten[31];
    int   namSinh;
    float canNang;
    float chieuCao;
    float bmi;
} KhachHang;
// TÍNH BMI
float tinhBMI(float cn, float cc) {
    return cn / (cc * cc);
}
// NHẬP KHÁCH HÀNG
void nhapKH(KhachHang *kh) {
    while (getchar() != '\n');
    // tên
    do {
        printf("Ten (<=30 ky tu): ");
        fgets(kh->ten, sizeof(kh->ten), stdin);
        kh->ten[strcspn(kh->ten, "\n")] = '\0';
    } while (strlen(kh->ten) == 0 || strlen(kh->ten) > 30);
    // năm sinh
    do {
        printf("Nam sinh: ");
        if (scanf("%d", &kh->namSinh) != 1 || kh->namSinh <= 0) {
            while (getchar() != '\n');
            kh->namSinh = -1;
        }
    } while (kh->namSinh <= 0);

    // cân nặng
    do {
        printf("Can nang: ");
        if (scanf("%f", &kh->canNang) != 1 || kh->canNang <= 0) {
            while (getchar() != '\n');
            kh->canNang = -1;
        }
    } while (kh->canNang <= 0);
    // chiều cao
    do {
        printf("Chieu cao: ");
        if (scanf("%f", &kh->chieuCao) != 1 || kh->chieuCao <= 0) {
            while (getchar() != '\n');
            kh->chieuCao = -1;
        }
    } while (kh->chieuCao <= 0);

    kh->bmi = tinhBMI(kh->canNang, kh->chieuCao);
}
// PHÂN LOẠI BMI
char* xepLoai(float bmi) {
    if (bmi < 18.5) return "Gay";
    else if (bmi < 25) return "Binh thuong";
    else if (bmi < 30) return "Thua can";
    else return "Beo phi";
}

// THỐNG KÊ NHÓM TUỔI
void thongKeNhomTuoi(KhachHang ds[], int n, int namHienTai) {
    int thieuNien = 0, thanhNien = 0, trungNien = 0, nguoiGia = 0;
    for (int i = 0; i < n; i++) {
        int tuoi = namHienTai - ds[i].namSinh;
        if (tuoi >= 11 && tuoi <= 16) thieuNien++;
        else if (tuoi <= 40) thanhNien++;
        else if (tuoi <= 60) trungNien++;
        else nguoiGia++;
    }
    printf("\n===== THONG KE =====\n");
    printf("Thieu nien: %d\n", thieuNien);
    printf("Thanh nien: %d\n", thanhNien);
    printf("Trung nien: %d\n", trungNien);
    printf("Nguoi gia : %d\n", nguoiGia);
}
// SẮP XẾP BMI GIẢM DẦN
void sapXep(KhachHang ds[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ds[i].bmi < ds[j].bmi) {
                KhachHang t = ds[i];
                ds[i] = ds[j];
                ds[j] = t;
            }
}
// IN TOP N
void inTop(KhachHang ds[], int n) {
    printf("\nTOP %d BMI CAO NHAT:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d | %s | %d | %.2f | %s\n",
               i + 1,
               ds[i].ten,
               ds[i].namSinh,
               ds[i].bmi,
               xepLoai(ds[i].bmi));
    }
}

// MAIN
int main() {
    int m;
    do {
        printf("Nhap so khach: ");
        scanf("%d", &m);
    } while (m <= 0);
    KhachHang ds[100];
    for (int i = 0; i < m; i++) {
        printf("\nKhach %d:\n", i + 1);
        nhapKH(&ds[i]);
    }
    int namHienTai = 2026; // năm hiện tại

    thongKeNhomTuoi(ds, m, namHienTai);
    sapXep(ds, m);
    int n;
    printf("\nNhap n: ");
    scanf("%d", &n);
    inTop(ds, n);
    return 0;
}