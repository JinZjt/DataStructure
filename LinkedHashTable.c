#include<stdio.h>
#include<stdlib.h>
#define N 11
typedef struct node{
    int data;
    struct node* next;
}HashNode;
typedef struct{
    HashNode* head;
}HashList;
typedef struct{
    HashList* table;
    int size;
}HashTable;

HashTable* CreateHashTable(int num){
    HashTable* t;
    t = (HashTable*)malloc(sizeof(HashTable));
    t->size = num;
    t->table = (HashList*)malloc(sizeof(HashList)*num);
    for(int i=0;i<num;i++) t->table[i].head = NULL;
    return t;
}

int HashFunc(int a){
    return a%N;
}

void Insert(int input, HashTable* t){
    int index = HashFunc(input);
    HashNode* p;
    p = (HashNode*)malloc(sizeof(HashNode));
    p->data = input;
    p->next = NULL;
    p->next = t->table[index].head;
    t->table[index].head = p;
    printf("The data is stored in %d position\n", index);
    return;
}

int main(){
    HashTable* H;
    H = CreateHashTable(N);
    Insert(37, H);
    Insert(48, H);
    printf("%d %d\n", H->table[4].head->data, H->table[4].head->next->data);
    return 0;
}