#include<iostream>
using namespace std;

// Function to perform binary search
int binarySearch(int arr[], int size, int key) {

    int start = 0;         // Initialize the starting index of the array
    int end = size - 1;    // Initialize the ending index of the array

    // Calculate the middle index of the array
    int mid = (start + end) / 2;

    // Binary search loop
    while (start <= end) {
        // If the key is found at the middle index, return the index
        if (arr[mid] == key) {
            return mid;
        }
        // If the key is greater than the middle element, search in the right half
        if (key > arr[mid]) {
            start = mid + 1;  // Update the start to search the right half
        }
        // If the key is smaller than the middle element, search in the left half
        else {
            end = mid - 1;    // Update the end to search the left half
        }
        // Recalculate the middle index
        mid = (start + end) / 2;
    }
    // If the key is not found, return -1
    return -1;
}

int main() {
    int n, key;

    // Take input for array size
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare the array with the given size
    int arr[n];

    // Take input for array elements
    cout << "Enter " << n << " sorted elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Take input for the element to search (key)
    cout << "Enter the element to search: ";
    cin >> key;

    // Call binary search function to find the index of the key
    int index = binarySearch(arr, n, key);

    // Output the result
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
