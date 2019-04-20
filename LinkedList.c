#include<stdio.h>
#include<stdlib.h>
#define DONE 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct node{
    ElemType data;
    struct node* next;
}Node;

//Initialization the header
Node* Initialization(){
    Node* L;
    L = (Node*)malloc(sizeof(Node));
    if(!L) printf("error in the initialization\n");
    else{
        printf("Successful Initialization\n");
        L->data = 0;
        L->next = NULL;
    }
    return L;
}
// add elements into the linked list
Status AddElem(Node* L, ElemType e){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp->data = e;
    temp->next = NULL;
    temp->next = L->next;
    L->next = temp;
    L->data++;
    return DONE;
}
//insert the valueinto the link
void Insertion(Node*L, int n, ElemType e){
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = NULL;
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));
    temp = L;
    int i = 1; // the calculator
    while(i<n){
        if(!temp->next){ // if the next one is NULL
            printf("The index for element being inserted is incorrect\n");
            return;
        }
        else{
            temp = temp->next;
            i++;
        }
    }
    p->next = temp->next;
    temp->next = p;
    L->data++;
} 
//delete a specific element in the linked list
void DeleteOne(Node* L, int n){
    if(n>L->data){
        printf("Deletion cannot be executed");
        return;
    }
    else{
        Node* temp;
        Node* tail;
        tail = (Node*)malloc(sizeof(Node));
        temp = (Node*)malloc(sizeof(Node));
        int i=1;
        temp = L;
        while(i<n){
            temp = temp->next;
            i++;
        }
        tail = temp->next;
        temp->next = tail->next;
        tail->next = NULL;
        free(tail);
        L->data--;
    }
}
//display elements in the linked list
void Display(Node*L){
    Node * p;
    p = (Node*)malloc(sizeof(Node));
    p = L->next;
    printf("the total number of elements in the linked list = %d\n", L->data);
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
//delete the whole list
void DeleteAll(Node* L){
    Node* front;
    Node* tail;
    front = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    front = L;
    tail = front->next;
    while(front){
        front->next = NULL;
        free(front);
        front = tail;
        tail = front->next;
        if(tail==NULL){
            front->next = NULL;
            free(front);
            printf("Clear\n");
            return;
        }
    }
}
int main(){
    Node* head;
    head = Initialization();
    AddElem(head, 1);
    AddElem(head, 2);
    AddElem(head, 3);
    AddElem(head, 4);
    Insertion(head, 4, 8);
    Display(head);
    DeleteOne(head, 1);
    Display(head);
    DeleteAll(head);
    //printf("%d\n",head->next->data);
    return 0;
}

