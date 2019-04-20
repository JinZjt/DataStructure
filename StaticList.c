#include<stdio.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType data;
    int cur; //cursor pointed to other index
}component, staticlist[MAXSIZE];
//The cursor of the first index is used to locate the unused index
//The cursor of the last index is used to locate the used index
int sum=0;
//Initialization
Status Initlist(staticlist space){ //结构体构成的数组可以直接传参，并进行修改很神奇吧，其他的都需要指针操作。
    int i;
    for(i=0;i<MAXSIZE-1;i++){
        space[i].cur = i+1;
    }
    space[MAXSIZE-1].cur = 0;
    for(i=0;i<MAXSIZE;i++) space[i].data = -1;
    return DONE;
}
//add node into the static list from the 1st index
Status AddNode(staticlist space, ElemType e){
    int i;
    i = space[0].cur;
    space[i].data = e;
    space[0].cur = i+1;
    space[MAXSIZE-1].cur = 1;
    sum++;
}
//insert new value into the list
Status Insert(staticlist space, int n, ElemType e){
    AddNode(space, e);
    sum--;
    int i=MAXSIZE-1;
    int j,current;
    for(j=0;j<n-1;j++){
        i = space[i].cur;
    }
    current = space[0].cur-1;
    space[current].cur = space[i].cur;
    space[i].cur = current;
    if(space[current].cur == n){
        printf("Successful insertion\n");
        sum++;
        return DONE;
    }
    else return ERROR;
}
//delete the value in a exact position
Status Delete(staticlist space, int n){
    int i=MAXSIZE-1;
    int j, delete_one;
    for(j=0;j<n-1;j++) i = space[i].cur;
    delete_one = space[i].cur;
    space[i].cur = space[delete_one].cur;
    space[delete_one].cur = space[0].cur;
    space[0].cur = delete_one;
    sum--;
    return DONE;
}
//display values in the list
void Display(staticlist space){
    int i = MAXSIZE-1;
    int end = sum;
    int count=0;
    printf("sum=%d\n", sum);
    while(1){
        i = space[i].cur;
        if(count==end) {
            printf("\n");
            return;
        }
        else {
            printf("%d ", space[i].data);
            count++;
        }
    }    
}
int main(){
    staticlist L;
    Initlist(L);
    AddNode(L, 1);
    AddNode(L, 2);
    AddNode(L, 3);
    AddNode(L, 4);
    AddNode(L, 5);
    Insert(L,3,6);
    Display(L);
    Delete(L,3);
    //printf("%d\n", L[MAXSIZE-1].cur);
    Display(L);
    AddNode(L,6);
    Insert(L,4,7);
    Display(L);
    return 0;
}
