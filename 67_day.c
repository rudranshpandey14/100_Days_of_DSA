#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack implementation
int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

// DFS function
void dfs(int v, int visited[], int adj[MAX][MAX], int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological sort function
void topoSort(int adj[MAX][MAX], int n) {
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, n);
        }
    }

    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", pop());
    }
}

// Main function
int main() {
    int n, edges;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) where u -> v:\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort(adj, n);

    return 0;
}
