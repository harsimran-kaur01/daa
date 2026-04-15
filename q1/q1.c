#include <stdio.h>
#include <limits.h>

#define N 4

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Generate permutations
void permute(int arr[], int l, int r, int graph[N][N], int *min_cost) {
    if (l == r) {
        int cost = 0;
        int k = 0; // start from node 0

        for (int i = 0; i < r; i++) {
            cost += graph[k][arr[i]];
            k = arr[i];
        }

        cost += graph[k][0]; // return to start

        *min_cost = min(*min_cost, cost);
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        permute(arr, l + 1, r, graph, min_cost);
        swap(&arr[l], &arr[i]);
    }
}

int tsp(int graph[N][N]) {
    int vertices[N-1];

    for (int i = 1; i < N; i++)
        vertices[i-1] = i;

    int min_cost = INT_MAX;

    permute(vertices, 0, N-2, graph, &min_cost);

    return min_cost;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    printf("Minimum travelling cost: %d\n", tsp(graph));
    return 0;
}