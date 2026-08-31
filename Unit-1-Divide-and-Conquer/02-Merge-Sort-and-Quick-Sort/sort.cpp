#include <iostream>
#include <vector>
using namespace std;

class Sort {
public:
    vector<int> merge_sort(vector<int> arr) {
        if (arr.size() <= 1) {
            return arr;
        }

        int mid = arr.size() / 2;

        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        left = merge_sort(left);
        right = merge_sort(right);

        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                result.push_back(left[i]);
                i++;
            }
            else {
                result.push_back(right[j]);
                j++;
            }
        }

        while (i < left.size()) {
            result.push_back(left[i]);
            i++;
        }

        while (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }

        return result;
    }

    vector<int> quick_sort(vector<int> arr) {
        if (arr.size() <= 1) {
            return arr;
        }

        int pivot = arr.back();

        vector<int> left;
        vector<int> right;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] <= pivot) {
                left.push_back(arr[i]);
            }
            else {
                right.push_back(arr[i]);
            }
        }

        vector<int> result;

        vector<int> sorted_left = quick_sort(left);
        vector<int> sorted_right = quick_sort(right);

        result.insert(result.end(), sorted_left.begin(), sorted_left.end());
        result.push_back(pivot);
        result.insert(result.end(), sorted_right.begin(), sorted_right.end());

        return result;
    }
};


int main() {
    vector<int> arr = {5, 2, 8, 1, 9, 3};

    Sort sorter;

    cout << "Original: ";
    for (int x : arr) {
        cout << x << " ";
    }

    vector<int> merge_result = sorter.merge_sort(arr);
    vector<int> quick_result = sorter.quick_sort(arr);

    cout << "\nMerge Sort: ";
    for (int x : merge_result) {
        cout << x << " ";
    }

    cout << "\nQuick Sort: ";
    for (int x : quick_result) {
        cout << x << " ";
    }

    return 0;
}