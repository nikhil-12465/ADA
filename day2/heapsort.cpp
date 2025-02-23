#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm> 
using namespace std;

void heapify(vector<int> &a, int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}


void buildHeap(vector<int> &a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
}

// heap sort :
void heapSort(vector<int> &a, int n) {
    buildHeap(a, n);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    ofstream file("heap_sort_complexity.csv"); 
    file << "Input_Size,Time_Taken\n"; 

    for (long n = 1; n <= 100000; n += 10) {
        vector<int> a(n);
        generate(a.begin(), a.end(), rand); 

        auto start = chrono::high_resolution_clock::now(); 
        heapSort(a, n);
        auto end = chrono::high_resolution_clock::now(); 

        chrono::duration<double> elapsed = end - start; 
        file << n << "," << elapsed.count() << "\n"; 

       
    }

    file.close(); 
    cout << "CSV File 'heap_sort_complexity.csv' generated successfully!\n";
    return 0;
}
