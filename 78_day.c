#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int i = 0; i < n; i++) {
        if (mstSet[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];
    int mstSet[MAX];
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0; // Start from node 0

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // Convert to 0-based indexing
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
