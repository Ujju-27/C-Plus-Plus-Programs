#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int c=10,i,j;
void sort(int a[])
{
    int temp;
    for(i=0;i<c;i++)
    {
        for(j=i+1;j<c;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
int binarySearch(int a[],int s,int e)
{
    int k=a[c];
    int m;
    cout<<"\nEnter the Element to be Searched: ";
    cin>>k;
    while(s<=e)
    {
        m=(s+e)/2;
        if(a[m]==k)
            return m;
        else if(a[m]<k)
            s=m+1;
        else
        {
            e=m-1;
        }
    }
}
int main()
{
    int a[c];
    for(i=0;i<c;i++)
    {
        a[i]=rand()%((c*10)+1);
    }
    for(i=0;i<c;i++){
        cout<<a[i]<<" ";
    }
    auto start1=high_resolution_clock::now();
    sort(a);
    auto stop1=high_resolution_clock::now();
    auto total=duration_cast<microseconds>(stop1-start1);
    cout<<"\nTime Taken by Sorting: "<<total.count()<<" microseconds";
    cout<<"\nSorted Array: "<<endl;
    for(i=0;i<c;i++){
        cout<<a[i]<<" ";
    }
    auto start2=high_resolution_clock::now();
    binarySearch(a,0,c);
    auto stop2=high_resolution_clock::now();
    auto duration= duration_cast<microseconds>(stop2-start2);
    cout<<"\nTime Taken by Binary Program: "<<duration.count()<<" microseconds";
    return 0;
}
