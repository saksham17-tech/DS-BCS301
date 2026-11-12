#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adjList[MAX];
int visited[MAX];
int V = 0;

Node* create(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void initGraph(int vertices) {
    V = vertices;
    for(int i=0; i<V; ++i) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
}

void addEdge(int u, int v, int isDirected) {
    if(u<0 || u>=V || v<0 || v>=V) {
        printf("Invalid vertices!\n");
        return;
    }
    Node* newNode = create(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    if(!isDirected) {
        Node* revNode = create(u);
        revNode->next = adjList[v];
        adjList[v] = revNode;
    }
}

void resetVisited() {
    for(int i=0; i<V; ++i) {
        visited[i] = 0;
    }
}

void bfs(int start) {
    resetVisited();
    int q[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    q[rear++] = start;

    printf("BFS Traversal: ");
    while(front < rear) {
        int curr = q[front++];
        printf("%d ", curr);

        Node* temp = adjList[curr];
        while(temp!=NULL) {
            int neighbor = temp->dest;
            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                q[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void dfsUtil(int curr) {
    visited[curr] = 1;
    printf("%d ", curr);

    Node* temp = adjList[curr];
    while(temp!=NULL) {
        int neighbor = temp->dest;
        if(!visited[neighbor]) {
            dfsUtil(neighbor);
        }
        temp = temp->next;
    }
}

void dfs(int start) {
    resetVisited();
    printf("DFS Traversal: ");
    dfsUtil(start);
    printf("\n");
}

void display() {
    printf("\n--- Adjacency List ---\n");
    for(int i=0; i<V; ++i) {
        printf("Vertex %d: ", i);
        Node* curr = adjList[i];
        while(curr!=NULL) {
            printf("%d -> ", curr->dest);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int vertices, edges, isDirected, start;
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

    printf("\nEnter starting vertex for BFS and DFS: ");
    scanf("%d", &start);

    bfs(start);
    dfs(start);

    return 0;
}