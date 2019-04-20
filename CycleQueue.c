#include<stdio.h>
#include<stdlib.h>
// use an array to accomplish the goal of becoming a queue
#define QUEUESIZE 4
typedef int Elemtype;
typedef struct node{
    Elemtype data[QUEUESIZE];
    int front;
    int rear;
}Queue;

//INitialization
void Initialization(Queue* q){
    q->front = 0;
    q-> rear = 0;
    return;
}

//enqueue
void Enqueue(Queue* q, Elemtype e){
    if((q->rear+1)%QUEUESIZE==q->front){
        printf("The queue is full\n");
        return;
    }
    else{
        q->data[q->rear]=e;
        q->rear=(q->rear+1)%QUEUESIZE;
        return;
    }
}
//dequeue
void Dequeue(Queue* q){
    if((q->front==q->rear)){
        printf("The cycle queue is empty\n");
        return;
    }
    else{
        printf("%d\n", q->data[q->front]);
        q->front = (q->front+1)%QUEUESIZE;
        return;
    }
}
//在循环队列里面必须要注意有限域的设定，要注意下标取模
int main(){
    Queue s;
    Initialization(&s);
    Enqueue(&s, 1);
    Enqueue(&s, 2);
    Enqueue(&s, 3);
    Enqueue(&s, 4);
    Dequeue(&s);
    Dequeue(&s);
    Dequeue(&s);
    Dequeue(&s);
    return 0;
}




