#include <stdio.h>
void doi(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int a=10;
    int b=30;
    printf("Gia tri cua a: %d\n", a);
    printf("Gia tri cua b: %d\n", b);
    doi(&a, &b);
    printf("Gia tri cua a sau khi doi: %d\n", a);
    printf("Gia tri cua b sau khi doi: %d\n", b);
    return 0;
}