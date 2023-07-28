#include<iostream>
using namespace std;
class student{
   string name,Grade;
   int age,year,marks[3],i;
   char section;
   public:
    void cal_percent(int sum)
    {
        float percent;
        percent=(sum/3);
        if(percent >= 90 && percent <=100)  Grade ='A';
        else if(percent >= 80 )  Grade ='B';
        else if(percent >= 60 )  Grade ='C';
        else if(percent >= 40)  Grade ='D';
        else Grade ="Fail";
    }
    void input()
    {
        int sum;
        string g;
        getchar();
        cout << "Enter the name of student : " ;     getline(cin , name);
        cout << "Age : " ;     cin >> age;
        cout << "Year : ";     cin >> year;
        cout << "Section : "; cin >>section;
        cout <<"Enter the marks in three subjects ( CS , DSA ,Mathematics) \n\n";
        for(i=0;i<3;i++)
        {
            cout << i+1 << ". Subject : ";
            cin >> marks[i];
            sum+=marks[i];
        }
    cout <<"\n\n----------------------------\n\n";
    cal_percent(sum);
    }
    void display()
    { cout<< "\n\n";
        cout << "Name of student : " << name<<endl;
        cout << " Age : " << age<<endl;
        cout << "Year : " << year<<endl;
        cout <<"The grade of the student is : " << Grade<<endl;
    }
};
int main()
{
    int n, i;
    cout << "Enter the number of students : ";  cin >> n;
    student s[n];
    for(i=0;i<n;i++)
        s[i].input();
    cout << "\n\n_______________The details of the students are __________________\n\n";
    for(i=0;i<n;i++)
        s[i].display();

}

