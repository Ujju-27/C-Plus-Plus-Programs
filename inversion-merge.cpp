#include<iostream>
using namespace std;
int merge(int a[],int temp[],int l,int mid,int r)
{
    int i,j,k,inv=0,comp=0;
    i=l;
    j=mid;
    k=l;
    while((i<=mid-1) && (j<=r))
    {
        comp++;
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[i++];
            inv+= (mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=a[i++];
    }
    while(j<=r)
    {
        temp[k++]=a[j++];
    }
    for(int m=l;m<=r;m++)
    {
        a[m]=temp[m];
    }
    return inv;
}
int mergesort(int a[],int temp[],int l,int r)
{
    int inv=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        inv+= mergesort(a,temp,l,mid);
        inv+= mergesort(a,temp,mid+1,r);
        inv+= merge(a,temp,l,mid+1,r);
    }
    return inv;
}
int main()
{
    int t,comp=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int temp[n];
        cout<<mergesort(a,temp,0,n-1);
        cout<<comp<<endl;
    }
    return 0;
}