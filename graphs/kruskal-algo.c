#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4
#define E 5

struct Edge {
    int u, v, weight;
};

bool dfs_reach(int current, int target, int vertices, int mstAdj[vertices][vertices], bool visited[]) {
    if (current == target) return true;
    visited[current] = true;
    
    for (int i = 0; i < vertices; i++) {
        if (mstAdj[current][i] && !visited[i]) {
            if (dfs_reach(i, target, vertices, mstAdj, visited)) {
                return true;
            }
        }
    }
    return false;
}

bool isConnected(int u, int v, int vertices, int mstAdj[vertices][vertices]) {
    bool visited[V] = {false};
    return dfs_reach(u, v, vertices, mstAdj, visited);
}

int compareEdges(const void* a, const void* b) {
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight - b1->weight;
}

void kruskalMST(struct Edge edges[]) {
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int mstAdj[V][V] = {0}; // Adjacency matrix to track MST edges
    struct Edge mst[V - 1]; // Array to store the final MST edges
    int edgeCount = 0;
    int totalWeight = 0;

    printf("Edges in the constructed MST:\n");

    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (!isConnected(u, v, V, mstAdj)) {
            mstAdj[u][v] = 1;
            mstAdj[v][u] = 1;

            mst[edgeCount++] = edges[i];
            totalWeight += weight;
            
            printf("%d -- %d == %d\n", u, v, weight);
        }
    }

    printf("Total Weight of MST: %d\n", totalWeight);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges);

    return 0;
}