//1. Pick the first node to push it into the stack 
//2.Pop the node in the stack and print it out
//3.Push all its adjacent nodes into the stack and tag nodes visited 
//4.Repeat the process of popping until the stack is empty.
#include<stdio.h>
#include<stdlib.h>
#define N 6
#define STACKSIZE 10
typedef int ElemType;
typedef struct{
    ElemType array[STACKSIZE];
    int top;
}Stack;
int visited[N]={0};
//Initialization
Stack* Initialization(){
    Stack* s;
    s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}
int IsEmpty(Stack* s){
    if(s->top == -1){
        printf("The stack is empty\n");
        return 1;
    }
    else return 0;
}
void PrintVertex(int i){
    if(i==0) printf("A ");
    else if(i==1) printf("B ");
    else if(i==2) printf("C ");
    else if(i==3) printf("D ");
    else if(i==4) printf("E ");
    else if(i==5) printf("F ");
    else return;
}
int PopStack(Stack* s){
    int i=s->array[s->top];
    if(i<0){
        printf("error\n");
        return -1;
    }
    else{
        PrintVertex(i);
        s->array[s->top]=0;
        s->top--;
    }
    return i;
}
void PushStack(Stack* s, int index, int a[][N]){
    int i = index;
    int ptr=0;
    if(i<0) return;
    for(ptr=N-1;ptr>=0;ptr--){
        if(a[i][ptr]>0&&visited[ptr]==0){
            s->top++;
            s->array[s->top]=ptr;
            visited[ptr]=1;
        }
    }
    return;
}
void DFS(Stack* s, int a[][N]){
    int pushptr=0;
    //select the first node and push it into the stack
    if(visited[0]==0){
        s->top++;
        s->array[s->top] = 0; 
    }
    while(1){
        pushptr = PopStack(s);
        PushStack(s, pushptr, a);
        if(IsEmpty(s)){
            printf("Traversal Finished\n");
            return;
        }
    }
    
}
int main(){
    /*build adjacency matrix*/
    int a[N][N] = {{0, 1, 0, 1, 1, 0},
                   {0, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 1, 0, 0},
                   {0, 0, 1, 0, 0, 0}};//0:A, 1:B, 2:C, 3:D, 4:E, 5:F
    Stack* s;
    s = Initialization();
    //printf("%d\n", s->top);
    DFS(s, a);
    return 0;
}