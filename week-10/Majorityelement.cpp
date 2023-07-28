#include <iostream>
using namespace std;

int findCandidate(int arr[], int n)
{
    int candidate = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == candidate)
            count++;
        else
            count--;

        if (count == 0)
        {
            candidate = arr[i];
            count = 1;
        }
    }
    return candidate;
}

bool isMajority(int arr[], int n, int candidate)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            count++;
    }
    return (count > n / 2);
}

void findMajorityAndMedian(int arr[], int n)
{
    int candidate = findCandidate(arr, n);
    if (isMajority(arr, n, candidate))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    // Sorting the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Finding the median of the array
    int median;
    if (n % 2 == 0)
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    else
        median = arr[n / 2];

    cout <<"Median is: "<<median << endl;
}

int main()
{
    int n;
    cout<<"Enter the Array Size: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findMajorityAndMedian(arr, n);

    return 0;
}
