#include<stdio.h>
#include<stdlib.h>
#define N 6
#define STACKSIZE 10
int visited[N]={0};
typedef int ElemType;
typedef struct{
    ElemType array[STACKSIZE];
    int top;
}Stack;
typedef struct node{
    int dest;
    int weight;
    struct node* next;
}AdjListNode;

typedef struct{
    AdjListNode* head;//head pointer
}Adjlist;

typedef struct{
    int size;
    Adjlist* array;
}graph;
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
AdjListNode* CreateNode(int vertex, int weight){
    AdjListNode* p;
    p = (AdjListNode*)malloc(sizeof(AdjListNode));
    p->dest = vertex;
    p->weight = weight;
    p->next = NULL;
    return p; 
}
graph* CreateGraph(int num){
    graph* g;
    g = (graph*)malloc(sizeof(graph));
    if(!g){
        printf("Error in initialization\n");
        return NULL;
    }
    else{
        g->size = num;
        g->array = (Adjlist*)malloc(sizeof(Adjlist)*num);
        for(int i=0;i<num;i++)
            g->array[i].head = NULL;
        printf("Sucessful in initialization\n");
        return g;
    }
}
void BuildGraph(graph* g, int sur, int dest, int weight){
    // insert from the head but remember this is a graph with direction. THe operation is asymmetrical.
    AdjListNode* newnode = CreateNode(dest, weight);
    newnode->next = g->array[sur].head;
    g->array[sur].head = newnode;
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
void PushStack(Stack* s, int index, graph* g){
    int i = index;
    AdjListNode* p;
    if(i<0) return;
    p = g->array[i].head;
    while(p!=NULL){
        if(visited[p->dest]==0){
            s->top++;
            s->array[s->top]=p->dest;
            visited[p->dest]=1;
        }
        p = p->next;
    }
    return;
}
void DFS(Stack* s, graph* g){
    int pushptr=0;
    //select the first node and push it into the stack
    if(visited[0]==0){
        s->top++;
        s->array[s->top] = 0; 
    }
    while(1){
        pushptr = PopStack(s);
        PushStack(s, pushptr, g);
        if(IsEmpty(s)){
            printf("Traversal Finished\n");
            return;
        }
    }
    
}
int main(){
    graph* graph;
    graph=CreateGraph(6);
    BuildGraph(graph, 0,1,1);//BuildGraph actually refers to adding edge
    BuildGraph(graph, 0,3,1);
    BuildGraph(graph, 0,4,1);
    BuildGraph(graph, 1,2,1);
    BuildGraph(graph, 1,3,1);
    BuildGraph(graph, 2,1,1);
    BuildGraph(graph, 2,3,1);
    BuildGraph(graph, 3,5,1);
    BuildGraph(graph, 4,3,1);
    BuildGraph(graph, 5,2,1);
    //printf("%d\n", graph->array[0].head->weight);
    Stack* s;
    s = Initialization();
    DFS(s, graph);
    return 0;
}