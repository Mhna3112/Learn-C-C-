#include <stdio.h>
int ucln(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(){
    int a, b;
    printf("Nhap hai so nguyen duong: ");
    scanf("%d %d", &a, &b);
    int kq = ucln(a, b);
    printf("Uoc so chung lon nhat la: %d", kq);
    return 0;
}