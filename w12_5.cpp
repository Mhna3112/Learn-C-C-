#include <stdio.h>

float* findClosestToAverage(float* arr, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float average = sum / size;

    float* closest = &arr[0];
    float minDiff = float(arr[0] - average);

    for (int i = 1; i < size; i++) {
        float diff = float(arr[i] - average);
        if (diff < minDiff) {
            minDiff = diff;
            closest = &arr[i];
        }
    }
    return closest;
}

int main() {
    float arr[] = {50., 50., 30., 40., 50.,1.,10.};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    float* closestValue = findClosestToAverage(arr, size);
    printf("phan tu gan voi gia tri trung binh nhat la: %.2f\n", *closestValue);
    
    return 0;
}