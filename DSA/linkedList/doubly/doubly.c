#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node*));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int printList(Node* head)
{
    Node* ptr = head;
    int count = 0;
    while (ptr != NULL) {
        count++;
        printf("%d <=> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\nLinked list has %d nodes\n", count);
    return count;
}

void insertAtStart(Node* head, int data)
{
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node* head, int data)
{
    Node* newNode = createNode(data);
    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
}

void freeList(Node** head)
{
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main(void)
{

    Node* head = createNode(5);
    printList(head);
    insertAtStart(head, 10);
    printList(head);
    insertAtLast(head, 7);
    printList(head);
    insertAtStart(head, 100);
    printList(head);
    freeList(&head);

    return 0;
}
