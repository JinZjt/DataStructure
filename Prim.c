#include<stdio.h>
#include<stdlib.h>
#define N 9
#define MAX 999
//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
//The principle can be seen in the above address
//Using HeapSort will be better
int visit[N]={0};
int vertex[N]={0};
int cost[N];
int weight = 0;

typedef struct node{
    int dest;
    int weight;
    struct node* next;
}AdjListNode;

typedef struct{
    AdjListNode* head; //head pointer
}Adjlist;

typedef struct{
    int size;
    Adjlist* array;
}graph;

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
    // insert from the head but remember this is no direcction graph. THe operation is symmetrical.
    AdjListNode* newnode = CreateNode(dest, weight);
    newnode->next = g->array[sur].head;
    g->array[sur].head = newnode;
    newnode = CreateNode(sur, weight);
    newnode->next = g->array[dest].head;
    g->array[dest].head = newnode;
}
void UpdateCostVertex(graph* g, int ptr){
    AdjListNode* p;
    p = g->array[ptr].head;
    while(p!=NULL){
        if(visit[p->dest]==0&&p->weight<cost[p->dest]){
            cost[p->dest] = p->weight;
            vertex[p->dest] = ptr;
        }
        p = p->next;
    }
    return;
}
void Prim(graph*g){
    //pick the 0 as the root
    int ptr = 0;
    visit[ptr] = 1;
    int count = 0;
    count++;
    while(count<N){
        int min = MAX, i=0, MININDEX;
        UpdateCostVertex(g, ptr);
        for(i=0;i<N;i++){
            if(cost[i]<min&&visit[i]==0){
                MININDEX = i;
                min = cost[i];
            }
        }
        weight+=min;
        printf("(%d, %d): %d\n", vertex[MININDEX], MININDEX, min);
        ptr = MININDEX;
        visit[MININDEX]=1;
        count++;
    }
}
int main(){
    graph* graph;
    graph=CreateGraph(N);
    for(int i=0;i<N;i++) cost[i] = MAX;
    BuildGraph(graph, 0,1,10);
    BuildGraph(graph, 0,5,11);
    BuildGraph(graph, 1,2,18);
    BuildGraph(graph, 1,8,12);
    BuildGraph(graph, 1,6,16);
    BuildGraph(graph, 5,6,17);
    BuildGraph(graph, 5,4,26);
    BuildGraph(graph, 2,8,8);
    BuildGraph(graph, 2,3,22);
    BuildGraph(graph, 3,8,21);
    BuildGraph(graph, 3,6,24);
    BuildGraph(graph, 6,7,19);
    BuildGraph(graph, 3,7,16);
    BuildGraph(graph, 4,7,7);
    BuildGraph(graph, 3,4,20);
    Prim(graph);
    printf("%d\n", weight);
    return 0;
}
