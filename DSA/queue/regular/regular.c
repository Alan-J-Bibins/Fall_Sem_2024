#include <stdio.h>
#include <stdlib.h>
typedef struct Queue {
    int size;
    int rear;
    int front;
    int* arr;
} Queue;

Queue* createQueue(int size)
{
    Queue* queue = (Queue*)malloc(sizeof(size));
    queue->size = size;
    queue->rear = queue->front = -1;
    queue->arr = (int*)calloc(size, sizeof(int));
    return queue;
}

void enqueue(Queue* queue, int n)
{
    if (queue->rear + 1 == queue->size) {
        printf("Overflow\n");
    } else {
        queue->arr[++queue->rear] = n;
        queue->front = queue->front == -1 ? 0 : queue->front;
    }
}

int dequeue(Queue* queue)
{
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Underflow\n");
        return -1;
    } else {
        return queue->arr[queue->front++];
    }
}

void display(Queue* queue)
{
    if (queue->front == -1) {
        printf("Empty\n");
    } else {
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

void freeQueue(Queue** queue)
{
    free((*queue)->arr);
    free(*queue);
    *queue = NULL;
}

int main(int argc, char* argv[])
{
    Queue* queue = createQueue(10);
    enqueue(queue, 5);
    display(queue);
    enqueue(queue, 8);
    display(queue);
    enqueue(queue, 10);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    freeQueue(&queue);
    return 0;
}
