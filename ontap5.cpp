#include <stdio.h>

int main(){
    int a[] = {1,2,3,4,5};
    int n = 5;

    int *p = a;

    // đưa p tới cuối mảng
    for (int i = 1; i < n; i++){
        p++;
    }

    // in ngược
    for (int i = 0; i < n; i++){
        printf("%d ", *p);
        p--;
    }

    return 0;
}