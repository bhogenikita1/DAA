/*Implement Check if it is possible to transform one string to 
another.
Statement Given two strings s1 and s2 (all letters in uppercase). 
Check if it is possible to convert s1 to s2 by performing following 
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes
*/
#include <iostream>
#include <string>

using namespace std;

// Function to check if it's possible to transform s1 to s2
bool canTransform(const string& s1, const string& s2) {
    string filteredS1;

    // Filter out lowercase letters from s1 and convert uppercase letters
    for (char c : s1) {
        if (isupper(c)) {
            filteredS1 += c;  // Add only uppercase letters to filteredS1
        }
    }

    // Use two pointers to check if s2 is a subsequence of filteredS1
    int j = 0;  // Pointer for s2
    for (char c : filteredS1) {
        if (j < s2.size() && c == s2[j]) {
            j++;  // Move pointer in s2 if there's a match
        }
    }

    // If we have matched all characters in s2, return true
    return j == s2.size();
}

int main() {
    // Example 1
    string s1 = "daBcd";
    string s2 = "ABC";
    cout << (canTransform(s1, s2) ? "yes" : "no") << endl;  // Output: yes

    // Example 2
    string s3 = "argaju";
    string s4 = "RAJ";
    cout << (canTransform(s3, s4) ? "yes" : "no") << endl;  // Output: yes

    return 0;
}
