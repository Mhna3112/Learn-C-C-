#include <stdio.h>

int ucln(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int bcnn(int a, int b){
    return (a * b) / ucln(a, b);
}
int main(){
    int a, b;
    printf("Nhap hai so nguyen: ");
    scanf("%d %d", &a, &b);
    int kq = bcnn(a, b);
    printf("Boi so chung nho nhat la: %d", kq);
    return 0;
}