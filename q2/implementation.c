#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Graph structure
typedef struct Graph {
    int V;
    Node* adj[MAX];
    int indegree[MAX];
} Graph;

// Create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    for (int i = 0; i < V; i++) {
        graph->adj[i] = NULL;
        graph->indegree[i] = 0;
    }

    return graph;
}

// Add edge u -> v (dependency)
void addDependency(Graph* graph, int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    graph->indegree[v]++;
}

// Queue implementation
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    return q->items[q->front++];
}

// Topological sort with levels
void topologicalSortWithLevels(Graph* graph) {
    Queue q;
    initQueue(&q);

    // Step 1: Push all nodes with indegree 0
    for (int i = 0; i < graph->V; i++) {
        if (graph->indegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    int step = 1;

    printf("Topological Order (Levels):\n");

    // Step 2: Process level by level
    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        printf("Step %d: ", step++);

        for (int i = 0; i < size; i++) {
            int node = dequeue(&q);
            printf("%d ", node);

            Node* temp = graph->adj[node];
            while (temp != NULL) {
                graph->indegree[temp->vertex]--;

                if (graph->indegree[temp->vertex] == 0) {
                    enqueue(&q, temp->vertex);
                }

                temp = temp->next;
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Number of processes
    int V = 5;

    Graph* graph = createGraph(V);

    // Dependencies
    addDependency(graph, 0, 1); // Assembly → Painting
    addDependency(graph, 0, 2); // Assembly → Wiring
    addDependency(graph, 1, 3); // Painting → Testing
    addDependency(graph, 2, 3); // Wiring → Testing
    addDependency(graph, 3, 4); // Testing → Packaging

    topologicalSortWithLevels(graph);

    return 0;
}