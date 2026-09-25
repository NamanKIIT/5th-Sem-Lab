#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    int n, m, i, j, count = 0, total = 0;
    struct Edge e[100], temp;
    FILE *fp;

    fp = fopen("kruskal.dat", "r");

    if (fp == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    fscanf(fp, "%d %d", &n, &m);

    for (i = 0; i < m; i++)
        fscanf(fp, "%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    fclose(fp);

    for (i = 1; i <= n; i++)
        parent[i] = i;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    printf("Edge Cost\n");

    for (i = 0; i < m && count < n - 1; i++)
    {
        if (find(e[i].u) != find(e[i].v))
        {
            printf("%d--%d %d\n", e[i].u, e[i].v, e[i].w);
            total += e[i].w;
            unite(e[i].u, e[i].v);
            count++;
        }
    }

    printf("Total Weight of the Spanning Tree: %d\n", total);

    return 0;
}