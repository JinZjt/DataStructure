#include<stdio.h>
#include<stdlib.h>
#define N 11

int HashFunc(int a){
    return a%N;
}

void Initialization(int* a, int size){
    for(int i=0;i<size;i++) a[i]=-1;
    return;
}
void PrintTable(int* a, int n){
    for(int i=0;i<n;i++) printf("%d ", a[i]);
    printf("\n");
    return;
}
void Insert(int* a, int input){
    int index = HashFunc(input);
    int i=index, count=0;
    if(a[i]==-1){
        a[i] = input;
        return;
    }
    while(a[i]!=-1){
        i=(i+1)%N;
        count++;
        if(count>=N){
            printf("The hash table is full\n");
            return;
        }
    }
    a[i] = input;
    return;
}
void Search(int e, int* a){
    int index = HashFunc(e);
    int i = index, count=0;
    if(a[i]==e){
        printf("The data is found in %d position\n", i);
        return;
    }
    while(a[i]!=e){
        i = (i+1)%N;
        count++;
        if(count>=N){
            printf("Not found\n");
            return;
        }
    }
    printf("THe  data is in %d position\n", i);
    return;
}
int main(){
    int a[N];
    Initialization(a, N);
    //PrintTable(a, N);
    Insert(a, 37);
    Insert(a, 48);
    Insert(a, 1);
    Search(37, a);
    Search(48, a);
    Search(96,a);
    return 0;
}






