#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Graph structure
struct Graph {
    struct Node* head[MAX];
};

// Create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->head[u];
    graph->head[u] = newNode;
}

// Min Heap structure
struct MinHeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

// Swap nodes
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Extract min
struct MinHeapNode extractMin(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Insert into heap
void insertHeap(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[(i - 1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// Dijkstra Algorithm
void dijkstra(struct Graph* graph, int V, int src) {
    int dist[MAX];
    struct MinHeap heap;
    heap.size = 0;

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    insertHeap(&heap, src, 0);

    while (heap.size > 0) {
        struct MinHeapNode minNode = extractMin(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->head[u];
        while (temp != NULL) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Main function
int main() {
    int V = 5;
    struct Graph graph;

    for (int i = 0; i < V; i++)
        graph.head[i] = NULL;

    addEdge(&graph, 0, 1, 10);
    addEdge(&graph, 0, 4, 5);
    addEdge(&graph, 1, 2, 1);
    addEdge(&graph, 1, 4, 2);
    addEdge(&graph, 2, 3, 4);
    addEdge(&graph, 3, 2, 6);
    addEdge(&graph, 4, 1, 3);
    addEdge(&graph, 4, 2, 9);
    addEdge(&graph, 4, 3, 2);

    dijkstra(&graph, V, 0);

    return 0;
}
