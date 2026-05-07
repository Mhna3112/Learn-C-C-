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
#define max 1000
typedef struct {
    char ten[50];
    char lop[20];
    int id;
    float gpa;
} SinhVien;
int main() {
    int n = 0; 
    int chon;
    SinhVien sv[max];
    do 
    {
    printf("1. nhap thong tin sinh vien\n");
    printf("2. in thong tin sinh vien theo id\n");
    printf("3. liet ke sinh vien co gpa can tra\n");
    printf("4. sinh vien diem cao nhat\n");
    printf("5. sinh vien diem thap nhat\n");
    printf("0. thoat\n");
    printf("Nhap lua chon: ");
    scanf("%d", &chon);
    switch (chon) {
        case 1: {
            getchar();
            printf("nhap ten sinh vien: \n");
            fgets(sv[n].ten, sizeof(sv[n].ten), stdin);
            printf("nhap lop sinh vien: \n");
            fgets(sv[n].lop, sizeof(sv[n].lop), stdin);
                printf("nhap id sinh vien: \n");
            scanf("%d", &sv[n].id);
            printf("nhap gpa sinh vien: \n");
            scanf("%f", &sv[n].gpa);
            n++;
            break;
        }
        case 2: {
            int id;
            printf("nhap id sinh vien can in thong tin: \n");
            scanf("%d", &id);
            for (int i = 0; i < n; i++) {
                if (sv[i].id == id) {
                    printf("ten: %s\n", sv[i].ten);
                    printf("lop: %s\n", sv[i].lop);
                    printf("id: %d\n", sv[i].id);
                    printf("gpa: %.2f\n", sv[i].gpa);
                }
            }
            break;
        }
        case 3: {
            float gpa;
            printf("nhap gpa can tra: \n");
            scanf("%f", &gpa);
            for (int i = 0; i < n; i++) {
                if (sv[i].gpa == gpa) {
                    printf("ten: %s\n", sv[i].ten);
                    printf("lop: %s\n", sv[i].lop);
                    printf("id: %d\n", sv[i].id);
                    printf("gpa: %.2f\n", sv[i].gpa);
                }
            }
            break;
        }
        case 4: {
            if (n==0)
            {
                printf("Khong co sinh vien de xem\n");
                break;
            }
            
            int max_gpa = 0;
            for (int i = 1; i < n; i++) { 
                if (sv[i].gpa > sv[max_gpa].gpa) {
                    max_gpa = i ;
                }
            }
                    printf("ten: %s\n", sv[max_gpa].ten);
                    printf("lop: %s\n", sv[max_gpa].lop);
                    printf("id: %d\n", sv[max_gpa].id);
                    printf("gpa: %.2f\n", sv[max_gpa].gpa);
            break;
        }
        case 5: {
            if (n==0)
            {
                printf("Khong co sinh vien de xem\n");
                break;
            }
            int min_gpa = 0;
            for (int i = 1; i < n; i++) {
                if (sv[i].gpa < sv[min_gpa].gpa) {
                    min_gpa = i;
                }
            }
                    printf("ten: %s\n", sv[min_gpa].ten);
                    printf("lop: %s\n", sv[min_gpa].lop);
                    printf("id: %d\n", sv[min_gpa].id);
                    printf("gpa: %.2f\n", sv[min_gpa].gpa);
            break;
        }
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le, vui long chon lai\n");
    }
    } while (chon != 0);
    return 0;
}