#include <stdio.h>
#include <string.h>
int dem(char str[]) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}
int main() {
    char str[1000];
    printf("Nhap mot dong ky tu: ");
    fgets(str, sizeof(str), stdin);
    int soKhoangTrang = dem(str);
    printf("So ky tu khoang trang trong xau la: %d\n", soKhoangTrang);
    return 0;
}