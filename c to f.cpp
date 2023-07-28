#include<iostream>
using namespace std;
int main()
{
    float c, f;
    char ch;
    cout << "Enter c to convert celsius into fahrenheit in temperature "<<endl;
    cout << "Enter f to convert fahrenheit into celsius in temperature "<<endl;
    cout << "Enter the Choice(c,f): ";
    cin >> ch;
    if (ch == 'c' || ch == 'C')
    {
        cout << "Enter the degree Fahrenheit: ";
        cin >> f;
        c = (f - 32) / 1.8;
        cout << "\nTemperature Converts in Degree Centigrade: " << c;
    }
    else if (ch == 'f' || ch == 'F')
    {
        cout << "Enter the Degree Celsius: ";
        cin >> c;
        f = (c * 1.8) + 32;
        cout << "\nTemperature Converts in Degree Fahrenheit: " << f;
    }
    else
    {
        cout << "Invalid Choice";
    }
}
