/*Implement a problem of smallest number with at least n 
trailing zeroes in factorial. 
Statement: Given a number n. The task is to find the smallest 
number whose factorial contains at least n trailing zeroes. 
Input : n = 1          Output : 5  
Input : n = 6          Output : 25 */

#include<iostream>
using namespace std;

// Function to find the smallest number whose factorial contains at least 'n' trailing zeroes
int findnum(int n) {
    int num = 1;   // Variable to keep track of the current number
    int cnt = 0;   // Counter to track the number of trailing zeroes

    // Infinite loop to check each number until we find one with 'n' trailing zeroes in its factorial
    while (true) {
        int temp = num;

        // Check how many times the number is divisible by 5
        // Every division by 5 adds a trailing zero in the factorial
        while (temp % 5 == 0) {
            cnt++;  // Increment the trailing zero counter
            temp /= 5;  // Continue to divide by 5 to check higher powers of 5
        }

        // If the count of trailing zeroes is greater than or equal to 'n', return the number
        if (cnt >= n) {
            return num;
        }

        // Increment the number and continue the search
        num++;
    }
}

int main() {
    int n;
    // Ask user for the desired number of trailing zeroes
    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    // Call the function to find the smallest number whose factorial contains 'n' trailing zeroes
    printf("The factorial number having %d trailing zeroes is : %d", n, findnum(n));
    return 0;
}
