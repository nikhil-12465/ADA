#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int findpeak(vector<int> &a, int low, int high, int n)
{

    int mid = (low + high) / 2;

    // according to problem if the mid is the peak then it will return the mid and if their is given the peak is 0th value or the n-1th value then this  is possible

    if (mid == 0 && a[mid] >= a[mid + 1])
    {
        return mid;
    }
    else if(mid == n - 1 && a[mid] >= a[mid - 1])
    {
        return mid;
    }

    else if(a[mid] >= a[mid + 1] && a[mid] >= a[mid - 1])
    {
        return mid ;
    }
    else if(mid > 0 && a[mid] < a[mid - 1])
    {
        return findpeak(a, low, mid - 1, n);
    }
    else
    {
        return findpeak(a, mid + 1, high, n);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int low = 0;
    int high = n - 1;

    int x = findpeak(a, low, high, n);
    cout << x << " is a peak " << endl;
    return 0;
}