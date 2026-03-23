#include <stdio.h>
int main() {
    float a;
    printf("\nNhap so a: ");
    scanf("%f", &a);

    if (a >= 0 && a < 5) {
        printf("hoc luc kem");
    } 
    else if (a >= 5 && a < 7) {
        printf("hoc luc trung binh");
    } 
    else if (a >= 7 && a < 8) {
        printf("hoc luc kha");
    } 
    else if (a >= 8 && a < 9) {
        printf("hoc luc gioi");
    } 
    else if (a >= 9 && a <= 10) {
        printf("hoc luc xuat sac");
    } 
    else {
        printf("khong hop le");
    }

    return 0;
}