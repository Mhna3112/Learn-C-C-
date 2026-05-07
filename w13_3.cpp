#include<stdio.h>
#include<string.h>

int main() {
    char a[50], b[50];
    int i, j = 0, n;

    printf("nhap ho ten: ");
    fgets(a, sizeof(a), stdin);

    // xóa ký tự '\n'
    a[strcspn(a, "\n")] = '\0';

    n = strlen(a);

    // Lấy từ cuối (tên)
    for(i = n - 1; i >= 0; i--) {
        if(a[i] == ' ') break;
        b[j++] = a[i];
    }

    b[j] = '\0';

    // đảo lại chuỗi b
    printf("Ten: ");
    for(i = j - 1; i >= 0; i--) {
        printf("%c", b[i]);
    }

    return 0;
}