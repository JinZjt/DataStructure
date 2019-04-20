#include<stdio.h>
#define MAXSIZE 20
#define DONE 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}sqlist;
//initialize sequential list
Status Initialization(sqlist L){
    int i;
    for(i=0;i<MAXSIZE;i++) L.data[i]=0;
    L.length = 0;
    if(L.length==0) return DONE;
    else return ERROR;
}
//get element function
Status GetElem(sqlist L, int n, ElemType *e){ // get the address of b and then change the value of b
    if(L.length==0||n<1||n>L.length) return ERROR;
    else{
        *e =L.data[n-1];
        return DONE;
    }
}
//add element function
Status AddElem(sqlist* L, int n, ElemType elem){
    if(n>=MAXSIZE||n<1) return ERROR;
    else{
        L->data[n-1] = elem;
        if(L->length<n) L->length = n;
        return DONE;
    } 
}
int main(){
    sqlist List;
    ElemType* a;
    ElemType b;
    Initialization(List);//Actually the initialization is redundant
    AddElem(&List, 1, 1);
    AddElem(&List, 2, 2);
    AddElem(&List, 3, 3);
    AddElem(&List, 4, 4);
    GetElem(List, 2, &b);
    a = &(List.data[2]);
    printf("%d %d \n", List.data[2], List.length);
    printf("%d\n", *a);
    printf("%d\n",b);
    return 0;
}