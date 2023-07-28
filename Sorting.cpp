#include<iostream>
using namespace std;
void sorting(int arr[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
              if(arr[min]>arr[j])
              {
                min=j;
              }
        }
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    cout<<"The sorted array becomes : ";
    for(i=0;i<n;i++)
    cout << arr[i] <<" " ;
}
int main()
{
    int n,i;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter  the elements of the  array :  ";
    for(i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sorting(arr,n);
}

