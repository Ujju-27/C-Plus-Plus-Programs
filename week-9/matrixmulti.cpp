#include <iostream>
#include <limits.h>
using namespace std;

// Function to find the minimum number of operations
int findMinimumOperations(int dimensions[], int n) {
    // Create a 2D array to store the minimum number of operations
    int dp[n][n];
    
    // Initialize the diagonal elements to 0
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }
    
    // Iterate over the chain length
    for (int chainLen = 2; chainLen < n; chainLen++) {
        for (int i = 1; i < n - chainLen + 1; i++) {
            int j = i + chainLen - 1;
            dp[i][j] = INT_MAX;
            
            // Find the minimum number of operations
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    
    
    // Return the minimum number of operations
    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;
    
    int dimensions[n + 1];
    cout << "Enter the dimensions of the matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }
    
    int minOperations = findMinimumOperations(dimensions, n + 1);
    
    cout << "Minimum number of operations: " << minOperations << endl;
    
    return 0;
}