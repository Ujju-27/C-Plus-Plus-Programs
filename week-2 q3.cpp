#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int countDiff(int a[],int n,int k)
{
    int c=0;
    sort(a,a+n);
    int l=0;
    int r=0;
    while(r<n)
    {
        if(a[r]-a[l]==k)
        {
            c++;
            l++;
            r++;
        }
        else if(a[r]-a[l]>k)
        {
            l++;
        }
        else
            r++;
    }
    return c;
}
int main()
{
    int c,n,i,k;
    cout<<"Enter the Test Cases: ";
    cin>>c;
    while(c>0)
    {
        cout<<"Enter Array Size: ";
        cin>>n;
        int a[n];
        cout<<"Array Elements: ";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<"difference is: ";
        cin>>k;
        cout<<"Count of Pairs with Difference is: "<<countDiff(a,n,k);
    }
    return 0;
}
