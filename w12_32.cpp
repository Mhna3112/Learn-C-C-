#include <stdio.h>
void reversearray(int *a, int size){
int i, j, tmp;
i=0; j= size -1;
while(i<j){
tmp=*(a+i);
*(a+i)=*(a+j);
*(a+j)= tmp;
i++; j--;
}
}
int main(){
    int arr[] = {4, 9, 3, 4};
    reversearray(arr, 4);
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}