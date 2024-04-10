#include <stdio.h>

#define MAX_VERTICES 100

// Structure to represent a stack
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Function to perform topological sort using Depth-First Search (DFS)
void topSortUtil(int v, int adj[MAX_VERTICES][MAX_VERTICES], int V, int vis[], Stack *S) {
    // Mark the current vertex as visited
    vis[v] = 1;
    // Traverse all adjacent vertices
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !vis[i]) {
            // If an adjacent vertex is not visited, recursively call topSortUtil
            topSortUtil(i, adj, V, vis, S);
        }
    }
    // After visiting all adjacent vertices, push the current vertex to the stack
    (S->top)++;
    S->items[S->top] = v;
}

// Function to perform topological sort
void topSort(int adj[MAX_VERTICES][MAX_VERTICES], int V) {
    int vis[MAX_VERTICES] = {0}; // Array to mark visited vertices
    Stack S = {.top = -1}; // Initialize stack for topological sort
    // Perform topological sort for each vertex
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            // If the current vertex is not visited, call topSortUtil
            topSortUtil(i, adj, V, vis, &S);
        }
    }
    // Print the topological order
    printf("Topological sorting of the graph: ");
    while (S.top >= 0) {
        printf("%d ", S.items[S.top--]);
    }
}

int main() {
    // Number of vertices in the graph
    int V = 5;
    // Edges representing the directed graph
    int edges[][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    // Adjacency matrix to represent the graph
    int adj[MAX_VERTICES][MAX_VERTICES] = {0}; 
    // Update the adjacency matrix based on the edges
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
    }
    // Perform topological sort and print the result
    topSort(adj, V);
    return 0;
}
