#include <stdio.h>
#include <math.h>

int main() {
double pi = 0;
int i, n;

printf("Nhap n: ");
scanf("%d", &n);

for(i = 0; i < n; i++) {
pi += pow(-1, i) * (1.0 / (2*i + 1));
}

pi *= 4;

printf("PI = %lf", pi);
return 0;
}