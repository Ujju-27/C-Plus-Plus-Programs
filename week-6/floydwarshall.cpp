#include <iostream>
using namespace std;

#define INF 999999

void shortestPath(int graph[10][10], int V, int src, int dest, int k)
{
    int dist[V][V][k + 1];

    for (int e = 0; e <= k; e++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {

                dist[i][j][e] = INF;

                if (e == 0 && i == j)
                    dist[i][j][e] = 0;

                if (e == 1 && graph[i][j])
                    dist[i][j][e] = graph[i][j];

                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        if (graph[i][a] && i != a &&
                            j != a && dist[a][j][e - 1] != INF)
                        {
                            dist[i][j][e] = min(dist[i][j][e],
                                                graph[i][a] + dist[a][j][e - 1]);
                        }
                    }
                }
            }
        }
    }

    // Required shortest distance
    int ans = INF;
    for (int e = 1; e <= k; e++)
        if (dist[src - 1][dest - 1][e] < ans)
            ans = dist[src - 1][dest - 1][e];

    if (ans != INF)
        cout << "Weight of Shortest path from("<<src<<","<<dest<<") with "<< k << " edges: " << ans << endl;
    else
        cout << "No path of length " << k << " is available" << endl;
}

int main()
{
    int V, src, dest, k;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    int graph[10][10];
    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }
    cout << "Enter the source vertex, destination vertex, and k:" << endl;
    cin >> src >> dest >> k;
    shortestPath(graph, V, src, dest, k);
    return 0;
}
