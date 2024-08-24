/*Implement a problem of move all zeroes to end of array. 
Statement: Given an array of random numbers, Push all the zero’s 
of a given array to the end of the array. For example, if the given 
arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 
9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be 
same.  
Input :  arr[] = {1, 2, 0, 4, 3, 0, 5, 0}; 
Output : arr[] = {1, 2, 4, 3, 5, 0, 0, 0}; */

#include <iostream>
using namespace std;

// Function to move all zeros to the end of the array using divide and conquer approach
void moveZerosToEnd(int arr[], int left, int right) {
    // Base case: if the left index is greater or equal to the right index, stop recursion
    if (left >= right) return;

    // Find the middle index
    int mid = left + (right - left) / 2;

    // Recursively sort the left half
    moveZerosToEnd(arr, left, mid);

    // Recursively sort the right half
    moveZerosToEnd(arr, mid + 1, right);

    // Temporary array to hold non-zero elements
    int temp[right - left + 1];
    int index = 0;

    // Collect all non-zero elements from the left to right range
    for (int i = left; i <= right; i++) {
        if (arr[i] != 0) {
            temp[index++] = arr[i]; // Add non-zero elements to temp array
        }
    }

    // Fill the remaining positions in the temp array with zeros
    while (index < (right - left + 1)) {
        temp[index++] = 0;
    }

    // Copy the temp array back to the original array from left to right
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

int main() {
    // Input array with mixed zeros and non-zero elements
    int A[] = {5, 6, 0, 4, 6, 0, 9, 0, 8, 7};
    
    // Size of the array
    int n = sizeof(A) / sizeof(A[0]);

    // Call the function to move zeros to the end
    moveZerosToEnd(A, 0, n - 1);

    // Output the modified array
    for (int i = 0; i < n; i++) {
        cout << A[i] << " "; // Print each element of the array
    }

    return 0;
}
