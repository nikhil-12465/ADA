#include <iostream>
#include <cmath>
using namespace std;

int x[100]; //  column position of the row k 
int n;     

bool Place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false; 
        }
    }
    return true;
}

void NQueen(int k) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i; 
            if (k == n) {
             
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
                NQueen(k + 1); 
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;
    NQueen(1);
    return 0;
}
