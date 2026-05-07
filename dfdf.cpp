//#include <stdio.h>
//#include <math.h>
//int main() {
//    int a, b, c;
//    float p;
//    float s;
//    printf("nhap ba canh a,b,c: \n");
//    scanf("%d%d%d", &a, &b, &c);
//    if (a +b>c  && b + c>a && c + a > b) {
//	p = ( a + b + c ) /2 ;
//	s = sqrt(p*(p-a)*(p-b)*(p-c));
//	printf ("dien tich tam giac la %.2f", s);
//}
//	else {
//	printf ("day khong phai la mot tam giac");
//}
//	return 0;
//}
#include <stdio.h>
#include <math.h>
float tvh(float P[], float Q[], float R[]){
return 0.5 * fabs(P[0] * (Q[1] - R[1]) + Q[0] * (R[1] - P[1]) + R[0] * (P[1] - Q[1]));
}
int main() {
    float A[2], B[2], C[2];
    printf("Nhap toa do A (x y): ");
    scanf("%f %f", &A[0], &A[1]);
    printf("Nhap toa do B (x y): ");
    scanf("%f %f", &B[0], &B[1]);
    printf("Nhap toa do C (x y): ");
    scanf("%f %f", &C[0], &C[1]);
    float t1 = tvh(A,B,C),
          t2 = tvh(B,C,A),
          t3 = tvh(C,A,B);
    if (t1 == 0 || t2 == 0 || t3 == 0 ){
        printf("day la tam giac vuong");
    } else if (t1 == t2 || t2 == t3 || t1 == t3) {
        printf("day la tam giac can ");
        } else if (t1 ==t2 && t2== t3) {
            printf("day la tam giac deu");
        } else if (t1*t2*t3 <0 ){
            printf("day la tam giac tu");
        } else {
            printf("day la tam giac thuong");
        }
 return 0; 
}
