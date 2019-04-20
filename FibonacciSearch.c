#include<stdio.h>
#include<stdlib.h>
#define N 21
//Use the property of Fibonacci Array. F[k] = F[k-1]+F[k-2]. Use this property to divide the array.
void Merge(int* a, int start, int middle, int end){
    int length1 = middle-start+1;
    int length2 = end - middle;
    int arr1[length1];
    int arr2[length2];
    int i=0, j=0, k=start;
    for(i=0;i<length1;i++) arr1[i] = a[start+i];
    for(j=0;j<length2;j++) arr2[j] = a[middle+1+j];
    i = 0;
    j = 0;
    while(i<length1&&j<length2){
        if(arr1[i]<arr2[j]){
            a[k] = arr1[i];
            i++;
            k++;
        }
        else{
            a[k] = arr2[j];
            j++;
            k++;
        }
    }
    while(i<length1){
        a[k]=arr1[i];
        i++;
        k++;
    }
    while(j<length2){
        a[k] = arr2[j];
        j++;
        k++;
    }
}
void MergeSort(int* a, int start, int end){
    if(start<end){
        int m=(start+end)/2;
        MergeSort(a, start, m);
        MergeSort(a, m+1, end);
        Merge(a, start, m, end);
    }
}
void Display(int *a){
    for(int i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
void Fibonacci(int* F){
    int i=2;
    for(i=2;i<N;i++){
        F[i]=F[i-1]+F[i-2];
    }
    return;
}
void FibonacciSearch(int* a, int* F, int e, int length){
    int k=0, i=length;
    int low=0, high = length-1;
    while(length>F[k])
        k++;
    int upperbound = F[k];
    for(i=length; i<F[k]; i++)
        a[i] = a[length-1];
    while(low<=high){
        int m = low+F[k-1];
        if(a[m]>e){
            high = m-1;
            k = k-1;
        }
        else if(a[m]<e){
            low = m+1;
            k = k-2;
        }
        else{
            if(m<=length-1){
                printf("Found in %d\n", m);
                return;
            }
            else if(m>=length&&m<upperbound){
                printf("Found in %d\n", length-1);
                return;
            }
            }
        }
        if(low>high) printf("Not Found\n");
        return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    int F[N] = {0,1};
    MergeSort(a, 0, 8);
    //Display(a);
    Fibonacci(F);
    FibonacciSearch(a, F, 10, 9);
    return 0;
}
