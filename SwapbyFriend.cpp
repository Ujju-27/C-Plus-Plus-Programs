#include<iostream>
using namespace std;
class B;
class A{
     int value1;
     public:
     void input(int x1){
          value1=x1;
     }
     friend void swapping(A & , B &);
     void display()
     {
          cout << "\nThe value of data is : " << value1;
     }
};
class B{
     int value2;
     public:
     void input(int x2){
          value2=x2;
     }
     friend void swapping(A &  , B &);
      void display()
     {
          cout << "\nThe value of data is : " << value2;
     }
};
void swapping(A &o1 ,B &o2)
{
     int temp;
     temp=o1.value1;
     o1.value1=o2.value2;
     o2.value2=temp;
}
int main()
{
     A obj1;
     B obj2;
     int x1 , x2;
     cout <<"Enter the value of data of obj1 : ";cin >> x1;
     cout<<"Enter the value of data of obj2 : ";cin >> x2;
     obj1.input(x1);
     obj2.input(x2);
     swapping(obj1,obj2);
     obj1.display();
     obj2.display(); }

