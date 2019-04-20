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
void SelectionSort(int* a){
    int min;
    for(int i=0;i<N-1;i++){
        min = i;
        for(int j=i+1;j<N;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        Swap(&a[i], &a[min]);
    }
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    SelectionSort(a);
    Display(a);
    return 0;
}