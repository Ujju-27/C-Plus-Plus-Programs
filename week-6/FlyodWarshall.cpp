#include <iostream>
#include <climits>

const int INF = INT_MAX;
using namespace std;
void floydWarshall(int **graph, int V)
{
    int dist[V][V];

    // Initialize the distance matrix with the given graph
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    // Run the Floyd-Warshall algorithm
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // Check for "INF" values in the input
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    // If vertex k is on the shortest path from i to j,
                    // and the distance through k is smaller, update the distance matrix
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    // Print the shortest distance matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Dynamically allocate memory for the graph
    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
    }

    cout << "Enter the adjacency matrix or adjacency list (use INF for missing edges):" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            string input;
            cin >> input;

            // Convert "INF" to actual infinity value
            if (input == "INF")
            {
                graph[i][j] = INF;
            }
            else
            {
                graph[i][j] = stoi(input);
            }
        }
    }
    cout << "Shortest Distance Matrix: "<<endl;
    floydWarshall(graph, V);
    return 0;
}
