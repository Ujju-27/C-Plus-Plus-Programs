#include<iostream>
using namespace std;
class student {
	public:
		int roll_no;
		int marks;
		string name;
};
int main() {
	student s1,s,s2,s3;
	cout << "Enter the roll.no: ";
	cin >> s1.roll_no;
	cout << "Enter the marks: ";
	cin >> s1.marks;
	cout << "Enter the name of student: ";
	cin >> s1.name;
	cout <<"\nName : " <<  s1.name << "\nRoll_no : "<< s1.roll_no << "\nMarks : "<< s1.marks;
	return 0;

}

