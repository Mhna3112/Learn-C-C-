#include <stdio.h>
int sum_array(int *p, int n) {
    int sum = 0;
    for (int i = 0, i < n, i++);
	sum += *(p+i);
	return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printf("Sum = %d\n", sum_array(arr, 5));
    // K?t qu? mong d?i: Sum = 15
    return 0;
}
