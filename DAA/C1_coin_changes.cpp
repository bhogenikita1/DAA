/*Implement Coin Change problem.
Statement Given an integer array of coins[ ] of size N representing 
different types of currency and an integer sum, The task is to find 
the number of ways to make sum by using different combinations 
from coins[]. 
Note: Assume that you have an infinite supply of each type of 
coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5
*/

#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeSum(int sum, const vector<int>& coins) {
    // Create a dp array to store the number of ways to make each sum
    vector<int> dp(sum + 1, 0);

    // There is 1 way to make sum 0 (no coins)
    dp[0] = 1;

    // Loop over each coin
    for (int coin : coins) {
        // Update the dp array for all sums that can be formed with this coin
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[sum];  // Return the number of ways to make the target sum
}

int main() {
    // Example 1
    int sum1 = 4;
    vector<int> coins1 = {1, 2, 3};
    cout << "Number of ways to make sum " << sum1 << ": " << countWaysToMakeSum(sum1, coins1) << endl;  // Output: 4

    // Example 2
    int sum2 = 10;
    vector<int> coins2 = {2, 5, 3, 6};
    cout << "Number of ways to make sum " << sum2 << ": " << countWaysToMakeSum(sum2, coins2) << endl;  // Output: 5

    return 0;
}

