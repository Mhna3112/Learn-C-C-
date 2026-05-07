#include <STDIO.H>
int sum(int *a, int n){
    int sum=0;
    int *p=a;
    for (int i=0; i<n; i++){
        sum+=*p;
    }
    return sum;
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
    int tong=sum(a, n);
    printf("Tong cac phan tu: %d\n", tong);
    return 0;
}