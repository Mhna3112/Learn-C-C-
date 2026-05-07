#include <stdio.h>

int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int a[n];  // VLA

    for (int i = 0; i < n; i++){
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Mang: ");
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}