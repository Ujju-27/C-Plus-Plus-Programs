#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float n;
	cout << "Enter any decimal number : ";
	cin >> n;
	cout << "The number become : ";
	cout << fixed << setprecision(2) << n;
	return 0;
}

