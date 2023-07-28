#include<iostream>
#include<vector>
using namespace std;
int main(){
 int T;
 cout<<"enter the number of test cases: ";
 cin>>T;
 for(int j=0;j<T;j++){
 int n, s=0, comp=0;
 cout<<"enter the size of array: ";
 cin>>n;
 vector<int> arr(n);
 for(int i=0;i<n;i++){
 cin>>arr[i];
 }
 for(int i=1;i<n;i++){
 int key=arr[i];
 int j=i-1;
 while(j>=0 && arr[j]>key){
 arr[j+1]=arr[j];
 j--;
 s++;
 comp++;
 }
 arr[j+1]=key;
 s++;
 }
 for(int i=0;i<n;i++){
 cout<<arr[i]<<" ";
 }
 cout<<endl<<"comparisons = "<<comp<<endl;
 cout<<"shifts = "<< s<<endl;
}
}
