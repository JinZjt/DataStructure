#include<stdio.h>
#include<stdlib.h>
#define N 9
int sorted = 0;
void Swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Bubble(int *a){//Move the relatively small element upward from the bottom, but for nearly sorted array, it lacks efficiency
    for(int i=0;i<N;i++){
        for(int j=N-1;j>i;j--){
            if(a[j]<a[j-1]) Swap(&a[j], &a[j-1]);
        }
    }
    return;
}
void BubbleAdvanced(int *a){// Add one flag to better solve the nearly sorted array.
    while(sorted==0){
        sorted = 1;
        for(int i=0;i<N-1;i++){
            if(a[i+1]<a[i]){
                Swap(&a[i+1], &a[i]);
                sorted = 0;}
        }
    }
}
void Display(int *a){
    for(int i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    Bubble(a);
    Display(a);
    BubbleAdvanced(a);
    Display(a);
    return 0;
}