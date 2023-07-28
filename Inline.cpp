#include<iostream>
using namespace std;
inline int Max(int x,int y)
{
    return (x>y)?x:y;
}
int main()
{
    cout<<"Max(20,200): "<<Max(20,200)<<endl;
    cout<<"Max(0,200): "<<Max(0,200)<<endl;
    cout<<"Max(100,0101): "<<Max(100,0101)<<endl;
    return 0;
}

