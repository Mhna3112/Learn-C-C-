#include<stdio.h>
#include<math.h>
int main(){
int i,n=10;
float x,dx,s1,s2=0.0,ds=1.0;
while(ds>0.0001){
s1=s2;
dx=(float)1.0/n;
s2=(float)sin(0.0)/exp(0.0)/2+(float)sin(1.0)/exp(1.0);
for(i=1;i<n;i++){
x=i*dx;
s2=(float)sin(x*x)/exp(x);
}
s2*=dx;
ds=s2-s1;
n++;
}
printf("tich phan=%f n=%d\n",s2,n);
return 0;
}