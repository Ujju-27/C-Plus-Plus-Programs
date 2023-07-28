#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
long long merge(int a[], int temp[], int l, int mid, int r)
{
    int i = l, j = mid, k = l;
    while (i <= mid - 1 && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }
    for (i = l; i <= r; i++)
    {
        a[i] = temp[i];
    }
}
long long mergeSort(int a[], int temp[], int l, int r)
{
    if (r > l)
    {
        int mid = (l + r) / 2;
        mergeSort(a, temp, l, mid);
        mergeSort(a, temp, mid + 1, r);
        merge(a, temp, l, mid + 1, r);
    }
}
int main()
{
    int t;
    time_t start, end;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n], temp[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        a[i] = ((rand() % n * 10) + 1);
    }
    start = clock();
    mergeSort(a, temp, 0, n - 1);
    end = clock();
    double times = (double(end - start)) / CLOCKS_PER_SEC * 1000000;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    cout << "Time is: " << times << " microseconds" << endl;
    return 0;
}