#include<stdio.h>
#include<stdlib.h>
typedef int EdgeType;
typedef int VertexType;
#define MAXSIZE 100
#define INFINITY 66535
int main(){
    int size, vertex, weight, i=0, j=0;
    printf("The size of the matrix is \n");
    scanf("%d", &size);
    int matrix[size][size], num[size];
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            matrix[i][j]=INFINITY;
        }
    }
    for(i=0;i<size;i++){
        printf("The current vertex is %d, please input the number of its adjacent vertices\n", i);
        scanf("%d", &num[i]);
        for(j=0;j<num[i];j++){
            printf("The current vertex is %d, please input the adjacent edge and its weight\n",i);
            scanf("%d %d", &vertex, &weight);
            matrix[i][vertex] = weight;
        }
    }
    printf("%d\n", matrix[0][1]);
    return 0;
}