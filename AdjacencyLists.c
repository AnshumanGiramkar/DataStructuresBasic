#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100
struct Node
{
    int data;
    struct Node *next;
};

struct Node *adjList[MAX_SIZE];
bool visited[MAX_SIZE];
void addEdge(int u, int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}
void bfs(int start, int vertices)
{
    int queue[MAX_SIZE];
    int front = 0;
    int rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    printf("BFS Traversal: ");
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        struct Node *temp = adjList[node];
        while (temp)
        {
            int adjNode = temp->data;
            if (!visited[adjNode])
            {
                queue[rear++] = adjNode;
                visited[adjNode] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}
void dfs(int start)
{
    visited[start] = true;
    printf("%d ", start);

    struct Node *temp = adjList[start];
    while (temp)
    {
        int adjNode = temp->data;
        if (!visited[adjNode])
        {
            dfs(adjNode);
        }
        temp = temp->next;
    }
}

int main()
{
    int vertices, edges;
    int u, v;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        adjList[i] = NULL;
        visited[i] = false;
    }
    printf("Enter the edges in the format 'u v' (u and v are vertices connected by an edge):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    int start;
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &start);
    bfs(start, vertices);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        visited[i] = false;
    }
    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");

    return 0;
}
