#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) i++;
        while (i <= j && arr[j] > pivot) j--;
        if (i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSortIterative(vector<int> &arr, int low, int high) {
    stack<pair<int, int>> st;
    st.push({low, high});

    while (!st.empty()) {
        low = st.top().first;
        high = st.top().second;
        st.pop();

        if (low < high) {
            int pivotIndex = partition(arr, low, high);
            if (pivotIndex - 1 > low) st.push({low, pivotIndex - 1});
            if (pivotIndex + 1 < high) st.push({pivotIndex + 1, high});
        }
    }
}

void printArray(vector<int> &arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
   int n;
   cout<<"enter the size of the array "<<endl;
   cin>>n;

 vector<int> arr(n);

 for(int i=0;i<n;i++){
    cin>>arr[i];
 }


    cout << "Original array: ";
    printArray(arr, n);

    quickSortIterative(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
