#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cout << "enter the number of test cases: ";
    cin >> T;
    for (int j = 0; j < T; j++)
    {
        int n, s = 0, comp = 0;
        cout << "enter the size of array: ";
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min])
                    min = j;
                comp++;
            }
            if (min != i)
            {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
                s++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << "comparisons = " << comp << endl;
        cout << "swaps= " << s << endl;
    }
}
