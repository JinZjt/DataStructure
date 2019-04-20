#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node *next;
}StackNode;

typedef struct link{
    StackNode* top; // the top pointer
    int count;
}LinkedStack;

//Initialization
LinkedStack* Initialization(){
    LinkedStack* L;
    L = (LinkedStack*)malloc(sizeof(LinkedStack));
    if(!L){
        printf("Error in initialization\n");
        return NULL;
    }
    else{
        printf("Successful Initialization\n");
        L->top=NULL;
        L->count = 0;
        return L;
    }
}
//push the stack
void Push(LinkedStack* L, ElemType e){
    StackNode* p;
    p = (StackNode*)malloc(sizeof(StackNode));
    p->data = e;
    p->next = L->top;
    L->top = p;
    L->count++;
    return;
}
//pop the stack
void Pop(LinkedStack *L){
    StackNode* p;
    p = (StackNode*)malloc(sizeof(StackNode));
    if(L->top==NULL){
        printf("The linked stack is already empty\n");
        return;
    }
    else{
        printf("%d\n", L->top->data);
        p = L->top;
        L->top = p->next;
        free(p);
        L->count--; 
        return;
    }
}
int main(){
    LinkedStack* LS;
    LS = Initialization();
    printf("%d\n", LS->count);
    Push(LS, 1);
    Push(LS, 2);
    Push(LS, 3);
    Push(LS, 4);
    Pop(LS);
    Pop(LS);
    printf("%d\n", LS->count);
    return 0;
}