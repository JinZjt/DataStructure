//When writing BFS, we need to use queue to store the node. FIFO.
#include<stdio.h>
#include<stdlib.h>
#define N 6
int visited[N]={0};
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}QueueNode;
typedef struct link{
    QueueNode* front;
    QueueNode* rear;
}LinkedQueue;
typedef struct node{
    int dest;
    int weight;
    struct node* next;
}AdjListNode;
typedef struct{
    AdjListNode* head;
}AdjList;
typedef struct{
    int num;
    AdjList* array;
}graph;

AdjListNode* CreateNode(int dest){
    AdjListNode* p;
    p = (AdjListNode*)malloc(sizeof(AdjListNode));
    p->dest = dest;
    p->next = NULL;
    return p;
}

graph* CreateGraph(int num){
    graph* g;
    int i;
    g = (graph*)malloc(sizeof(graph));
    g->num = num;
    g->array = (AdjList*)malloc(sizeof(AdjList)*num);
    for(i=0;i<num;i++) g->array[i].head = NULL;
    return g;
}

void BuildGraph(graph* g, int sur, int dest){
    AdjListNode* newnode = CreateNode(dest);
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

LinkedQueue* Initialization(){
    LinkedQueue* lq;
    QueueNode* q;
    q = (QueueNode*)malloc(sizeof(QueueNode));
    lq = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    q->next = NULL;
    lq->front = q;
    lq->rear = q;
    return lq;
}

void Enqueue(LinkedQueue* lq, ElemType e){
    QueueNode* p;
    p = (QueueNode*)malloc(sizeof(QueueNode));
    p->data = e;
    p->next = NULL;
    lq->rear->next = p;
    lq->rear = p;
}

void Dequeue(LinkedQueue* lq){
    if(lq->front->next==NULL){
        printf("The queue is empty\n");
        return;
    }
    else{
        QueueNode* p;
        p = (QueueNode*)malloc(sizeof(QueueNode));
        p = lq->front->next;
        PrintVertex(p->data);
        lq->front->next = p->next;
        free(p);
        return;
    }
}

void EnQueue(LinkedQueue* lq, ElemType e){
    Enqueue(lq, e);
    visited[e]=1;
}

void DeQueue(graph* g, LinkedQueue* lq){
    int temp = lq->front->next->data;
    AdjListNode* p;
    p = g->array[temp].head;
    while(p!=NULL){
        if(visited[p->dest]==0)
            EnQueue(lq, p->dest);
        p = p->next;
    }
    Dequeue(lq);
}

int IsEmpty(LinkedQueue* lq){
    if(lq->front->next==NULL)
        return 1;
    else return 0;
}
void BFS(graph* g, LinkedQueue* lq){
    EnQueue(lq, 0);// select the first node
    while(IsEmpty(lq)==0){
        DeQueue(g, lq);
    }
    return;
}
int main(){
    LinkedQueue* q;
    q = Initialization();
    graph* graph;
    graph = CreateGraph(N);
    BuildGraph(graph, 0, 4);
    BuildGraph(graph, 0, 3);
    BuildGraph(graph, 0, 1);
    BuildGraph(graph, 1, 3);
    BuildGraph(graph, 1, 2);
    BuildGraph(graph, 2, 3);
    BuildGraph(graph, 2, 1);
    BuildGraph(graph, 3, 5);
    BuildGraph(graph, 4, 3);
    BuildGraph(graph, 5, 2);
    printf("%d\n", graph->array[0].head->dest);
    BFS(graph, q);
    return 0;
}
