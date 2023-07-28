#include<iostream>
using namespace std;
int main()
{
    int c1=0,c2=0,temp=0,i;
    char str1[30],str2[40];
    cout<<"Enter the First String: ";
    cin>>str1;
    cout<<"Enter the Second String: ";
    cin>>str2;
    while(str1[c1]!='\0')
        c1++;
    while(str2[c2]!='\0')
        c2++;
    i=0;
    while(str1[i]==str2[i] && str1[i]!='\0')
        i++;
    if(str1[i]>str2[i])
        cout<<"First String is Greater than Second String\n";
    else if(str1[i]<str2[i])
        cout<<"Second String is Greater than First String\n";
    else
        cout<<"Both Strings are Equal";
    return 0;
}
