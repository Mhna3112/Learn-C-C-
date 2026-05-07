#include <stdio.h>

int tinh(int n){
	int i = 1,s= 1;
    while(i <= n){
        s = s * i;
        i++;
    }
    return s;
}

int main(){
    int n;
    printf("nhap so N: ");
    scanf("%d", &n);

    int kq = tinh(n);

    printf("ket qua la: %d\n", kq);
    return 0;
}