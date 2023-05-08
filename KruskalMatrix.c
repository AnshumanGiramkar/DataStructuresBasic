// C program for Kruskal's Algorithm using Adjacency Matrix
//by
//Anshuman Giramkar
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
struct Edge {
    int src, dest, weight;
};
int find(int parent[], int node) {
    if (parent[node] == node)
        return node;
    return find(parent, parent[node]);
}
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
void sortEdges(struct Edge edges[], int numEdges) {
    int i, j;
    struct Edge temp;
    for (i = 0; i < numEdges - 1; i++) {
        for (j = i + 1; j < numEdges; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}
void kruskalMST(int graph[MAX][MAX], int numVertices) {
    int i, j, k;
    int parent[MAX], rank[MAX];
    struct Edge edges[MAX * MAX];
    int numEdges = 0;
    int minWeight = 0;
    for (i = 0; i < numVertices; i++) {
        for (j = i + 1; j < numVertices; j++) {
            if (graph[i][j] != 0) {
                edges[numEdges].src = i;
                edges[numEdges].dest = j;
                edges[numEdges].weight = graph[i][j];
                numEdges++;
            }
        }
    }
    sortEdges(edges, numEdges);
    for (i = 0; i < numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (i = 0, j = 0; i < numVertices - 1 && j < numEdges; j++) {
        int x = find(parent, edges[j].src);
        int y = find(parent, edges[j].dest);
        if (x != y) {
            minWeight += edges[j].weight;
            printf("%d - %d\n", edges[j].src, edges[j].dest);
            unionSets(parent, rank, x, y);
            i++;
        }
    }
    printf("Minimum Spanning Tree Weight: %d\n", minWeight);
}
int main() {
    int i, j;
    int numVertices, graph[MAX][MAX];
printf("Enter the number of vertices in the graph: ");
scanf("%d", &numVertices);
printf("Enter the adjacency matrix of the graph:\n");
for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
        scanf("%d", &graph[i][j]);
    }
}
printf("Minimum Spanning Tree Edges:\n");
kruskalMST(graph, numVertices);

return 0;
}
