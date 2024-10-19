/*
Implement a problem of maximize Profit by trading stocks 
based on given rate per day. 
Statement: Given an array arr[] of N positive integers which 
denotes the cost of selling and buying a stock on each of 
the N days. The task is to find the maximum profit that can be 
earned by buying a stock on or selling all previously bought stocks 
on a particular day. 
Input: arr[] = {2, 3, 5}                      Output: 5  
Input: arr[] = {8, 5, 1}                      Output: 0  
*/
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum profit from buying and selling stocks
int maxProfit(int* prices, int n) {
    int profit = 0;        // Initialize profit variable
    int currentDay = n - 1; // Start from the last day in the array

    // Loop while there are days to consider
    while (currentDay > 0) {
        int day = currentDay - 1;  // Start from the day before currentDay

        // Traverse backwards through the array and accumulate profit
        // Sell the stock at currentDay if prices[day] < prices[currentDay]
        while (day >= 0 && prices[currentDay] > prices[day]) {
            profit += (prices[currentDay] - prices[day]);  // Add profit
            day--;  // Move to the previous day
        }

        // After accumulating profit, update currentDay to the next day
        // where prices[day] >= prices[currentDay], marking it as the new selling point
        currentDay = day;
    }

    // Return the total accumulated profit
    return profit;
}

int main() {
    // Array of stock prices for consecutive days
    int prices[] = {2, 3, 5};

    // Calculate the number of days based on the size of the array
    int N = sizeof(prices) / sizeof(prices[0]);

    // Call the maxProfit function and print the result
    cout << "Maximum profit from buying and selling stocks on particular day: "<<maxProfit(prices, N);

    return 0;
}
