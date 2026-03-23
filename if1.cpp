#include <stdio.h>
int main(){
    int a;
    printf("Nhap so a: ");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("Ban vua nhap so chan");
    }
    else
    {
        printf("Ban vua nhap so le");
    }
    return 0;
}