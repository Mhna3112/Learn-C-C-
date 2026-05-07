#include <stdio.h>

int main() {
int n, sum = 0;

printf("Nhap n: ");
	scanf("%d", &n);

if (n < 1) {
	printf("n phai la so nguyen duong!\n");
return 0;
	}

	for (int i = 1; i <= n; i++) {
	sum += i;
		}

printf("Tong cac so tu 1 den %d la: %d\n", n, sum);

return 0;
}