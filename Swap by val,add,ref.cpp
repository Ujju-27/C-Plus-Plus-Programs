#include<iostream>
using namespace std;
void refrence(int &n,int &m)
{
    int sum,i;
    sum=n;
    n=m;
    m=sum;
    cout<<"Call By Refrence: "<<n<<" "<<m<<endl;
}
void value(int n,int m)
{
    int sum;
    sum=n;
    n=m;
    m=sum;
    cout<<"Call By Value: "<<n<<" "<<m<<endl;
}
void address(int *p,int *q)
{
    int sum,i;
    sum=*p;
    *p=*q;
    *q=sum;
    cout<<"Call By Address: "<<*p<<" "<<*q<<endl;
}
int main()
{
    int n,m;
    cout<<"Enter the First Number: ";
    cin>>n;
    cout<<"Enter the Second Number: ";
    cin>>m;
    cout<<"Inputed Value: "<<n<<" "<<m<<endl;
    refrence(n,m);
    value(n,m);
    address(&n,&m);
    return 0;
}
