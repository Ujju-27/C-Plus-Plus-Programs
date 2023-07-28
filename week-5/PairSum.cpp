#include <bits/stdc++.h>
using namespace std;
#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
// Function to find two elements in the array with sum equal to key
void findPair(int arr[], int n, int key)
{
    // Sort the array
    mergeSort(arr,0,n-1);

    // Initialize left and right pointers
    int left = 0, right = n - 1;

    // Traverse the array with two pointers
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == key)
        {
            cout << arr[left] << " " << arr[right] << endl;
            return;
        }
        else if (sum < key)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << "No Such Elements Exist" << endl;
}

int main()
{
    int t;
    cout << "Enter the Test Cases: ";
    cin >> t;

    while (t--)
    {
        int n, key;
        cout << "Enter the Size of Array: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements of Array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the Key: ";
        cin >> key;
        findPair(arr, n, key);
    }

    return 0;
}