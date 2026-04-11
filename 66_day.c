#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int V, int** adj, int* adjSize, int* visited, int* recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, V, adj, adjSize, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return false;
}

// Function to check cycle
bool isCycle(int V, int** adj, int* adjSize) {
    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, adjSize, visited, recStack))
                return true;
        }
    }

    return false;
}

// Example usage
int main() {
    int V = 4;

    // adjacency list
    int* adjSize = (int*)calloc(V, sizeof(int));
    int** adj = (int**)malloc(V * sizeof(int*));

    for (int i = 0; i < V; i++) {
        adj[i] = (int*)malloc(V * sizeof(int)); // max size
    }

    // Graph:
    // 0 -> 1
    // 1 -> 2
    // 2 -> 3
    // 3 -> 1 (cycle)

    adj[0][adjSize[0]++] = 1;
    adj[1][adjSize[1]++] = 2;
    adj[2][adjSize[2]++] = 3;
    adj[3][adjSize[3]++] = 1;

    if (isCycle(V, adj, adjSize))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
