#include <stdio.h>

int main()
{
    int n, m, i, k;
    int a[20][2] = {0};
    int visited[1024] = {0};
    int queue[1024], front = 0, rear = 0;
    int s, ns;

    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("Enter the number of transitions: ");
    scanf("%d", &m);

    printf("Enter the transitions (source input destination):\n");

    for(i = 0; i < m; i++)
    {
        int u, c, v;

        printf("For transition %d:\n", i + 1);
        scanf("%d%d%d", &u, &c, &v);

        a[u][c] |= (1 << v);
    }

    visited[1] = 1;
    queue[rear++] = 1;

    printf("\nDFA\n");

    while(front < rear)
    {
        s = queue[front++];

        printf("{");

        for(i = 0; i < n; i++)
        {
            if(s & (1 << i))
            {
                printf("%d", i);
            }
        }

        printf("}");

        for(k = 0; k < 2; k++)
        {
            ns = 0;

            for(i = 0; i < n; i++)
            {
                if(s & (1 << i))
                {
                    ns |= a[i][k];
                }
            }

            printf("---%d---{", k);

            for(i = 0; i < n; i++)
            {
                if(ns & (1 << i))
                {
                    printf("%d", i);
                }
            }

            printf("}");

            if(!visited[ns])
            {
                visited[ns] = 1;
                queue[rear++] = ns;
            }
        }

        printf("\n");
    }

    return 0;
}