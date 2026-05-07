#include <stdio.h>
#include <math.h>
#define m 10
int main() {
    int n,j;
    float a[m];
	float h;
    do {
        printf("Nhap n (n < 10): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 10);
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", &a[i]);
    }
    printf("\nDay vua nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", a[i]);
    }
	for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] < a[j]){
                h = a[i];
                a[i] = a[j];
                a[j] = h;        
            }
        }
    }
	 printf("\nMang da sap xap tu lon den be: ");
    for(int i = 0; i < n; i++){
        printf("%f", a[i]);
	}
	for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                h = a[i];
                a[i] = a[j];
                a[j] = h;        
            }
        }
    }
	printf("\nMang da sap xep tu be den lon: ");
    for(int i = 0; i < n; i++){
        printf("%f", a[i]);
	}
	 for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(fabs(a[i]) < fabs(a[j])){
                h = a[i];
                a[i] = a[j];
                a[j] = h;
            }
        }
    }

    printf("\nMang sau khi sap xep (giam dan theo |x|):\n");
    for(int i = 0; i < n; i++){
        printf("%f", a[i]);
    }
	return 0;
}