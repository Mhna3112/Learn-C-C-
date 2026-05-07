#include <stdio.h>
#include <string.h>
void Trang(char str[]) {
    int i, j = 0;
    int space = 0;
    while (str[i] == ' ') {
        i++;
    }
    for (; i < strlen(str); i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
            space = 0;
        } else {
            if (space == 0) {
                str[j++] = ' ';
                space = 1;
            }
        }
    }
    if (j > 0 && str[j - 1] == ' ') {
        j--;
    }
    str[j] = '\0';
}
int main() {
    char str[1000];
    printf("Nhap xau: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    Trang(str);
    printf("Xau sau khi chuan hoa: \"%s\"\n", str);
    return 0;
}