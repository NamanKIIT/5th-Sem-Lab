#include <stdio.h>

#define INF 99999

int main()
{
    int n, s;
    int cost[100][100], tree[100][100] = {0};
    int key[100], parent[100], visited[100] = {0};
    int i, j, u, v, min, total = 0;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Starting Vertex: ");
    scanf("%d", &s);

    FILE *fp = fopen("inUnAdjMat.dat", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            fscanf(fp, "%d", &cost[i][j]);
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        key[i] = INF;
        parent[i] = -1;
    }

    key[s - 1] = 0;

    for (i = 0; i < n; i++)
    {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++)
        {
            if (!visited[j] && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;

        if (parent[u] != -1)
        {
            tree[u][parent[u]] = cost[u][parent[u]];
            tree[parent[u]][u] = cost[u][parent[u]];
            total += cost[u][parent[u]];
        }

        for (v = 0; v < n; v++)
        {
            if (cost[u][v] != 0 && !visited[v] && cost[u][v] < key[v])
            {
                key[v] = cost[u][v];
                parent[v] = u;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", tree[i][j]);
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", total);

    return 0;
}