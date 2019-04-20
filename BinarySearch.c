#include<stdio.h>
#include<stdlib.h>
#define N 9
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
void BinarySearch(int* a, int e, int low, int high){
    //int middle = (low+high)/2;
    /*The method above is binary search. The method below is insertion search*/
    int middle = low+(e-a[low])/(a[high]-a[low])*(high-low);
    if(a[middle]==e){
        printf("The element has been found in %d position\n", middle);
        return;
    }
    else if(low>=high){
        printf("Not Found\n");
        return;
    }
    else if(a[middle]>e){
        BinarySearch(a, e, low, middle-1);
    }
    else if(a[middle]<e){
        BinarySearch(a, e, middle+1, high);
    }
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    MergeSort(a, 0, N-1);
    Display(a);
    BinarySearch(a, 1, 0, N-1);
    return 0;
}
