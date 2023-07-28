#include <iostream>
using namespace std;
class student
{
protected:
    int roll_no;
public:
    void get_no()
    {
        cout << "Enter the Roll No.: ";
        cin >> roll_no;
    }
    void put_no()
    {
        cout << "The Roll no. of Student is: " << roll_no << endl;
    }
};
class test : public virtual student
{
protected:
    float sub1, sub2;

public:
    void get_marks(float a, float b)
    {
        sub1 = a;
        sub2 = b;
    }
    void put_marks()
    {
        cout << "Marks in 1st Subject: " << sub1<<endl;
        cout << "Marks in 2st Subject: " << sub2 << endl;
    }
};
class sports
{
protected:
    float score;

public:
    void get_score(float c)
    {
        score = c;
    }
    void put_score()
    {
        cout << "Score in Sports is: " << score<<endl;
    }
};
class result : public test, public sports
{
    float total;
    public:
    void display()
    {
        total=sub1+sub2;
        cout<<"Total Marks of an Student is: "<<total;
    }
};
int main()
{
    result o1;
    o1.get_no();
    o1.put_no();
    o1.get_marks(96.7,85.4);
    o1.put_marks();
    o1.get_score(98.5);
    o1.put_score();
    o1.display();
}
