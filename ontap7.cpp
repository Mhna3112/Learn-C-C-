 //Cho chuỗi ký tự, dùng con trỏ để:
// Đếm số ký tự
// Không dùng strlen
#include <stdio.h>
int main(){
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    
    char *p = str;
    int count = 0;
    
    while (*p != '\0') {
        count++;
        p++;
    }
    
    printf("So ky tu trong chuoi: %d\n", count - 1); // Trừ 1 để loại bỏ ký tự newline
    return 0;
}