#include<iostream>
using namespace std;
class weight
{
    int kg;
public:
    weight()
    {
        kg=0;
    }
    weight(int x)
    {
        kg=x;
    }
    void display()
    {
        cout<<"Weight in Kg is: "<<kg<<endl;
    }
    weight operator -()
    {
        weight temp;
        temp.kg=-kg;
        return temp;
    }
};
int main()
{
    weight w1(65),w2;
    w2=-w1;
    w2.display();
    return 0;
}

