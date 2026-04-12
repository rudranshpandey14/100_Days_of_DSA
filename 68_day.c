#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int graph[MAX][MAX], int V) {
    int indegree[MAX] = {0};
    int i, j;

    // Step 1: Calculate in-degree
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Enqueue vertices with indegree 0
    for (i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (j = 0; j < V; j++) {
            if (graph[u][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
        count++;
    }

    // Step 4: Check for cycle
    if (count != V) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int V, i, j;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(graph, V);

    return 0;
}
