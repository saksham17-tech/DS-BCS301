#include <stdio.h>

#define MAX 100

int tc[MAX][MAX];
int V = 0;

void transitiveClosure(int adj[MAX][MAX], int vertices) {
    V = vertices;

    // Step 1: Initialize TC matrix and set diagonal elements to 1
    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j)  tc[i][j] = adj[i][j];
        tc[i][i] = 1;
    }

    // Step 2: Warshall's Triple Nested Loop (Intermediate vertex k)
    for(int k=0; k<V; ++k)
        for(int i=0; i<V; ++i)
            for(int j=0; j<V; ++j)
                tc[i][j] = tc[i][j] || (tc[i][k]&&tc[k][j]);
}

void displayTC() {
    printf("\n--- Transitive Closure Matrix ---\n   ");
    for(int i=0; i<V; ++i)  printf("%d ", i);
    printf("\n");

    for(int i=0; i<V; ++i) {
        printf("%d: ", i);
        for(int j=0; j<V; ++j) {
            printf("%d ", tc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    int adj[MAX][MAX] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 0}
    };

    transitiveClosure(adj, vertices);
    displayTC();

    return 0;
}