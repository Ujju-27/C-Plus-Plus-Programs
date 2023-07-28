#include <bits/stdc++.h>
#include<time.h>
using namespace std;
int partition(int a[], int l, int h,int &cmp,int &swp)
{
    int pvt = a[h];
    int j;
    int i = l - 1;
    for (j = l; j < h; j++)
    {
        cmp++;
        if (a[j] <= pvt)
        {
            i++;
            swp++;
            swap(a[i], a[j]);
        }
    }
    swp++;
    swap(a[i + 1], a[h]);
    return i + 1;
}
void quicksort(int a[], int l, int h,int &cmp,int &swp)
{
    if (l < h)
    {
        int pvt_indx = partition(a, l, h,cmp,swp);
        quicksort(a, l, pvt_indx - 1,cmp,swp);
        quicksort(a, pvt_indx + 1, h,cmp,swp);
    }
}
int main()
{   
    int t;
    cout << "Enter the Test Cases: ";
    cin >> t;
    while (t > 0)
    {
        int n, i;
        cout << "Enter the Array Size: ";
        cin >> n;
        int a[n];
        cout<<"Enter the Array Elements: ";
        for (i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        int cmp=0,swp=0;
        quicksort(a, 0, n - 1,cmp,swp);
        cout<<"Sorted Array: ";
        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n\nNo. of Comparisons: " <<cmp<<endl;
        cout<<"No. of Swaps: "<<swp<<endl;
        t--;
    }
    return 0;
}