#include<stdio.h>
#include<stdlib.h>
#define N 6
int visited[N] = {0};
void PrintVertex(int i){
    if(i==0) printf("A ");
    else if(i==1) printf("B ");
    else if(i==2) printf("C ");
    else if(i==3) printf("D ");
    else if(i==4) printf("E ");
    else if(i==5) printf("F ");
    else return;
}
void DFS(int a[][N], int i){
    int j=0;
    PrintVertex(i);
    visited[i]=1;
    for(j=0;j<N;j++){
        if(a[i][j]>0&&visited[j]==0)
            DFS(a, j);
    }
    return;
}
int main(){
    /*build adjacency matrix*/
    int a[N][N] = {{0, 1, 0, 1, 1, 0},
                   {0, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1},
                   {0, 0, 0, 1, 0, 0},
                   {0, 0, 1, 0, 0, 0}};//0:A, 1:B, 2:C, 3:D, 4:E, 5:F
    DFS(a, 0);
    return 0;
}