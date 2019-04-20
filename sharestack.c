#include<stdio.h>
#include<stdlib.h>
#define MAXSIZZE 6
typedef int ElemType;
typedef struct node{
    ElemType data[MAXSIZZE];
    int top1;
    int top2; 
}Stack;

void Initialization(Stack *s){
    s->top1 = -1;
    s->top2 = MAXSIZZE;
}

void Push(Stack *s, ElemType e, int stacknumber){//stack number is 1 or 2
    if(s->top1+1==s->top2){
        printf("The stack is already full\n");
        return;
    }
    else if(stacknumber==1){
        s->top1++;
        s->data[s->top1]=e;
        return;
    }
    else if(stacknumber==2){
        s->top2--;
        s->data[s->top2] = e;
        return;
    }
    return;
}

void Pop(Stack *s, ElemType *e, int stacknumber){
    if(stacknumber==1&&s->top1==-1){
        printf("The 1st stack is already empty\n");
        return;
    }
    else if(stacknumber==2&&s->top2==MAXSIZZE){
        printf("The2nd stack is already empty\n");
        return;
    }
    else if(stacknumber==1&&s->top1!=-1){
        *e = s->data[s->top1];
        s->top1--;
        return;
    }
    else if(stacknumber==2&&s->top2!=MAXSIZZE){
        *e = s->data[s->top2];
        s->top2++;
        return;
    }
    return;
}
int main(){
    Stack L;
    int a;
    Initialization(&L);
    Push(&L, 1, 1);
    Push(&L, 2, 1);
    Push(&L, 3, 1);
    Push(&L, 4, 2);
    Push(&L, 5, 2);
    Push(&L, 6, 1);
    Push(&L, 6, 1);//to test the code and see whether it can be regarded as full
    Pop(&L, &a, 1);
    printf("%d\n", a);
    Pop(&L, &a, 1);
    printf("%d\n", a);
    Pop(&L, &a, 1);
    printf("%d\n", a);
    Pop(&L, &a, 1);
    printf("%d\n", a);
    Pop(&L, &a, 2);
    printf("%d\n", a);
    Pop(&L, &a, 2);
    printf("%d\n", a);
    return 0;
}