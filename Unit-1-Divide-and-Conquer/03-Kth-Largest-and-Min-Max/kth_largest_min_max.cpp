#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}

pair<int, int> findMinMax(vector<int>& nums) {
    int minVal = nums[0];
    int maxVal = nums[0];

    for (int num : nums) {
        if (num < minVal)
            minVal = num;

        if (num > maxVal)
            maxVal = num;
    }

    return {minVal, maxVal};
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};

    cout << findKthLargest(nums, 2) << endl;

    pair<int, int> result = findMinMax(nums);
    cout << result.first << " " << result.second << endl;

    return 0;
}