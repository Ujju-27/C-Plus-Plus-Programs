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
 cout<<"enter 1 for circle area\t";
 cout<<" 2 for rectangle area\t";
 cout<<" 3 for square area\t";
 cout<<" 4 for triangle area\t";
 cin>>ch;
 switch(ch)
 {
 case 1:
 cout<<"enter the radius of circle"<<endl;
 cin>>c;
 cout<<"area of circle is: "<<area(c)<<endl;
 case 2:
 cout<<"enter length and breath of rectangle"<<endl;
 cin>>a>>b;
 cout<<"area of rectangle is"<<area(a,b)<<endl;
 case 3:
 cout<<"enter the side of square "<<endl;
 cin>>a;
 cout<<"area of square is "<<area(a)<<endl;
 case 4:
 cout<<"enter the base ans heigt of triangle"<<endl;
 cin>>a>>c;
 cout<<"area of triangle is"<<area(a,c)<<endl;
 default:
 exit(1);
 }
 return 0;
 }


