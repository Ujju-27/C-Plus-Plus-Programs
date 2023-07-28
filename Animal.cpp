#include<iostream>
using namespace std;
class Animal
{
    private:
        int love;
        int sound;
    public:
        int legs;
        int ears;
        void setdata(int l, int s);
        void getdata()
        {
            cout<<"The Dog's love: "<<love<<endl;
            cout<<"The Dog's sound: "<<sound<<endl;
            cout<<"The Dog's legs: "<<legs<<endl;
            cout<<"The Dog's ears: "<<ears<<endl;
        }
};
void Animal::setdata(int l,int s)
{
    love=l;
    sound=s;
}
int main()
{
    Animal Dog;
    Dog.setdata(100,1);
    Dog.ears=2;
    Dog.legs=4;
    Dog.getdata();
    return 0;
}
