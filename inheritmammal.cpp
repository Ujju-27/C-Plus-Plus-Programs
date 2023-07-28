#include<iostream>
using namespace std;
class mammal
{
public:
    void print()
    {
        cout<<" This is Mammal "<<endl;
    }
};
class marine
{
public:
    void print()
    {
        cout<<" This is Marine "<<endl;
    }
};
class bluewhale: public mammal,public marine
{
public:
    void print()
    {
        cout<<" This is Whale "<<endl;
    }
};
int main()
{
    bluewhale b1;
    b1.mammal::print();
    b1.marine::print();
    b1.print();
}
