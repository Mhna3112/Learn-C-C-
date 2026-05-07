#include <stdio.h>

double* maximum(double* a, int size) {
    if (size <= 0) {
        return NULL;
    }
    
    double* maxP = &a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > *maxP) {
            maxP = &a[i];
        }
    }
    return maxP;
}
int main() {
    double arr[] = {1.5, 3.2, 7.8, 2.4};

    double* max = maximum(arr, 4);

    if (max != NULL) {
        printf("Gia tri lon nhat: %lf\n", *max);
        printf("Vi tri: %ld\n", max - arr);
    }

    return 0;
}