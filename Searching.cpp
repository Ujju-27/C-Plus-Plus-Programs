#include<iostream>
using namespace std;
void search(int arr[],int n)
{
    int num,i;
    cout <<"Enter the number to be search : ";
    cin >> num;
    for(i=0;i<n-1;i++)
    {
         if(arr[i]==num)
         {
              break;
         }
    }
    if(i==n)
    cout << "\nElement  was not found ";
    else
    cout<<"\nThe position of the array is  : " << i;

}
int main()
{
    int n,i;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter  the elemnets of the  array :  ";
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    search(arr,n);
}

