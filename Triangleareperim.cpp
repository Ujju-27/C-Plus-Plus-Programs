#include<iostream>
#include<cmath>
using namespace std;
class triangle{
     float a=3, b=4, c=5;
     public:
     void area()
     {
          float s,area;
          s=(a+b+c)*0.5;
          area=sqrt(s*(s-a)*(s-b)*(s-c));
          cout << "\nArea of triangle is  : " << area;
     }
     void perim()
     {
          float perim=a+b+c;
          cout << "\nPerimeter of triangle is : " << perim;
     }

};
int main()
{
     triangle t1;
     t1.area();
     t1.perim();
     return 0;
}


