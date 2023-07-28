#include<iostream>
using namespace std;
int add(int a, int b)
{
    return a+b;
}
int add(int a, int b, int c)
{
    return a+b+c;
}
int main()
{
    cout<<"The sum of 3 and 6 is "<<sum(3,6);
    cout<<"The sum of 3,7 and 6 is "<<sum(3,7,6);
    return 0;
}
