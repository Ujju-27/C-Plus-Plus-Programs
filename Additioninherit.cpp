#include<iostream>
using namespace std;
class data
{
protected:
    int a,b;
public:
    void get_data()
    {
        cout<<"Enter the Value of a and b: ";
        cin>>a>>b;
    }
};
class sum: public data
{
    int sum;
public:
    void total()
    {
        cout<<"Value of a is: "<<a<<endl;
        cout<<"Value of b is: "<<b<<endl;
        sum=a+b;
        cout<<"Sum is: "<<sum<<endl;
    }
};
int main()
{
    sum obj;
    obj.get_data();
    obj.total();
    return 0;
}
