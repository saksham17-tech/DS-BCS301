#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

Node* adjList[MAX];
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

void removeEdge(int u, int v, int isDirected) {
    if(u<0 || u>=V || v<0 || v>=V) {
        printf("Invalid vertices!\n");
        return;
    }
    Node* curr = adjList[u];
    Node* prev = NULL;
    while(curr!=NULL && curr->dest!=v) {
        prev = curr;
        curr = curr->next;
    }
    if(curr!=NULL) {
        if(prev==NULL)  adjList[u] = curr->next;
        else            prev->next = curr->next;
        free(curr);
    }

    if(!isDirected) {
        curr = adjList[v];
        prev = NULL;
        while(curr!=NULL && curr->dest!=u) {
            prev = curr;
            curr = curr->next;
        }
        if(curr!=NULL) {
            if(prev==NULL)  adjList[v] = curr->next;
            else            prev->next = curr->next;
            free(curr);
        }
    }
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