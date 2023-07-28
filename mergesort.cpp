#include <bits/stdc++.h>
#include<time.h>
using namespace std;
void merge(int a[],int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = beg;
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        merge(a, beg, mid,end);
    }
}
int main()
{
    clock_t start, end;
    int t;
    cout << "Enter the Test cases: ";    
    cin >> t;
    while (t > 0)
    {
        int n, temp = 0;
        cout << "Enter the Array size: ";
        cin >> n;
        int a[n];
        cout << "Enter the Array Elements: ";
        for (int i = 0; i < n; i++)
        {
            a[i]=((rand()%n*10)+1);
        }
        start= clock();
        mergeSort(a, 0, n - 1);
        end= clock();
        double duration=((double) (end- start)) / CLOCKS_PER_SEC * 1000000;
        cout << "\nSorted Array: ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout <<endl;
        cout<<"Time taken by Merge Sort: "<<duration<<" microseconds"<<endl;
        t--;
    }
    return 0;
}
