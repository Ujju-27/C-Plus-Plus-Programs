#include<bits/stdc++.h>
using namespace std;
int first(int a[],int l,int h,int x,int n)
{
    while(h>=l)
    {
        int mid=(l+h)/2;
        if((mid==0 || x>a[mid-1]) && a[mid]==x)
            return mid;
        else if(x>a[mid])
            return first(a,(mid+1),h,x,n);
        else if(x<a[mid])
            return first(a,l,(mid-1),x,n);
    }
    return -1;
}
int last(int a[],int l,int h,int x,int n)
{
    while(h>=l)
    {
        int mid=(l+h)/2;
        if((mid==n-1 || x>a[mid-1])&& a[mid]==x)
            return mid;
        else if(x<a[mid])
            return last(a,l,(mid-1),x,n);
        else if(x>a[mid])
            return last(a,(mid+1),h,x,n);
    }
    return -1;
}
int cnt(int a[],int x,int n)
{
    int i,j;
    i=first(a,0,n-1,x,n);
    if(i==-1)
    {
        return i;
    }
    j=last(a,i,n-1,x,n);
    return j-i+1;
}
int main()
{
    int x,i,c,l,k;
    cout<<"Enter the Test Cases: ";
    cin>>c;
    while(c>0)
    {
        int n;
        cout<<"Enter the Array Size: ";
        cin>>n;
        int a[n];
        cout<<"Enter the Elements of Array: ";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<"Count frequency of element: ";
        cin>>k;
        l=cnt(a,x,n);
        cout<<x<<" occurs "<<l<<" times "<<endl;
    }
    return 0;
}
