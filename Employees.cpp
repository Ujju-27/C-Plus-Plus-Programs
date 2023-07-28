#include <bits/stdc++.h>
using namespace std;
class person
{
public:
    string name, adds;
    int phn_no;
};
class employee : public person
{
public:
    int emp_no;
    string e_name;
};
class manager : public employee
{
public:
    string desgn, dept;
    int basic_sal;

public:
    void get_data()
    {
        cout << "Enter the Employee Details: " << endl;
        cout << "\n";
        cout << "Enter the Employee No: " << endl;
        cin >> emp_no;
        cout << "Enter the Employee Name: " << endl;
        getline(cin, name);
        cout << "Enter the Employee Address: " << endl;
        getline(cin, adds);
        cout << "Enter the Employee Phone No.: " << endl;
        cin >> phn_no;
        cout << "Enter the Employee Designation: " << endl;
        getline(cin, desgn);
        cout << "Enter the Employee Department: " << endl;
        cin >> dept;
        cout << "Enter the Basic Salary of Employee: " << endl;
        cin >> basic_sal;
    }
    int salary()
    {
        return basic_sal;
    }
    void print()
    {
        cout << "-------------------------------------------" << endl;
        cout << "Manager having Highest Salary: " << endl;
        cout << "Employee No.: " << emp_no << endl;
        cout << "Name of Manager: " << e_name << endl;
        cout << "Address of Manager: " << adds << endl;
        cout << "Phone No. of Manager: " << phn_no << endl;
        cout << "Designation of Manager: " << desgn << endl;
        cout << "Department of Manager: " << dept << endl;
        cout << "Salary: " << basic_sal << endl;
        cout << "-------------------------------------------" << endl;
    }
};
int main()
{
    int n, i, sal = 0, index;
    manager m[100];
    cout << "Enter the No. of Managers: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        m[i].get_data();
    }
    for (i = 0; i < n; i++)
    {
        if (m[i].salary() > sal)
        {
            sal = m[i].salary();
            index = i;
        }
    }
    m[index].print();
    return 0;
}
