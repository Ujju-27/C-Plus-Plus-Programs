#include<iostream>
using namespace std;
class complex
{
    int real,img;
public:
    complex()
    {
        real=0;
        img=0;
    }
    complex(int r,int i)
    {
        real=r;
        img=i;
    }
    void display()
    {
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    complex operator +(complex c)
    {
        complex temp;
        temp.real=real-c.real;
        temp.img=img-c.img;
        return temp;
    }
};
int main()
{
    complex c1(7,8);
    complex c2(9,3);
    complex c3;
    c3=c1+c2;
    c3.display();
    return 0;
}
