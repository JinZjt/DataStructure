#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct node{
    ElemType data[MAXSIZE];
    int top;
}Stack;

void Initlist(Stack *s){
    s->top = -1;
}

void Push(Stack *s, ElemType e){
    if(s->top==MAXSIZE-1){
        printf("The stack is full\n");
        return;
    }
    else{
        s->top++;
        s->data[s->top] = e;
        return;
    }
}

void Pop(Stack *s, ElemType *e){
    if(s->top==-1){
        printf("The stack is empty\n");
        return;
    }
    else{
        *e = s->data[s->top];
        s->top--;
        return;
    }
}

int main(){
    Stack s;
    int a;
    Initlist(&s);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 3);
    Push(&s, 4);
    Pop(&s, &a);
    printf("%d\n", a);
    Pop(&s, &a);
    printf("%d\n", a);
    Pop(&s, &a);
    printf("%d\n", a);
    Pop(&s, &a);
    printf("%d\n", a);
    Pop(&s, &a);
    return 0 ;
}