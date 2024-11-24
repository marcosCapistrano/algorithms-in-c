/*
    A program demonstrating the "sieve of Erastothenes"

    Sets a[i] to:
      - 1 if i is prime
      - 0 if it's not
*/
#include <stdio.h>

#define N 1000

int main()
{
    int a[N + 1];

    a[1] = 0; //sets 1 as 0, because 1 is not prime.
    for (int i = 2; i <= N; i++)
    {
        a[i] = 1;
    }

    for(int i=2; i<=N/2; i++)
    {
        for(int j=2; j <= N/i; j++)
        {
            a[i*j] = 0;
        }
    }

    for(int i=1; i<=N; i++)
    {
        if(a[i])
        {
            printf("%4d", i);
        }
    }
    printf("\n");
}