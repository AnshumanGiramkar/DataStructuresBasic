#include<stdio.h>
#include<stdlib.h>
int no_vertices;
struct Node{
    int data;
    struct Node* next;
};
void readGraph(struct Node* adj[]){
    struct Node* newnode;
    struct Node* last=NULL;
    for(int i=0;i<no_vertices;i++){
        int k,data;
        printf("\nHow many values to a given index %d:\n",i);
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            newnode=(struct Node*)malloc(sizeof(struct Node));
            printf("\nEnter the value of %d neighbour of %d:\n",j,i);
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            if(adj[i]==NULL){
                adj[i]=newnode;
            }
            else{
                last->next=newnode;
            }
            last=newnode;
        }
    }
}
void printGraph(struct Node* adj[]){
    struct Node* temp;
    for(int i=0;i<no_vertices;i++){
        temp=adj[i];
        printf("Adjacent Values to %d are:\n",i);
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    printf("\nEnter Number of Vertices:\n");
    scanf("%d",&no_vertices);
    struct Node* adj[no_vertices];
    for(int i=0;i<no_vertices;i++){
        adj[i]=NULL;
    }
    readGraph(adj);
    printGraph(adj);
}
