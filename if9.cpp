#include <stdio.h>
#include <math.h>
int main() {
    float b,a;
    printf("\nNhap nam sinh: ");
    scanf("%f", &b);
	a = 2026 - b;
    if (a >= 0 && a < 6) {
        printf("la tre em ");
    } 
    else if (a >= 6 && a < 11) {
        printf("hoc sinh cap 1");
    } 
    else if (a >= 11 && a < 15) {
        printf("hoc sinh cap 2");
    } 
    else if (a >= 15 && a < 18) {
        printf("hoc sinh cap 3");
    } 
    else if (a >= 18 && a <= 40) {
        printf("la thanh nien");
    } 
	else if (a >= 40 && a <= 60) {
        printf("la trung nien ");
	}	
	else if (a > 60) {
        printf("la nguoi gia ");
	}
    else {
        printf("nhap sai tuoi ");
    }

    return 0;
}