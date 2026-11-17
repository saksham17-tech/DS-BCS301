#include <stdio.h>
#include <stdbool.h>
#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int vertices;

void DFS(int v) {
    visited[v] = true;
    printf("V%d ", v+1);

    for(int i=0; i<vertices; ++i)
        if(adj[v][i]==1 && !visited[i])
            DFS(i);
}

void findConnectedComponents() {
    int component_id = 1;
    
    for(int i=0; i<vertices; ++i)   visited[i] = false;
    
    for(int i=0; i<vertices; ++i) {
        if(!visited[i]) {
            printf("Subgraph %d: { ", component_id++);
            DFS(i);
            printf("}\n");
        }
    }
}

int main() {
    vertices = 8;
    
    for(int i=0; i<vertices; ++i)
        for(int j=0; j<vertices; ++j)
            adj[i][j] = 0;
            
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[0][2] = adj[2][0] = 1;
    
    adj[3][4] = adj[4][3] = 1;
    
    adj[5][6] = adj[6][5] = 1;
    
    printf("Finding Connected Components (Subgraphs):\n");
    findConnectedComponents();
    
    return 0;
}