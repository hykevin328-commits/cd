#include<stdio.h>

int e[10][10], a[10][10], b[10][10];
int visited[10];
int i, j, n;

void eclosure(int state)
{
    int i;

    visited[state] = 1;
    printf("%d ", state);

    for(i = 0; i < n; i++)
    {
        if(e[state][i] == 1 && !visited[i])
        {
            eclosure(i);
        }
    }
}

int main()
{
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the epsilon transitions:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }

    printf("Enter the a transitions:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the b transitions:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nEpsilon closures:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            visited[j] = 0;
        }

        printf("Epsilon closure of %d = { ", i);

        eclosure(i);

        printf("}\n");
    }

    return 0;
}
