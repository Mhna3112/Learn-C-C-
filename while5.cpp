#include <stdio.h>
#include <math.h>
float tinh(float x){
	float term = x;
	float sum = 0.0f;
	float eps = 0.0001f;
    int n = 0;
	 while (fabsf(term) >= eps) {
        sum += term;
        n++;
        term *= -x * x / ((2.0f * n) * (2.0f * n + 1.0f));
    }
	return sum;
}
int main() {
	float x;
    printf("Nhap x: ");
    scanf("%f", &x);
	float kq = tinh(x);
    printf("Sin(%.6f) xap xi = %.6f\n", x, kq);
    return 0;
}
