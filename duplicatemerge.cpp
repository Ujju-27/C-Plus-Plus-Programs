#include<iostream>
using namespace std;
void merge(int a[], int beg, int mid, int end)
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
        if(LeftArray[i] <= RightArray[j]){
        a[k] = LeftArray[i];
        i++;
    }
    else{
        a[k] = RightArray[j];
        j++;
    }
    k++;
    }
    while (i<n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }
    while (j<n2)
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
        merge(a, beg, mid, end);
    }
}
int main()
{
    int t;
    cout<<"Enter the Test cases: ";
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int n,temp=0;
        cout<<"Enter the Array size: ";
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
            if(arr[i]==arr[i+1]){
            temp=1;
            break;
        }
        }
        if(temp==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}
