#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int value;
    int weight;
};
bool compare(Item a, Item b)
{
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}
void sortItems(Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double ratioA = (double)items[j].value / items[j].weight;
            double ratioB = (double)items[j + 1].value / items[j + 1].weight;
            if (ratioA < ratioB)
            {
                swap(items[j], items[j + 1]);
            }
        }
    }
}
void fractionalKnapsack(Item items[], int n, int capacity)
{
    sortItems(items, n);
    int currentWeight = 0;
    double totalValue = 0.0;
    cout << "Item-Weight:" << endl;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            cout << i + 1 << "-" << items[i].weight << endl;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)remainingWeight / items[i].weight * items[i].value;
            cout << i + 1 << "-" << remainingWeight << endl;
            break;
        }
    }
    cout << "Maximum value: " << totalValue << endl;
}
int main()
{
    int n;
    cout<<"Enter the No. of Items: ";
    cin >> n;
    Item items[n];
    cout<<"Enter the Weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight;
    }
    cout<<"Enter the Values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].value;
    }
    int capacity;
    cout<<"Enter the Maximum Capacity: ";
    cin >> capacity;
    fractionalKnapsack(items, n, capacity);
    return 0;
}
