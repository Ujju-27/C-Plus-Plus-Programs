#include<iostream>
using namespace std;
class Employee
{
    int id;
    int salary;
public:
    void setId(void)
    {
        salary=122;
        cout<<"Enter the Id of Employee: ";
        cin>> id;
    }
    void getId(void)
    {
        cout<<"The Id of Employee is: "<<id<<endl;
    }
};
int main()
{
    Employee fb[2];
    for(int i=0;i<2;i++)
    {
        fb[i].setId();
        fb[i].getId();
    }
}
