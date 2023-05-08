#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int queue[MAX_SIZE];
int front = -1;
int rear = -1;
void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void bfs(int start, int vertices)
{
    front = 0;
    rear = 0;
    queue[rear] = start;
    visited[start] = true;
    printf("BFS Traversal: ");
    while (front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}
void dfs(int start, int vertices)
{
    visited[start] = true;
    printf("%d ", start);

    for (int i = 0; i < vertices; i++)
    {
        if (graph[start][i] == 1 && !visited[i])
        {
            dfs(i, vertices);
        }
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
        for (int j = 0; j < MAX_SIZE; j++)
        {
            graph[i][j] = 0;
        }
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
    dfs(start, vertices);
    printf("\n");

    return 0;
}