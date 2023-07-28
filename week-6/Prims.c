#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 100

int findMinKeyVertex(int key[], bool vis[], int num)
{
    int min = INT_MAX, minIndex;

    for (int v = 0; v < num; v++)
    {
        if (vis[v] == false && key[v] < min)
        {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

int printMST(int parent[], int **graph, int num)
{
    int totalCost = 0;
    for (int i = 1; i < num; i++)
    {
        totalCost += graph[i][parent[i]];
    }
    return totalCost;
}

int primMST(int **graph, int num)
{
    int parent[MAX_CITIES];
    int key[MAX_CITIES];
    bool vis[MAX_CITIES];

    for (int i = 0; i < num; i++)
    {
        key[i] = INT_MAX;
        vis[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < num - 1; count++)
    {
        int u = findMinKeyVertex(key, vis, num);
        vis[u] = true;

        for (int v = 0; v < num; v++)
        {
            if (graph[u][v] && vis[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    return printMST(parent, graph, num);
}

int main()
{
    int num;

    printf("Enter the number of cities: ");
    scanf("%d", &num);

    int **graph = (int **)malloc(num * sizeof(int *));
    for (int i = 0; i < num; i++)
    {
        graph[i] = (int *)malloc(num * sizeof(int));
    }

    printf("Enter the adjacency matrix (cost of connecting each city):\n");
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int totalCost = primMST(graph, num);
    printf("Total cost of the minimum spanning tree: %d\n", totalCost);
    return 0;
}
