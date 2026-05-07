#include <stdio.h>
float tinh_e(float espilon){
    int n = 1;
    int gt = 1;
    float e = 1.0, de = 1.0;
    while(de > espilon){
        gt *= n;        
        de = 1.0 / gt; 
        e += de;
        n++;
    }
    return e;
}
int main(){
    float espilon;
    printf("nhap espilon: ");
    scanf("%f", &espilon);
    float kq = tinh_e(espilon);
    printf("e = %f\n", kq);
    return 0;
}