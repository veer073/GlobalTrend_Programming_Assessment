#include <bits/stdc++.h>

using namespace std;

int maxDifference(const vector<int>& nums) {
    if (nums.empty()) return 0;
    int minElem = nums[0];
    int maxDiff = 0;
    for (int i = 1; i < nums.size(); ++i) {
        maxDiff = max(maxDiff, nums[i] - minElem);
        minElem = min(minElem, nums[i]);
    }
    return maxDiff;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Maximum difference between any two elements: " << maxDifference(nums) << endl;

    return 0;
}

