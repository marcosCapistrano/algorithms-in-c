#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *prev;
    struct Node *next;
} Node;

Node *Stack_init(int key)
{
    Node *base = (Node *)malloc(sizeof(Node *));
    base->key = key;
    base->prev = NULL;
    base->next = NULL;
    return base;
}

Node *Stack_push(Node *sp, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = sp;

    sp->next = newNode;
    return newNode;
}

int Stack_pop(Node **sp)
{
    Node *temp = *sp;
    int key = temp->key;

    *sp = (*sp)->prev;
    (*sp)->next = NULL;

    free(temp);

    return key;
}

int main()
{
    Node *sp = Stack_init(1);
    sp = Stack_push(sp, 2);
    sp = Stack_push(sp, 3);
    sp = Stack_push(sp, 4);

    printf("Currently on stack: %d\n", Stack_pop(&sp));
    printf("Currently on stack: %d\n", Stack_pop(&sp));
    printf("Currently on stack: %d\n", Stack_pop(&sp));
    printf("Currently on stack: %d\n", sp->key);
}
