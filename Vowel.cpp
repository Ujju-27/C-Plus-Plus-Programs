#include<iostream>
using namespace std;
int main()
{
    char c;
    cout<<"Enter a Character: ";
    cin>>c;
    if(c=='a'|c=='A'|c=='e'|c=='E'|c=='o'|c=='O'|c=='u'|c=='U')
    {
        cout<<c<<" is a Vowel";
    }
    else
        cout<<c<<" is a Consonant";

}
