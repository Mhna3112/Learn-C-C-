#include<stdio.h>
int main(){
int i,n,gt=1;
// n!=1x2x3...xn;
n=5;
for(i=1;i<=n;i++){
gt=gt*i;
}
printf("%d!=%d\n",n,gt);
return 0;
}