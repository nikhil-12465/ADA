#include <iostream>
#include <vector>

using namespace std;

void findMinMAX(vector<int> &a, int low, int mid, int high, int &min, int &max) {
    int left = low;
    int right = mid + 1;
    min = a[left];
    max = a[left];
    int min1 = a[right];
    int max1 = a[right];

    while (left <= mid && right <= high) {
        if (a[left] < min) min = a[left];
        if (a[left] > max) max = a[left];
        left++;

        if (a[right] < min1) min1 = a[right];
        if (a[right] > max1) max1 = a[right];
        right++;
    }

    if (min1 < min) min = min1;
    if (max1 > max) max = max1;
}

void MaxMin(vector<int> &a, int n, int low, int high, int &max, int &min) {
    if (low == high) {
        max = min = a[low];
        return;
    }

    int mid = (high + low) / 2;
    MaxMin(a, n, low, mid, max, min);
    MaxMin(a, n, mid + 1, high, max, min);
    findMinMAX(a, low, mid, high, min, max);
}

int main() {
    vector<int> a;
    int n;

    cout << "Number of elements in the array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        a.push_back(value);
    }

    int low = 0, high = n - 1;
    int max, min;

    MaxMin(a, n, low, high, max, min);

    cout <<"max is :" <<max<<endl;
    cout<< "min is :"<<min <<endl;
    return 0;
}
