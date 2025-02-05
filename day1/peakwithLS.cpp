#include <iostream>
#include <vector>
using namespace std;

void findPeak(vector<int> &a, int n) {
    int count = 0;

    if (n==1){
        cout<<" peak is itself "<<endl;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0 && a[i] > a[i + 1]) {  
            cout << i << " is a peak" << endl;
            count++;
            return;
        }
        else if (i == n - 1 && a[i] > a[i - 1]) {  
            cout << i << " is a peak" << endl;
            count++;
            return;
        }
        else if (i > 0 && i < n - 1 && a[i] > a[i + 1] && a[i] > a[i - 1]) {  
            cout << i << " is a peak" << endl;
            count++;
            return;
        }
    }

    if (count == 0) {
        cout << "Peak does not exist" << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    findPeak(a, n);
    return 0;
}
