/*
    The first half of this program uses an array to implement a stack, simple if the max size of the stack is known.
    The second half is implemented using a linked list, more complicated but allows for dynamic size.
*/
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_IMPLEMENTATION 1

#ifdef ARRAY_IMPLEMENTATION

#define MAX 100

static int stack[MAX+1], p;

void Stack_init()
{
    p = 0;
}

void Stack_push(int v)
{
    stack[p++] = v;
}

int Stack_pop()
{
    return stack[--p];
}

#endif


#ifdef LINKEDLIST_IMPLEMENTATION
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
#endif