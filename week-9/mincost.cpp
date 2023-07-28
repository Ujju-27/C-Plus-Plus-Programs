#include <iostream>
#include <algorithm>
using namespace std;
int mergeFiles(int arr[], int n)
{
    int cost = 0;
    // Base case: If there is only one file, no computation is needed
    if (n <= 1)
        return cost;

    // Loop until there is only one file left
    while (n > 1)
    {
        // Find the two smallest files
        int smallest1 = 0, smallest2 = 1;
        if (arr[smallest1] > arr[smallest2])
            swap(smallest1, smallest2);
        // Find the smallest and second smallest files
        for (int i = 2; i < n; i++)
        {
            if (arr[i] < arr[smallest1])
            {
                smallest2 = smallest1;
                smallest1 = i;
            }
            else if (arr[i] < arr[smallest2])
            {
                smallest2 = i;
            }
        }

        // Merge the two smallest files and update the cost
        int mergedSize = arr[smallest1] + arr[smallest2];
        cost += mergedSize;
        // Replace the two smallest files with the merged file
        arr[smallest1] = mergedSize;
        arr[smallest2] = arr[n - 1];
        n--;
    }
    return cost;
}

int main()
{
    int n;
    cout<<"Enter the Array Size: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the Array Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int minComputationCost = mergeFiles(arr, n);
    cout <<"Minimum Computation Cost is: "<<minComputationCost << endl;
    return 0;
}
