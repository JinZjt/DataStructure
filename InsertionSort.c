#include<stdio.h>
#include<stdlib.h>
#define N 9
void Display(int *a){
    for(int i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
void Swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void InsertionSort(int* a){
    for(int i=1;i<N;i++){
        for(int j=i-1; j>=0;j--){
            if(a[j]>a[j+1]) Swap(&a[j], &a[j+1]);
        }
    }
    return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    InsertionSort(a);
    Display(a);
    return 0;
}