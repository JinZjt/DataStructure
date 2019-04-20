#include<stdio.h>
#include<stdlib.h>
#define N 9
typedef struct{
    int array[N+1];
    int end;
}Heap;
Heap* Initialization(){
    Heap* h;
    h = (Heap*)malloc(sizeof(Heap));
    if(!h){
        printf("Error\n");
        return NULL;
    }
    else{
        h->end = 0;
        return h;
    }
}
void Swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Display(int *a){
    for(int i=1;i<=N;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
void BuildHeap(int* a, Heap* h){
    for(int i=0;i<N;i++){
        h->array[i+1] = a[i];
        h->end++;
        int parent=(h->end)/2;
        while(parent>0){
            if(h->array[parent]<h->array[h->end]) Swap(&h->array[parent], &h->array[h->end]);
            parent = parent/2;
        }
    }
}
int GetMaxIndex(Heap* h, int a, int b){
    if(h->array[a]>=h->array[b]) return a;
    else return b;
}
void RemoveMax(Heap* h){
    h->array[0]=h->array[1];
    Swap(&h->array[1], &h->array[h->end]);
    h->end--;
    printf("%d ", h->array[0]);
    int pos = 1;
    int object;
    while(1){
        if(2*pos>h->end) return;
        else if(2*pos+1>h->end){
            object = 2*pos;
            if(h->array[object]>h->array[pos]) {
                Swap(&h->array[pos], &h->array[object]);
                pos= object; 
            }
            return;
        }
        else{
            object = GetMaxIndex(h, 2*pos, 2*pos+1);
            if(h->array[object]>h->array[pos]){
                Swap(&h->array[pos], &h->array[object]);
                pos = object;
            }
        }
    }
}
void HeapSort(Heap* h){
    for(int i=1;i<=N;i++){
        RemoveMax(h);
    }
    printf("\n");
    return;
}
int main(){
    int a[N]={9,1,5,8,3,7,6,4,2};
    Heap* h;
    h = Initialization();
    BuildHeap(a, h);
    Display(h->array);
    HeapSort(h);
    return 0;
}