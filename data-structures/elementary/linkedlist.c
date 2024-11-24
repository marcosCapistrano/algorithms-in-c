#include <stdio.h>

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

Node *List_init(int key)
{
    Node *head = (Node *)malloc(sizeof(Node *));
    head->key = key;
    head->next = NULL;
}

Node *List_insert(Node *node, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->key = key;
    newNode->next = NULL;

    node->next = newNode;
    return newNode;
}

int *List_delete(Node *head, Node *node)
{
    Node *temp = head;
    while(temp->next != node)
    {
        temp = temp->next;
    }

    temp->next = node->next;

    int key = node->key;
    free(node);

    return key;
}

int main()
{
    Node *head = List_init(1);
    if(!head)
    {
        printf("Could not create Linked List!");       
        return -1;
    }

    Node *second = List_insert(head, 2);
    Node *third = List_insert(second, 3);

    printf("Before deletion: ");
    Node *temp = head;
    while(temp != NULL)
    {
        printf("%d - ", temp->key);
        temp = temp->next;
    }
    printf("\n");

    List_delete(head, second);

    printf("After deletion: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d - ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}