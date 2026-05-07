#include <stdio.h>

int countEven(int *arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }

    return count;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 88, 86};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = countEven(arr, size);
    printf("So luong so chan: %d\n", result);

    return 0;
}