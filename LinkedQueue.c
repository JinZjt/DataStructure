#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node* next;
}QueueNode;

typedef struct link{
    QueueNode* front;
    QueueNode* rear;
}LinkedQueue;
//In the process of initialization, we need to have a head node first.
LinkedQueue* Initialization(QueueNode* q){
    LinkedQueue* lq;
    lq = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    q = (QueueNode*)malloc(sizeof(QueueNode));
    if(!q){
        printf("Error in initialization");
        return NULL;
    }
    else{
        q->next = NULL;
        lq->front = q;
        lq->rear = q;
        return lq;
    }
}
//enqueue
void Enqueue(LinkedQueue* q, ElemType e){
    QueueNode* p;
    p = (QueueNode*)malloc(sizeof(QueueNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return;
}
//dequeue
void Dequeue(LinkedQueue* q){
    if(q->front->next==NULL){
        printf("The queue is already empty\n");
        q->rear = q->front;
        return;
    }
    else{
        QueueNode* p;
        p = (QueueNode*)malloc(sizeof(QueueNode));
        p = q->front->next;
        printf("%d\n", p->data);
        q->front->next = p->next;
        free(p);
        return;
    }
}
int main(){
    QueueNode* q;
    LinkedQueue* lq;
    lq = Initialization(q);
    Enqueue(lq, 1);
    Enqueue(lq, 2);
    Enqueue(lq, 3);
    Dequeue(lq);
    Dequeue(lq);
    Dequeue(lq);
    Dequeue(lq);
    return 0;
}