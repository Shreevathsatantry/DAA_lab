#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Function to perform Breadth-First Search (BFS) traversal
void bfs(int source, int n, int a[MAX_VERTICES][MAX_VERTICES], int s[MAX_VERTICES]) {
    // Initialize variables for front and rear of the queue
    int front = 0, rear = 0;
    // Create a queue for BFS traversal
    int queue[MAX_VERTICES];
    // Enqueue the source vertex
    queue[rear++] = source;
    // Mark the source vertex as visited
    s[source] = 1;

    // Perform BFS traversal
    while (front < rear) {
        // Dequeue a vertex from the queue
        int u = queue[front++];
        // Traverse all adjacent vertices of the dequeued vertex
        for (int v = 0; v < n; v++) {
            // Check if vertex v is adjacent to vertex u and has not been visited yet
            if (s[v] == 0 && a[u][v] == 1) {
                // Mark vertex v as visited and enqueue it
                s[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int v;
    // Input the number of vertices in the graph
    printf("Enter the number of vertices:\n");
    scanf("%d", &v);

    // Input the adjacency matrix representing the graph
    int a[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Initialize an array to mark visited vertices
    int s[MAX_VERTICES] = {0}; 

    // Input the source vertex for BFS traversal
    int source;
    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    // Perform BFS traversal from the specified source vertex
    bfs(source, v, a, s);

    // Output BFS reachability
    printf("BFS Reachability:\n");
    for (int i = 0; i < v; i++) {
        if (s[i] == 1) {
            printf("%d is reachable from %d\n", i, source);
        } else {
            printf("%d is not reachable from %d\n", i, source);
        }
    }

    return 0;
}
