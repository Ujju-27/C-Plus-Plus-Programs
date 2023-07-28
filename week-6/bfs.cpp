#include <iostream>

using namespace std;

bool isBipartite(int **graph, int V)
{
    int *color = new int[V];
    for (int i = 0; i < V; ++i)
        color[i] = 0;

    int *queue = new int[V];
    int front = 0, rear = 0;

    for (int v = 0; v < V; ++v)
    {
        if (color[v] == 0)
        {
            color[v] = 1; // Assign the first color to the current vertex
            queue[rear++] = v;

            while (front != rear)
            {
                int u = queue[front++];
                for (int i = 0; i < V; ++i)
                {
                    if (graph[u][i])
                    {
                        if (color[i] == 0)
                        {
                            color[i] = -color[u];
                            queue[rear++] = i;
                        }
                        else if (color[i] == color[u])
                        {
                            delete[] color;
                            delete[] queue;
                            return false;
                        }
                    }
                }
            }
        }
    }
    delete[] color;
    delete[] queue;
    return true;
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create the adjacency matrix
    int **graph = new int *[V];
    for (int i = 0; i < V; ++i)
    {
        graph[i] = new int[V];
    }

    cout << "Enter the adjacency matrix: \n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];
    }

    // Check if the graph is bipartite
    if (isBipartite(graph, V))
        cout << "The graph is bipartite.\n";
    else
        cout << "The graph is not bipartite.\n";

    // Clean up memory
    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;
    return 0;
}
