#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int V = 0;

void initGraph(int vertices) {
    V = vertices;
    for(int i=0; i<V; ++i) {
        for(int j=0; j<V; ++j) {
            adj[i][j] = 0;
        }
    }
}

void addEdge(int u, int v, int isDirected) {
    if(u<0 || u>=V || v<0 || v>=V) {
        printf("Invalid vertices!\n");
        return;
    }
    adj[u][v] = 1;
    if(!isDirected) {
        adj[v][u] = 1;
    }
}

void removeEdge(int u, int v, int isDirected) {
    if(u<0 || u>=V || v<0 || v>=V) {
        printf("Invalid vertices!\n");
        return;
    }
    adj[u][v] = 0;
    if(!isDirected) {
        adj[v][u] = 0;
    }
}

void display() {
    printf("\n--- Adjacency Matrix ---\n   ");
    for(int i=0; i<V; ++i)  printf("%d ", i);
    printf("\n");

    for(int i=0; i<V; ++i) {
        printf("%d: ", i);
        for(int j=0; j<V; ++j) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, isDirected;
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &vertices);
    initGraph(vertices);

    printf("Is graph directed? (1 = Yes, 0 = No): ");
    scanf("%d", &isDirected);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i=0; i<edges; ++i) {
        int u, v;
        printf("Edge %d (u v): ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(u, v, isDirected);
    }

    display();

    return 0;
}