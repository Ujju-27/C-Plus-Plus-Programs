#include <iostream>
using namespace std;
int comp = 0;
int merge(int a[], int temp[], int beg, int mid, int end)
{
    int i = beg, j = mid, k = beg, inv = 0;
    while (i <= mid - 1 && j <= end)
    {
        if (a[i]<= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            // LeftArray[i] > RightArray[j] and i < j
            inv += (mid - i);
        }
        comp++;
    }
    while (i <= mid - 1)
    {
        temp[k++] = a[i++];
    }
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    for (i = beg; i <= end; i++)
    {
        a[i] = temp[i];
    }
    return inv;
}
int mergeSort(int a[], int temp[], int beg, int end)
{
    int inv = 0;
    if (end > beg)
    {
        int mid = (beg + end) / 2;
        inv += mergeSort(a, temp, beg, mid);
        inv += mergeSort(a, temp, mid + 1, end);
        inv += merge(a, temp, beg, mid + 1, end);
    }
    return inv;
}
int main()
{
    int t;
    cout << "Enter the Test cases: ";
    cin >> t;
    while (t > 0)
    {
        int n;
        cout << "Enter the Array size: ";
        cin >> n;
        int a[n], temp[n];
        cout << "Enter the Array Elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int inv = mergeSort(a, temp, 0, n - 1);
        cout << "\nSorted Array: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "Comparisons: " << comp << endl;
        cout << "Inversions: " << inv << endl;
        t--;
    }
    return 0;
}
