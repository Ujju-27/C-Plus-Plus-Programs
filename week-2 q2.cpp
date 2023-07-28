#include<bits/stdc++.h>
using namespace std;
int findIndices(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[i]+a[j]==a[k])
                {
                    cout<<"Triplet Found: "<<i+1<<","<<j+1<<","<<k+1<<endl;
                    return 1;
                }
                k++;
            }
        }
    return 0;
}
int main()
{
    int c;
    cout<<"Enter the Test Cases: ";
    cin>>c;
    while(c>0)
    {
        int n,k,i;
        cout<<"Enter Array Size: ";
        cin>>n;
        int a[n];
        cout<<"Enter Array Elements: ";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int found= findIndices(a,n);
        if(!found)
        {
            cout<<"No Sequence Found"<<endl;
        }
        c--;
    }
    return 0;
}
