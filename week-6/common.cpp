#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter the size of array 1: ";
    cin >> m;
    cout << "Enter the size of array 2: ";
    cin >> n;
    int arr1[m], arr2[n];
    cout << "Enter the elements of array 1: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of array 2: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int i = 0, j = 0;
    cout << "Common elements: ";
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            cout << arr1[i] <<" ";
            i++;
            j++;
        }
    }
    return 0;
}