#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

bool hasCycle(int adjMatrix[][MAX_SIZE], int n, bool visited[], bool recStack[], int v)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] == 1)
            {
                if (!visited[i] && hasCycle(adjMatrix, n, visited, recStack, i))
                {
                    return true;
                }
                else if (recStack[i])
                {
                    return true;
                }
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int adjMatrix[][MAX_SIZE], int n)
{
    bool visited[MAX_SIZE] = {false};
    bool recStack[MAX_SIZE] = {false};

    for (int i = 0; i < n; i++)
    {
        if (hasCycle(adjMatrix, n, visited, recStack, i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int adjMatrix[MAX_SIZE][MAX_SIZE];
    cout << "Enter the adjacency matrix: "<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }

    if (isCyclic(adjMatrix, n))
    {
        cout << "Yes Cycle Exists" << endl;
    }
    else
    {
        cout << "No Cycle Exists" << endl;
    }

    return 0;
}