#include <vector>
#include <iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    long long exponent = n;

    if (exponent < 0) {
        x = 1 / x;
        exponent = -exponent;
    }

    double result = 1.0;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= x;
        }

        x *= x;
        exponent /= 2;
    }

    return result;
}


int main() {
    vector<int> nums = {1, 3, 5, 7, 9};

    cout << "Index: " << search(nums, 7) << endl;
    cout << "Power: " << myPow(2, 10) << endl;

    return 0;
}