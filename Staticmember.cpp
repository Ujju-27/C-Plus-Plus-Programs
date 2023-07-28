#include<iostream>
using namespace std;
class Employee
{
    int id;
    static int count;
    public:
        void setData(void)
        {
            cout<<"Enter the Id: ";
            cin>>id;
            count++;
        }
        void getData(void)
        {
            cout<<"The Id of this Employee is: "<<id<<" and this is Employee no.: "<<count<<endl;
        }
};
int main()
{
    Employee ujjawal;
    ujjawal.setData();
    ujjawal.getData();
}
