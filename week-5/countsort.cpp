#include<bits/stdc++.h>
using namespace std;
void countSort(char a[], int n)
{
    int c[26]={0};
    int max_count=0;
    char max_char;
    for(int i=0;i<n;i++)
    {
        c[a[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(c[i]>max_count)
        {
            max_count=c[i];
            max_char=i+'a';
        }
    }
    if(max_count==1)
    {
        cout<<"No Duplicates Present"<<endl;
    }
    else
    {
    cout<<max_char<<" - "<<max_count<<endl;}
}
int main()
{
    int t;
    cout << "Enter the Test cases: ";    
    cin >> t;
    while(t--)
    {
        string s;
        int n;
        cout<<"Enter the Size of String: ";
        cin>>n;
        char a[n];
        cout<<"Enter a String: ";
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        countSort(a,n);
    }
    return 0;
}

