#include<iostream>
using namespace std;
class B;
class A
{
    int num1;
    public:
        A():num1(12){}
    friend int add(A,B);
};
class B{
    int num2;
    public:
        B():num2(13){}
    friend int add(A,B);
};
