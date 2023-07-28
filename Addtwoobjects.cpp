#include <iostream>
using namespace std;
class add
{
     int a, b;

public:
     void input()
     {
          cout << "\nEnter the value of a and b : ";
          cin >> a >> b;
     }
     friend void addition(add, add);
};
void addition(add obj1, add obj2)
{
     add obj3;
     obj3.a = obj1.a + obj2.a;
     obj3.b = obj1.b + obj2.b;
     cout << "\nThe value of a and b of Third Object is : " << obj3.a << " " << obj3.b << endl;
}

int main()
{
     add obj1, obj2;
     obj1.input();
     obj2.input();
     addition(obj1, obj2);
}
