#include <stdio.h>

struct node
{
    int key;
    struct node *next;
};

int main()
{
    int N, M;
    struct node *t, *x;

    scanf("%d %d", &N, &M);

    /* first, the list is constructed with keys from 1 to N, circular list*/
    t = (struct node *)malloc(sizeof *t);
    t->key = 1;
    x = t;

    for(int i=2; i<=N; i++)
    {
        t->next = (struct node *)malloc(sizeof *t);
        t = t->next;
        t->key = i;
    }
    /* ----------------------------- */

    // x holds onto the beggining of the list as it's built
    t->next = x;

    while(t != t->next)
    {
        for(int i=1; i<M; i++)
        {
            t = t->next;
        }

        printf("%d ", t->next->key);
        x = t->next;
        t->next = t->next->next;
        free(x);
    }

    printf("%d\n", t->key);
}