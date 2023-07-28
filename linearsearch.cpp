#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
int c=1000,i;
void linear(int a[])
{
    int k=a[160];
    for(i=0;i<c;i++)
    {
        if(a[i]==k)
            break;
    }
    cout<<"Element found at: "<<i+1<<"\n";
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
    auto start=high_resolution_clock::now();
    linear(a);
    auto stop=high_resolution_clock::now();
    auto duration= duration_cast<microseconds>(stop-start);
    cout<<"\nTime Taken by Linear Program: "<<duration.count()<<" microseconds";
    return 0;
}
