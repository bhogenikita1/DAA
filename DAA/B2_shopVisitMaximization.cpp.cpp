/*Implement a problem of activity selection problem with K 
persons. 
Statement: Given two arrays S[] and E[] of size N denoting 
starting and closing time of the shops and an integer 
value K denoting the number of people, the task is to find out the 
maximum number of shops they can visit in total if they visit each 
shop optimally based on the following conditions: 
1. A shop can be visited by only one person 
2. A person cannot visit another shop if its timing collide with it 
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2 
Output: 4 
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2 
Output: 3 */

#include <iostream>
using namespace std;

// Function to calculate the maximum number of shops that can be opened
int MaxShops(int S[], int E[], int k, int n) {
    int cnt = 0;  // Counter for the number of shops that can be opened

    int p[k] = {0};  // Array to keep track of the end times for the k available slots

    // Iterate through all the shops
    for (int i = 0; i < n; i++) {
        int start = S[i];  // Get the start time of the current shop
        int end = E[i];    // Get the end time of the current shop

        // Try to allocate the shop to one of the k available slots
        for (int j = 0; j < k; j++) {
            // If the slot is free (end time is less than or equal to the shop's start time)
            if (p[j] <= start) {
                p[j] = end;  // Assign the current shop's end time to the slot
                cnt++;  // Increment the count of shops successfully opened
                break;  // Move on to the next shop
            }
        }
    }

    // Return the total number of shops that can be opened
    return cnt;
}

int main() {
    // Arrays for the start and end times of the shops
    int S[] = {1, 8, 3, 2, 6};  // Start times of the shops
    int E[] = {5, 10, 6, 5, 9}; // End times of the shops

    int k = 2;  // Number of available shop slots
    int n = sizeof(S) / sizeof(S[0]);  // Total number of shops

    // Output the maximum number of shops that can be opened
    cout << "Maximum no. of shops are: " << MaxShops(S, E, k, n);

    return 0;
}
