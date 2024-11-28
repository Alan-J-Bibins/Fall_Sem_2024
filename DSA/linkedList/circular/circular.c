#define MAX 5
#include <stdio.h>
void enqueue(int);
void dequeue();
void display();

struct circ_queue {
    int front;
    int rear;
    int arr[MAX];
} CircQueue;

int main(void)
{
    CircQueue.front = -1;
    CircQueue.rear = -1;
    int choice = 0;
    int num;
    while (choice != 3) {
        display();
        printf("\t1: Enqueue\n\t2: Dequeue\n\t3: Exit\n");
        scanf("%d", &choice);
        num = 0;
        switch (choice) {
        case 1:
            printf("Enter the number to be enqueued: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice\n");
        }
    }
}

void enqueue(int num)
{
    if ((CircQueue.rear + 1) % MAX == CircQueue.front)
        printf("\n\nOverflow!\n\n");
    else {
        if (CircQueue.front == -1 && CircQueue.rear == -1) {
            CircQueue.front = 0;
            CircQueue.rear = 0;
        } else {
            CircQueue.rear = (CircQueue.rear + 1) % MAX;
        }
        CircQueue.arr[CircQueue.rear] = num;
    }
}

void dequeue()
{
    if (CircQueue.front == -1)
        printf("\n\nUnderflow\n\n");
    if (CircQueue.front == CircQueue.rear) {
        CircQueue.front = -1;
        CircQueue.rear = -1;
    } else {
        CircQueue.front = (CircQueue.front + 1) % MAX;
    }
}

void display()
{
    printf("Circular Queue: ");
    int i = CircQueue.front;
    if (CircQueue.front == -1 && CircQueue.rear == -1) {
        printf("Queue is Empty");
    } else {
        while (i != CircQueue.rear) {
            printf("%d ", CircQueue.arr[i]);
            i = (i + 1) % MAX;
        }
        printf("%d ", CircQueue.arr[CircQueue.rear]);
    }
    printf("\n");
}
