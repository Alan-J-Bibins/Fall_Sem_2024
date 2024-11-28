#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vert;
    struct Node* next;
} Node;

typedef struct Graph {
    int numV;
    Node** adjL;
} Graph;

Graph* createNewGraph(int verts)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numV = verts;
    graph->adjL = (Node**)malloc(verts * sizeof(Node*));
    for (int i = 0; i < verts; i++) {
        graph->adjL[i] = NULL;
    }

    return graph;
}

void freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->numV; i++) {
        Node* current = graph->adjL[i];
        while (current) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(graph->adjL);
    free(graph);
}

void addEdge(Graph* graph, int src, int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vert = dest;
    newNode->next = graph->adjL[src];
    graph->adjL[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vert = src;
    newNode->next = graph->adjL[dest];
    graph->adjL[dest] = newNode;
}

void DFS(Graph* graph, int start, int* visited)
{
    visited[start] = 1;
    printf("Visited: %d\n", start);

    Node* temp = graph->adjL[start];
    while (temp) {
        int adjv = temp->vert;
        if (!visited[adjv]) {
            DFS(graph, adjv, visited);
        }
        temp = temp->next;
    }
}

void BFS(Graph* graph, int start, int* visited)
{
    int* queue = (int*)malloc(graph->numV * sizeof(int));
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];
        printf("Visited: %d\n", current);

        Node* temp = graph->adjL[current];
        while (temp) {
            int adjv = temp->vert;
            if (!visited[adjv]) {
                visited[adjv] = 1;
                queue[rear++] = adjv;
            }

            temp = temp->next;
        }
    }

    printf("\n");

    free(queue);
}

int main(int argc, char* argv[])
{
    Graph* graph = createNewGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int* visited = (int*)calloc(graph->numV, sizeof(int));

    printf("Breadth First Search:\n");
    BFS(graph, 0, visited);

    free(visited);
    visited = (int*)calloc(graph->numV, sizeof(int));

    printf("Depth First Search:\n");
    DFS(graph, 0, visited);

    free(visited);
    freeGraph(graph);

    return 0;
}
