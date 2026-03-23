#include<stdio.h>
int main(){
int a,k,m,n;
printf("Nhap a=");scanf("%d",&a);
k=a/100;
m=(a-100*k)/10;
n=a-100*k-10*m;
printf("k=%d m=%d n=%d\n",k,m,n);
switch(k){
case(1):printf("mot tram");break;
case(2):printf("hai tram");break;
case(3):printf("ba tram");break;
}
switch(m){
case(1):printf("muoi");break;
case(2):printf("hai muoi");break;
case(3):printf("ba muoi");break;
}
switch(n){
case(1):printf("mot");break;
case(2):printf("hai");break;
case(3):printf("ba");break;
}
return 0;
}