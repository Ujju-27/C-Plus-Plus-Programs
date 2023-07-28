#include<iostream>
using namespace std;
float area(float r)
{
 float ans=3.14*r*r;
 return ans;
}
int area(int l,int b)
{
 int ans=l*b;
 return ans;
}
int area(int a)
{
 int ans=a*a;
 return ans;
}
float area(int b,float h)
{
 float ans=(1/2.0)*b*h;
 return ans;
}
int main()
{
 int a,b;
 float c;
 int ch;
 cout<<"Please Enter Choice: "<<endl;
 cout<<"Enter 1. for circle area\t"<<endl;
 cout<<"Enter 2. for rectangle area\t"<<endl;
 cout<<"Enter 3. for square area\t"<<endl;
 cout<<"Enter 4. for triangle area\t"<<endl;
 cin>>ch;
 switch(ch)
 {
 case 1:
 cout<<"Enter the radius of circle"<<endl;
 cin>>c;
 cout<<"Area of circle is: "<<area(c)<<endl;
 break;
 case 2:
 cout<<"Enter length and breadth of rectangle"<<endl;
 cin>>a>>b;
 cout<<"Area of rectangle is"<<area(a,b)<<endl;
 break;
 case 3:
 cout<<"Enter the side of square "<<endl;
 cin>>a;
 cout<<"Area of square is "<<area(a)<<endl;
 break;
 case 4:
 cout<<"Enter the base and height of triangle"<<endl;
 cin>>a>>c;
 cout<<"Area of triangle is"<<area(a,c)<<endl;
 break;
 default:
 exit(1);
 }
 return 0;
 }


