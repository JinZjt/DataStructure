#include<stdio.h>
#include<stdlib.h>
#define N 9
void Swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Display(int *a){
    for(int i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
int Partition(int* a, int start, int end){
    int low = start;
    int high = end;
    int pivot = a[end];
    while(1){
    while(low<end&&a[low]<=pivot) low++; //low pointer should not reach the boung of the array, otherwise it may go beyond the boundary
    while(high>start&&a[high]>=pivot) high--;// The same with high pointer
    if(low>=high){
        Swap(&a[low], &a[end]);
        return low;
    }
    Swap(&a[low], &a[high]);
    }
}
void QuickSort(int* a, int start, int end){
    if(start<end){
        int pi;
        pi = Partition(a, start, end);
        QuickSort(a, start, pi-1);
        QuickSort(a, pi+1, end);
    }
    return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    QuickSort(a, 0, N-1);
    Display(a);
    return 0;
}