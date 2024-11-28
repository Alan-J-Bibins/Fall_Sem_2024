#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int front;
    int rear;
    int* arr;
} Queue;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int count;
    Node** adjL;
} Graph;

Queue* createQueue(int num)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->arr = (int*)calloc(num, sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int data, int length)
{
    if (queue->front == -1)
        queue->front = 0;

    if (queue->rear == length - 1)
        printf("Overflow\n");
    else
        queue->arr[++queue->rear] = data;
}

int dequeue(Queue* queue)
{
    int answer = -1;
    if (queue->front == -1 || queue->front > queue->rear)
        printf("Underflow\n");
    else
        answer = queue->arr[queue->front++];

    return answer;
}

void freeQueue(Queue** queue)
{
    free((*queue)->arr);
    free(*queue);
    *queue = NULL;
}

Graph* createGraph(int verts)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->count = verts;
    graph->adjL = (Node**)malloc(verts * sizeof(Node*));
    for (int i = 0; i < verts; i++) {
        *(graph->adjL + i) = NULL;
    }
    return graph;
}

void freeGraph(Graph* graph)
{
    for (int i = 0; i < graph->count; i++) {
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

void createEdge(Graph* graph, int src, int dest)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjL[src];
    graph->adjL[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjL[dest];
    graph->adjL[dest] = newNode;
}

void BFS(Graph* graph, int start, int* visited)
{
    Queue* queue = createQueue(graph->count);

    visited[start] = 1;
    enqueue(queue, start, graph->count);

    while (queue->front <= queue->rear && queue->front != -1) {
        int current = dequeue(queue);
        printf("Visited %d\n", current);

        Node* temp = graph->adjL[current];
        while (temp) {
            int adjv = temp->vertex;
            if (!visited[adjv]) {
                visited[adjv] = 1;
                enqueue(queue, adjv, graph->count);
            }
            temp = temp->next;
        }
    }

    freeQueue(&queue);
}

void DFS(Graph* graph, int start, int* visited)
{
    visited[start] = 1;
    printf("Visited %d\n", start);
    Node* temp = graph->adjL[start];
    while (temp) {
        int adjv = temp->vertex;
        if (!visited[adjv]) {
            DFS(graph, adjv, visited);
        }
        temp = temp->next;
    }
}

int main(void)
{
    Graph* graph = createGraph(5);
    createEdge(graph, 0, 1);
    createEdge(graph, 0, 4);
    createEdge(graph, 1, 2);
    createEdge(graph, 1, 3);
    createEdge(graph, 2, 3);
    createEdge(graph, 3, 4);

    int* visited = (int*)calloc(graph->count, sizeof(int));
    printf("BFS:\n");
    BFS(graph, 0, visited);
    free(visited);
    visited = (int*)calloc(graph->count, sizeof(int));
    printf("DFS:\n");
    DFS(graph, 0, visited);

    free(visited);
    freeGraph(graph);
    return 0;
}
