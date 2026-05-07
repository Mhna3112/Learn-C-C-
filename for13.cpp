#include <stdio.h>

int main() {
int trau_dung, trau_nam, trau_gia;

	for(trau_dung = 0; trau_dung <= 100; trau_dung++) {
	for(trau_nam = 0; trau_nam <= 100; trau_nam++) {
	trau_gia = 100 - trau_dung - trau_nam;

	if(trau_dung*5 + trau_nam*3 + trau_gia/3.0 == 100) {
		printf("Dung: %d, Nam: %d, Gia: %d\n",
		trau_dung, trau_nam, trau_gia);
			}
		}
	}

return 0;
}