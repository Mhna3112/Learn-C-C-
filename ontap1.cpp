#include <stdio.h>
int main() {
    int a=10;
    int *p=&a;
    printf("Gia tri cua a: %d\n", a);
    printf("Dia chi cua a: %p\n", &a);
    printf("Gia tri cua p: %p\n", p);
    printf("Gia tri ma p tro toi: %d\n", *p);
}
