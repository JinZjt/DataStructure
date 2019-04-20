#include<stdio.h>
#include<stdlib.h>
#define N 9
//shell sort是在insertion sort的基础上的增强版，insertion sort只能相邻的元素进行交换，在shell sort中引入了gap difference的概念, swap(a[i+gap], a[i])
//Divide the array into several group.
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

void ShellSort(int* a){
    int increment = N;// Increment is the gap difference. How to determine it is still under math research.
    while(increment>1){
        increment = increment/3+1;
        for(int i=increment; i<N;i++){
            for(int j=i-increment; j>=0&&a[j]>a[j+increment];j-=increment)
                Swap(&a[j], &a[j+increment]);
        }
    }
    return;
}

int main(){
    int a[N]={9,8,7,6,5,4,3,2,1};
    ShellSort(a);
    Display(a);
    return 0;
}