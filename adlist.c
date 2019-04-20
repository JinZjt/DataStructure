#include<stdio.h>
#include<stdlib.h>
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
int main(){
    graph* graph;
    graph=CreateGraph(5);
    BuildGraph(graph, 0,1,9);
    BuildGraph(graph, 0,2,2);
    BuildGraph(graph, 0,4,6);
    BuildGraph(graph, 1,2,3);
    BuildGraph(graph, 2,3,3);
    BuildGraph(graph, 3,4,1);
    printf("%d\n", graph->array[0].head->weight);
    return 0;
}
