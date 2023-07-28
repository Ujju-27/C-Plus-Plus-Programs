#include <bits/stdc++.h>
using namespace std;

const int MAX = 100; // Maximum number of vertices in the graph

int adj[MAX][MAX]; // Adjacency matrix to represent the graph
bool visited[MAX]; // Boolean array to keep track of visited vertices

// DFS function
bool DFS(int source, int target, int n)
{
    visited[source] = true; // Mark the source vertex as visited
    if (source == target)   // If we have reached the target vertex, return true
        return true;
    for (int i = 0; i < n; i++)
    {
        if (adj[source][i] == 1 && !visited[i])
        {                         
            if (DFS(i, target, n)) // Recursively check if a path exists between i and the target vertex
                return true;
        }
    }
    return false; //If we have explored all possible paths and haven't reached the target vertex, return false
}
int main()
{
    int n, source, target;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;
    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
        visited[i] = false; // Mark all vertices as unvisited
    }
    cout << "Enter the source and target vertices: ";
    cin >> source >> target;
    if (DFS(source, target, n))
        cout << "Yes Path exists"<< endl;
    else
        cout << "No Such Path Exists"<< endl;
    return 0;
}