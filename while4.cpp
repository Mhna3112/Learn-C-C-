#include <stdio.h>
#include <math.h>
float tinh_pi(float epsilon, int *sohang){
    float pi_over_4 = 0.0f;
    float term;
    int i = 0;
    do {
        term = 1.0f / (2 * i + 1);
        if(i % 2 != 0) term = -term;

        pi_over_4 += term;
        i++;
    } while(fabs(term) >= epsilon);
    *sohang = i;
    return pi_over_4 * 4;
}
int main(){
    float epsilon;
    printf("Nhap epsilon (<1): ");
    scanf("%f", &epsilon);
    if(epsilon >= 1 || epsilon <= 0){
        printf("Epsilon khong hop le!\n");
        return 0;
    }
    int n;
    float pi = tinh_pi(epsilon, &n);
    printf("Gia tri xap xi cua pi = %.6f\n", pi);
    printf("So hang da tinh = %d\n", n);
    return 0;
}