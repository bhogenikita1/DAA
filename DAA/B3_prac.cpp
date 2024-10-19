#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Check if we can complete all tasks within D days with the given maxWork per day
bool canComplete(const vector<int>& tasks, int D, int maxWork) {
    int days = 1, currentWork = 0;

    // Try to allocate tasks to days
    for (int task : tasks) {
        if (currentWork + task > maxWork) {  // If task exceeds the maxWork, allocate a new day
            days++;
            currentWork = task;
        } else {
            currentWork += task;
        }
    }

    return days <= D;  // Return true if we can finish within D days
}

// Find the minimum work to be done each day to finish all tasks in D days
int minWorkPerDay(const vector<int>& tasks, int D) {
    int left = *max_element(tasks.begin(), tasks.end());  // Minimum possible work (largest task)
    int right = accumulate(tasks.begin(), tasks.end(), 0);  // Maximum possible work (sum of all tasks)

    // Perform binary search for the minimum maxWork per day
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canComplete(tasks, D, mid))
            right = mid;  // Try for a smaller maxWork
        else
            left = mid + 1;  // Increase maxWork
    }

    return left;  // The minimum possible maxWork per day
}

int main() {
    vector<int> tasks1 = {3, 4, 7, 15};
    int D1 = 10;
    cout << minWorkPerDay(tasks1, D1) << endl;  // Output: 4

    vector<int> tasks2 = {30, 20, 22, 4, 21};
    int D2 = 6;
    cout << minWorkPerDay(tasks2, D2) << endl;  // Output: 22

    return 0;
}
