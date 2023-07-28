#include<iostream>
using namespace std;
class A
{
    static int cnt;
    public:
        void obj_count()
        {
            cnt++;
        }
        void display()
        {
            cout<<"The Total No. of Objects are: "<<cnt<<endl;
        }

    };
    int A::cnt;
    int main()
    {
        A obj1,obj2,obj3;
        obj1.obj_count();
        obj2.obj_count();
        obj3.obj_count();
        obj1.display();
        return 0;
    }
