// average case :

// #include <iostream>
// #include <vector>
// #include <chrono>
// using namespace std;
// using namespace chrono;

// void insert(vector<int>& a, int n) {
//     for (int i = 0; i < n; i++) {
//         a.push_back(rand() % 1000);
//     }
// }

// void merge(vector<int>& a, int low, int mid, int high) {
//     int left = low;
//     int right = mid + 1;
//     vector<int> temp;

//     while (left <= mid && right <= high) {
//         if (a[left] <= a[right]) {
//             temp.push_back(a[left]);
//             left++;
//         } else {
//             temp.push_back(a[right]);
//             right++;
//         }
//     }

//     while (left <= mid) {
//         temp.push_back(a[left]);
//         left++;
//     }

//     while (right <= high) {
//         temp.push_back(a[right]);
//         right++;
//     }

//     for (int i = low; i <= high; i++) {
//         a[i] = temp[i - low];
//     }
// }

// void mergesort(vector<int>& a, int low, int high) {
//     if (low >= high)
//         return;
//     int mid = (low + high) / 2;

//     mergesort(a, low, mid);
//     mergesort(a, mid + 1, high);
//     merge(a, low, mid, high);
// }

// int main() {
//     int n = 5;

//     while (n <= 100000) {
//         vector<int> a;
//         insert(a, n);

//         auto start = high_resolution_clock::now();

//         int low = 0;
//         int high = n - 1;
//         mergesort(a, low, high);

//         auto end = high_resolution_clock::now();
//         auto duration = duration_cast<nanoseconds>(end - start);

//         cout << n << ": " << duration.count() << endl;

//         n *= 5;
//     }

//     return 0;
// }


// worst case 

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void insert(vector<int>& a, int n) {
    int k=n;
    for (int i = 0; i < n; i++) {
        a.push_back(k);
        k-- ;
    }
}

void merge(vector<int>& a, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high) {
        if (a[left] <= a[right]) {
            temp.push_back(a[left]);
            left++;
        } else {
            temp.push_back(a[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(a[right]);
        right++;
    }

    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }
}

void mergesort(vector<int>& a, int low, int high) {
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    int n = 5;

    while (n <= 100000) {
        vector<int> a;
        insert(a, n);

        auto start = high_resolution_clock::now();

        int low = 0;
        int high = n - 1;
        mergesort(a, low, high);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << n << ": " << duration.count() << endl;

        n *= 5;
    }

    return 0;
}
