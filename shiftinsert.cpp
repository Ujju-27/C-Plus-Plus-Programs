#include<bits/stdc++.h>
using namespace std;
void insertionsort(int a[],int n)
{
    int i,key,j,s=0,comp=0;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
            s++;
            comp++;
        }
        a[j+1]=key;
        s++;
    }
}
void printArray(int a[],int n)
{
    int i,comp,s;
    cout<<"\nSorted Array: ";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"no of comparison: "<<comp<<endl;
    cout<<"shifts: "<<s<<endl;
}
int main()
{
    int c;
    cout<<"Enter the Test Cases: ";
    cin>>c;
    while(c>0)
    {
        int n,i;
        cout<<"Enter the Array Size: ";
        cin>>n;
        int a[n];
        cout<<"Enter the Array Elements: ";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        insertionsort(a,n);
        printArray(a,n);
    }
    return 0;
}
