#include <stdio.h>
void reversearray(int arr[], int size){
int i, j, tmp;
i=0; j= size -1;
while(i<j){
tmp=arr[i];
arr[i]=arr[j];
arr[j]= tmp;
i++; j--;
}
}
int main(){
    int arr[] = {1, 2, 3, 4};
    reversearray(arr, 4);
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}