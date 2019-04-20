#include<stdio.h>
#include<stdlib.h>
#define N 9
void Merge(int* a, int start, int middle, int end){
    int length1 = (middle-start)+1;
    int length2 = end - middle;
    int arr1[length1];
    int arr2[length2];
    //copy the elements in the array to two divided array
    int i=0, j=0, k=0;
    for(i=0;i<length1;i++) arr1[i] = a[start+i];
    for(j=0;j<length2;j++) arr2[j] = a[middle+1+j];
    i = 0;
    j = 0;
    k = start; //addingfrom the start of each merge
    while(i<length1&&j<length2){
        if(arr1[i]<=arr2[j]){
            a[k] = arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j]){
            a[k] = arr2[j];
            j++;
        }
        k++;
    }
    //copy the remaining elements in the array 1 to the final array
    while(i<length1){
        a[k] = arr1[i];
        i++;
        k++;
    }
    //copy the remaining elements in the array 2 to the final array
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
    return;
}
void Display(int *a){
    for(int i=0;i<N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    MergeSort(a, 0, N-1);
    Display(a);
    return 0;
}