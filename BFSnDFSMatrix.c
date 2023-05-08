#include<stdio.h>
#include<stdlib.h>
int adj[5][5]={{0,1,0,0,1},{1,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{1,1,0,1,0}};


void BFSTraversal(int start){
    int queue[5];
    int visitedBFS[5]={0,0,0,0,0};
    int front=-1,rear=-1;
    queue[++rear]=start;
    ++front;
    visitedBFS[front]=1;
    while(rear>=front){
        start=queue[front++];
        printf("%d->",start);
        for(int i=0; i<5; i++){
            if(adj[start][i] && !visitedBFS[i]){
                queue[++rear]=i;
                visitedBFS[i]=1;
            }
        }
    }
}

void DFSTraversal(int start){
    int stack[5];
    int visitedDFS[5]={0,0,0,0,0};
    int top=-1;
    stack[++top]=start;
    visitedDFS[top]=1;
    while(top!=-1){
        start=stack[top];
        top--;
        printf("%d->",start);
        for(int i=0; i<5; i++){
            if(adj[start][i] && !visitedDFS[i]){
                stack[++top]=i;
                visitedDFS[i]=1;
            }
        }
    }
}

int main(){
    printf("\nBFS Traversal\n");
    BFSTraversal(0);
    printf("\nDFS Traversal\n");
    DFSTraversal(0);
}
