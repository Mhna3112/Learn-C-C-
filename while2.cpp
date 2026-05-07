#include <stdio.h>
int tong(int n){
	int i = 1, tong = 0;
	while (i<= n){
		tong += i;
        i++;
    }
	return tong;
}

int main() {
    int n;
    printf("Nhap so N: ");
    scanf("%d", &n);
	while (n<=10 || n>=1000){
		printf("ban da nhap sai so\n");
		printf("nhap so N: ");
		scanf("%d", &n);
	}
		int kq = tong(n);
    printf("Tong tu 1 den %d la: %d\n", n, kq);

    return 0;
}