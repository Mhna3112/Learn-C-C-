// Viết chương trình quản lý thông tin sinh viên.
// Yêu cầu:
// • Sử dụng switch case để người dung có thể lựa chọn ‘action’ mong muốn:
// - Tạo sinh viên gồm: Tên, Lớp, Id, GPA
// - Nhập ID và in thông tin 1 sinh viên.
// - Liệt kê tất cả sinh viên có số điểm GPA cần tra.
// - Sinh viên điểm cao nhât.
// - Sinh viên điểm thấp nhất.
// Dùng typedef hoặc #define để không cần viết từ khóa struct khi khai báo biến.
#include <stdio.h>
#include <string.h>
#define hoc_snh 1000
typedef struct {
    char ten[50];
    char lop[20];
    int id;
    float gpa;
} SinhVien;
int main() {
    switch (nhap_thong_tin_sinh_vien()
    printf("Nhap ten sinh vien: ");
    fgets(sv.ten, sizeof(sv.ten), stdin);
    pritf("Nhap lop: ");
    fgets(sv.lop, sizeof(sv.lop), stdin);
    printf("Nhap ID: ");
    scanf("%d", &sv.id);
    printf("Nhap GPA: ");
    scanf("%f", &sv.gpa);
    printf("Thong tin sinh vien da nhap:\n");
    printf("Ten: %s", sv.ten);
    printf("Lop: %s", sv.lop);
    printf("ID: %d\n", sv.id);
    printf("GPA: %.2f\n", sv.gpa);
    )
    {
    case    
        break;
}