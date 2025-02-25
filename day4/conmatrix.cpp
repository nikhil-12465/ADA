#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b, int n) {
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}


vector<vector<int>> matrixMulti(const vector<vector<int>> &a, const vector<vector<int>> &b, int n) {
    vector<vector<int>> c(n, vector<int>(n, 0));

    if (n == 2) {
        return multiply(a, b, n); 
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));

    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));


    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = a[i][j];
            A12[i][j] = a[i][j + newSize];
            A21[i][j] = a[i + newSize][j];
            A22[i][j] = a[i + newSize][j + newSize];

            B11[i][j] = b[i][j];
            B12[i][j] = b[i][j + newSize];
            B21[i][j] = b[i + newSize][j];
            B22[i][j] = b[i + newSize][j + newSize];
        }
    }

   
    vector<vector<int>> M1 = matrixMulti(A11, B11, newSize);
    vector<vector<int>> M2 = matrixMulti(A12, B21, newSize);
    vector<vector<int>> M3 = matrixMulti(A11, B12, newSize);
    vector<vector<int>> M4 = matrixMulti(A12, B22, newSize);
    vector<vector<int>> M5 = matrixMulti(A21, B11, newSize);
    vector<vector<int>> M6 = matrixMulti(A22, B21, newSize);
    vector<vector<int>> M7 = matrixMulti(A21, B12, newSize);
    vector<vector<int>> M8 = matrixMulti(A22, B22, newSize);

   
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            c[i][j] = M1[i][j] + M2[i][j];
            c[i][j + newSize] = M3[i][j] + M4[i][j];
            c[i + newSize][j] = M5[i][j] + M6[i][j];
            c[i + newSize][j + newSize] = M7[i][j] + M8[i][j];
        }
    }

    return c;
}


int main() {
    int n;
    cout << "Enter the order of the matrices (must be power of 2 ≤ 32): ";
    cin >> n;

    if (n > 32 || (n & (n - 1)) != 0) { // Check power of 2 condition
        cout << "Invalid matrix size! n must be power of 2 (e.g., 2, 4, 8, 16, 32)" << endl;
        return 1;
    }

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    cout << "Matrix A:" << endl;
    print(a, n);

    cout << "Matrix B:" << endl;
    print(b, n);

    cout << "The result of matrix multiplication is:" << endl;
    vector<vector<int>> ans = matrixMulti(a, b, n);
    print(ans, n);

    return 0;
}
