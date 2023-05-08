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
        printf("\n");
    }
}
void BFSTraversal(struct Node *adj[],int visited[],int start)
{
	int queue[no_vertices],front=-1,rear=-1;
	printf("BFS : ");
	queue[++rear] = start;
	visited[start]=1;
	front++;
	while(front<=rear)
	{
		printf("%d\t",queue[front]);
		struct Node *ptr;
		ptr =  adj[queue[front++]];
		while(ptr != NULL)
		{
			if(visited[ptr->data]!=1)
			{
				queue[++rear] = ptr->data;
				visited[ptr->data] =1;
			}
			ptr = ptr->next;
		}

	}

}
void DFSTraversal(struct Node* adj[],int visited[],int start){
    visited[start] = 1;
    printf("\nDFS Traversal:\n");
	printf("%d\t",start);
	struct Node *temp;
	temp = adj[start];
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
			DFSTraversal(adj,visited,temp->data);
		temp = temp->next;
	}
}    
int main(){
    printf("\nEnter Number of Vertices:\n");
    scanf("%d",&no_vertices);
    struct Node* adj[no_vertices];
    int visited[no_vertices];
    for(int i=0;i<no_vertices;i++){
        adj[i]=NULL;
        visited[i]=0;
    }
    readGraph(adj);
    printGraph(adj);
    printf("\nEnter value of start:\n");
    int start;
    scanf("%d",&start);
    //BFSTraversal(adj,visited,start);
    DFSTraversal(adj,visited,start);
    return 0;
}