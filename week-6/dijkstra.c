#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 100
int minDistance(int dist[], bool visited[], int vertices)
{
    int min = INT_MAX, minIndex;
    int v;
    for (v = 0; v < vertices; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}
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
void dijkstra(int graph[MAX][MAX], int vertices, int start)
{
    int dist[MAX], i;
    bool visited[MAX];
    for (i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[start] = 0;
    int v, count;
    for (count = 0; count < vertices - 1; count++)
    {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;
        for (v = 0; v < vertices; v++)
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printShortestDistances(dist, vertices, start);
}
int main()
{
    int vertices, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
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
    dijkstra(graph, vertices, start - 1);
    return 0;
}