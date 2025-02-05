#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void magic_square(vector<vector<int>>& arr, int n) {
    int row = 0;
    int col = n / 2;
    int i = 1;
    while (i <= n * n) {
        arr[row][col] = i;

        int next_row = (row - 1 + n) % n;
        int next_col = (col - 1 + n) % n;

        if (arr[next_row][next_col] != 0) {
            row = (row + 1) % n;
        } else {
            row = next_row;
            col = next_col;
        }
        i++;
    }
}

int main() {
    int n = 5;
    
    while (n <= 1000000) {  
        auto start = high_resolution_clock::now();  

        vector<vector<int>> arr(n, vector<int>(n, 0));

    
        magic_square(arr, n);

        auto end = high_resolution_clock::now();  
        auto duration = duration_cast<nanoseconds>(end - start);  

        cout  << n << ": " << duration.count() << endl;

        n *=5; 
    }

    return 0;
}



