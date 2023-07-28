#include<iostream>
using namespace std;
class shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;
    public:
        void initCounter(void)
        {
            counter=0;
        }
        void setPrice(void);
        void displayPrice(void);
};
void shop :: setPrice(void)
{
    cout<<"Enter Id of your Item no.: "<<counter+1;
    cin>>itemId[counter];
    cout<<"Enter Price of your Item: ";
    cin>>itemPrice[counter];
    counter++;
}
void shop :: displayPrice(void)
{
    for(int i=0;i<counter;i++)
    {
        cout<<"The Price of Item with Id "<<itemId[i]<<" is: "<<itemPrice[i];
    }
}
int main()
{
    shop dukaan;
    dukaan.initCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}
