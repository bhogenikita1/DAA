/*Implement a problem of number of zeroes. 
Statement: Given an array of 1s and 0s which has all 1s first 
followed by all 0s? Find the number of 0s. Count the number of 
zeroes in the given array. 
Input: arr[] = {1, 1, 1, 1, 0, 0}      Output: 2 
Input: arr[] = {1, 0, 0, 0, 0}         Output: 4 */

#include<bits/stdc++.h>
using namespace std;

// Function to find the first occurrence of 0 in a sorted array of 1s followed by 0s
int firstZeroOccurance(int arr[], int low, int high) {
    if (high >= low) {
        // Calculate the mid index
        int mid = low + (high - low) / 2;

        // Check if the mid element is the first 0
        if ((mid == 0 || arr[mid - 1] == 1) && arr[mid] == 0)
            return mid;

        // If the mid element is 1, search in the right half of the array
        if (arr[mid] == 1)
            return firstZeroOccurance(arr, (mid + 1), high);
        else
            // If the mid element is 0 but not the first 0, search in the left half
            return firstZeroOccurance(arr, low, (mid - 1));
    }

    // Return -1 if 0 is not found in the array
    return -1;
}

// Function to count the total number of 0s in the array
int countTotalZeroes(int arr[], int n) {
    // Find the index of the first 0 in the array
    int first = firstZeroOccurance(arr, 0, n - 1);

    // If no 0s are found, return 0
    if (first == -1) {
        return 0;
    }

    // The number of 0s will be the difference between the total length and the index of the first 0
    return (n - first);
}

int main() {
    // Example input array where 1s are followed by 0s
    int arr[] = {1, 1, 1, 0, 0, 0, 0, 0};

    // Get the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the count of 0s in the array
    printf("Count of zeroes is %d", countTotalZeroes(arr, n));

    return 0;
}
