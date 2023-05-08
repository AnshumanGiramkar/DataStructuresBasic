// C program for Kruskal's Algorithm using Adjacency List
//by
//Anshuman Giramkar
#include<stdio.h>
#include<stdlib.h>
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge* edge;
};
struct Subset {
    int parent;
    int rank;
};
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
int compare(const void* a, const void* b) {
    struct Edge* a_edge = (struct Edge*) a;
    struct Edge* b_edge = (struct Edge*) b;
    return a_edge->weight > b_edge->weight;
}
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0, i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    struct Subset* subsets = (struct Subset*) malloc(V * sizeof(struct Subset));
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
    return;
}

int main() {
    int V, E, src, dest, weight;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    printf("Enter the edges in the graph (source, destination, weight):\n");
for (int i = 0; i < E; i++) {
scanf("%d %d %d", &src, &dest, &weight);
graph->edge[i].src = src;
graph->edge[i].dest = dest;
graph->edge[i].weight = weight;
}
KruskalMST(graph);
return 0;
}
