#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}
int main()
{
    time_t start, end;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i]=((rand()%n*10)+1);
    }
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    double times = (double(end - start)) / CLOCKS_PER_SEC * 1000000;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout << "Time is: " << times<<" microseconds"<<endl;
    return 0;
}