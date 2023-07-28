#include <iostream>

using namespace std;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the maximum value that can be achieved
// and the list of selected items
void knapsack(int n, int weights[], int values[], int capacity) {
    // Create a 2D array to store the maximum values
    int dp[n + 1][capacity + 1];

    // Initialize the first row and column with zeros
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    // Fill the dp array using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            // If the current item's weight is less than or equal to the capacity,
            // choose the maximum value by either including or excluding the item
            if (weights[i - 1] <= j)
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            // Otherwise, exclude the current item
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Find the list of selected items
    int i = n, j = capacity;
    int selectedItems[n] = {0};
    while (i > 0 && j > 0) {
        // If the value of current item was included in the optimal solution,
        // mark it as selected and move to the previous item
        if (dp[i][j] != dp[i - 1][j]) {
            selectedItems[i - 1] = 1;
            j -= weights[i - 1];
        }
        i--;
    }

    // Calculate the maximum value
    int maxValue = dp[n][capacity];

    // Print the maximum value and the list of selected items
    cout << "Value = " << maxValue << endl;
    cout << "Weights selected: ";
    for (int i = 0; i < n; i++) {
        if (selectedItems[i] == 1)
            cout << weights[i] << " ";
    }
    cout << endl;

    cout << "Values of selected weights: ";
    for (int i = 0; i < n; i++) {
        if (selectedItems[i] == 1)
            cout << values[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int values[n];
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    knapsack(n, weights, values, capacity);

    return 0;
}
