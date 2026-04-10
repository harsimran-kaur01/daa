#include <stdio.h>

#define MAX 10

// Warshall's Algorithm for Transitive Closure
void warshall(int graph[MAX][MAX], int n)
{
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                graph[i][j] = graph[i][j] ||
                               (graph[i][k] && graph[k][j]);
            }
        }
    }
}

// Function to print matrix
void printMatrix(int graph[MAX][MAX], int n)
{
    printf("\n=== Transitive Closure Matrix ===\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int graph[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            // safety: convert any non-zero to 1
            if (graph[i][j] != 0)
                graph[i][j] = 1;
        }
    }

    // Run Warshall’s Algorithm
    warshall(graph, n);

    // Print result
    printMatrix(graph, n);

    return 0;
}