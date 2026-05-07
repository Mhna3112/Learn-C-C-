#include <stdio.h>
int main(){
    int n;
    int *p=&n;
    printf("Nhap so nguyen: ");
    scanf("%d", &n);
    (*p)++;
    printf("Gia tri cua n: %d\n", n);
    return 0;
}