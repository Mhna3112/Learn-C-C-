#include <stdio.h>

int main() {
int n, lua_chon, tong = 0;

printf("Nhap n (so nguyen duong): ");
	scanf("%d", &n);

printf("Ban muon tinh tong so gi?\n");
printf("1. Tong cac so chan\n");
printf("2. Tong cac so le\n");
printf("Chon 1 hoac 2: ");
	scanf("%d", &lua_chon);

	if(lua_chon == 1) {
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 0)
	tong += i;
	}
printf("Tong cac so chan tu 1 den %d la: %d\n", n, tong);
		}
	else if(lua_chon == 2) {
	for(int i = 1; i <= n; i++) {
	if(i % 2 != 0)
	tong += i;
			}
		printf("Tong cac so le tu 1 den %d la: %d\n", n, tong);
				}
	else {
	printf("Lua chon khong hop le!\n");
					}

return 0;
}