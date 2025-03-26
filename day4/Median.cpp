#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == k) return arr[pivotIndex];
        else if (pivotIndex > k) return quickSelect(arr, left, pivotIndex - 1, k);
        else return quickSelect(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

double findMedian(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1)
        return quickSelect(arr, 0, n - 1, n / 2);
    else {
        int mid1 = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int mid2 = quickSelect(arr, 0, n - 1, n / 2);
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    vector<int> arr = {7, 2, 1, 5, 6, 3, 8, 4};
    cout << "Median: " << findMedian(arr) << endl;
    return 0;
}
