#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge
{
    int source;
    int destination;
    int weight;
};

bool compareEdges(const Edge &edge1, const Edge &edge2)
{
    return edge1.weight < edge2.weight;
}

int findParent(int parent[], int city)
{
    if (parent[city] == city)
        return city;
    return findParent(parent, parent[city]);
}

void unionSets(int parent[], int rank[], int city1, int city2)
{
    int root1 = findParent(parent, city1);
    int root2 = findParent(parent, city2);

    if (rank[root1] < rank[root2])
        parent[root1] = root2;
    else if (rank[root1] > rank[root2])
        parent[root2] = root1;
    else
    {
        parent[root2] = root1;
        rank[root1]++;
    }
}

int calculateMinimumCost(Edge edges[], int numCities, int numEdges)
{
    sort(edges, edges + numEdges, compareEdges);

    int parent[numCities];
    int rank[numCities];
    for (int i = 0; i < numCities; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalCost = 0;
    int numConnections = 0;

    for (int i = 0; i < numEdges; i++)
    {
        int root1 = findParent(parent, edges[i].source);
        int root2 = findParent(parent, edges[i].destination);

        if (root1 != root2)
        {
            totalCost += edges[i].weight;
            unionSets(parent, rank, root1, root2);
            numConnections++;
            if (numConnections == numCities - 1)
                break;
        }
    }

    return totalCost;
}

int main()
{
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    int **adjacencyMatrix = new int *[numCities];
    for (int i = 0; i < numCities; i++)
    {
        adjacencyMatrix[i] = new int[numCities];
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numCities; i++)
    {
        for (int j = 0; j < numCities; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int numEdges = 0;
    for (int i = 0; i < numCities; i++)
    {
        for (int j = i + 1; j < numCities; j++)
        {
            if (adjacencyMatrix[i][j] != 0)
                numEdges++;
        }
    }

    Edge edges[numEdges];
    int edgeIndex = 0;

    for (int i = 0; i < numCities; i++)
    {
        for (int j = i + 1; j < numCities; j++)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                edges[edgeIndex].source = i;
                edges[edgeIndex].destination = j;
                edges[edgeIndex].weight = adjacencyMatrix[i][j];
                edgeIndex++;
            }
        }
    }

    int minimumCost = calculateMinimumCost(edges, numCities, numEdges);
    cout << "Total cost of the minimum spanning weight: " << minimumCost << endl;
}
