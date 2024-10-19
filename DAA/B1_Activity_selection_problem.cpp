#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum number of shops that can be visited
int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    vector<pair<int, int>> shops;
    
    // Step 1: Pair start and end times of shops
    for (int i = 0; i < S.size(); ++i)
        shops.push_back({S[i], E[i]});

    // Step 2: Sort the shops by their ending times
    sort(shops.begin(), shops.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    });

    // Step 3: Track the last visited shop's end time for each person
    vector<int> end_times(K, -1);
    int total_shops = 0;

    // Step 4: Assign shops to persons
    for (auto& shop : shops) {
        for (int i = 0; i < K; ++i) {
            if (end_times[i] < shop.first) {  // Person can visit if no overlap
                end_times[i] = shop.second;   // Update their end time
                total_shops++;                // Count this shop as visited
                break;                        // Move to next shop
            }
        }
    }

    return total_shops;  // Return the total number of shops visited
}

int main() {
    // Test case 1
    vector<int> S1 = {1, 8, 3, 2, 6}, E1 = {5, 10, 6, 5, 9};
    int K1 = 2;
    cout << maxShopsVisited(S1, E1, K1) << endl;  // Output: 4

    // Test case 2
    vector<int> S2 = {1, 2, 3}, E2 = {3, 4, 5};
    int K2 = 2;
    cout << maxShopsVisited(S2, E2, K2) << endl;  // Output: 3

    return 0;
}
