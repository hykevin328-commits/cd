
#include <stdio.h>

int n;
int e[10][10], a[10][10], b[10][10];

int visited[10];

void closure(int s)
{
    int i;

    visited[s] = 1;

    for(i = 0; i < n; i++)
    {
        if(e[s][i] == 1 && !visited[i])
        {
            closure(i);
        }
    }
}

int main()
{
    int i, j, k;

    printf("Enter number of states: ");
    scanf("%d", &n);

    printf("Enter epsilon transition matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &e[i][j]);
        }
    }

    printf("Enter transition matrix for input a:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter transition matrix for input b:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nEquivalent NFA without epsilon transitions:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nState %d\n", i);

        for(j = 0; j < n; j++)
        {
            visited[j] = 0;
        }

        closure(i);

        printf("a -> { ");

        for(j = 0; j < n; j++)
        {
            if(visited[j])
            {
                for(k = 0; k < n; k++)
                {
                    if(a[j][k])
                    {
                        printf("%d ", k);
                    }
                }
            }
        }

        printf("}\n");

        printf("b -> { ");

        for(j = 0; j < n; j++)
        {
            if(visited[j])
            {
                for(k = 0; k < n; k++)
                {
                    if(b[j][k])
                    {
                        printf("%d ", k);
                    }
                }
            }
        }

        printf("}\n");
    }

    return 0;
}
