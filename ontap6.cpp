#include <stdio.h>
vodi max(int *a, int n){
    int max=*a;
    for (int i=1; i<n; i++){
        if (*(a+i)>max){
            max=*(a+i);
        }
    }
    return max;
}
int main(){
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n; i++){
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &a[i]);
    }
    int max_value=max(a, n);
    printf("Gia tri lon nhat: %d\n", max_value);
    return 0;
}