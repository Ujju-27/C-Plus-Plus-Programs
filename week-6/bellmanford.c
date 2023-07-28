#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_VERTICES 100
void printShortestDistances(int dist[], int vertices, int start)
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        if (i == start)
            printf("Shortest distance from node %d to node %d is 0\n", start + 1, i + 1);
        else if (dist[i] == INT_MAX)
            printf("No path exists from node %d to node %d\n", start + 1, i + 1);
        else
            printf("Shortest distance from node %d to node %d is %d\n", start + 1, i + 1, dist[i]);
    }
}
void bellmanFord(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start)
{
    int dist[MAX_VERTICES];
    int i, j;
    for (i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    int count, u, v;
    for (count = 0; count < vertices - 1; count++)
    {
        for (u = 0; u < vertices; u++)
        {
            for (v = 0; v < vertices; v++)
            {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    printShortestDistances(dist, vertices, start);
}
int main()
{
    int vertices, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the adjacency matrix:\n");
    int graph[100][100];
    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int start;
    printf("Enter the starting node: ");
    scanf("%d", &start);
    bellmanFord(graph, vertices, start - 1);
    return 0;
}