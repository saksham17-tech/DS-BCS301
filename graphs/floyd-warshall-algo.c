#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[V][V]) {
    printf("Following matrix shows the shortest distances between every pair of vertices:\n   ");
    for (int i = 0; i < V; i++) printf("%d ", i);
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Step 1: Initialize distance matrix with input graph weights
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Main Floyd-Warshall Triple Nested Loops
    for (int k = 0; k < V; k++) {          // Intermediate vertex
        for (int i = 0; i < V; i++) {      // Source vertex
            for (int j = 0; j < V; j++) {  // Destination vertex
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main() {
    // Graph representation where INF represents no direct edge
    int graph[V][V] = {
        {  0,   3, INF,   5 },
        { INF,   0,   2, 1 },
        { INF, INF,   0,   2 },
        { INF, INF, INF,   0 }
    };

    floydWarshall(graph);

    return 0;
}