/*Implement Subset Sum Problem.
Statement Given a set of non-negative integers and a value sum, 
the task is to check if there is a subset of the given set whose sum is 
equal to the given sum.
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9 Output: True
Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30 Output: False
*/
#include <iostream>
#include <vector>

using namespace std;

// Function to check if there's a subset that sums up to the given target
bool isSubsetSum(const vector<int>& set, int sum) {
    // dp[i] will be true if a subset with sum i is possible
    vector<bool> dp(sum + 1, false);

    // Base case: A sum of 0 is always possible with an empty subset
    dp[0] = true;

    // Process each element in the set
    for (int num : set) {
        // Update dp array for possible sums (in reverse to avoid reusing elements)
        for (int i = sum; i >= num; i--) {
            if (dp[i - num]) {
                dp[i] = true;  // If sum i-num was possible, then sum i is also possible
            }
        }
    }

    // Return whether the target sum is achievable
    return dp[sum];
}

int main() {
    // Example 1
    vector<int> set1 = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    cout << (isSubsetSum(set1, sum1) ? "True" : "False") << endl;  // Output: True

    // Example 2
    vector<int> set2 = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    cout << (isSubsetSum(set2, sum2) ? "True" : "False") << endl;  // Output: False

    return 0;
}
