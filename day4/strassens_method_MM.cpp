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

vector<vector<int>> matrixAdd(const vector<vector<int>> &A, const vector<vector<int>> &B, int size) {
    vector<vector<int>> C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> matrixSubtract(const vector<vector<int>> &A, const vector<vector<int>> &B, int size) {
    vector<vector<int>> C(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}



vector<vector<int>> matrixMulti(const vector<vector<int>> &a, const vector<vector<int>> &b, int n) {
    vector<vector<int>> c(n, vector<int>(n, 0));

    if (n == 1) {
        return {{a[0][0] * b[0][0]}};
    }
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

    vector<vector<int>> p = matrixMulti(matrixAdd(A11, A22, newSize), matrixAdd(B11, B22, newSize), newSize);
    vector<vector<int>> q = matrixMulti(matrixAdd(A21, A22, newSize), B11, newSize);
    vector<vector<int>> r = matrixMulti(A11, matrixSubtract(B12, B22, newSize), newSize);
    vector<vector<int>> s = matrixMulti(A22, matrixSubtract(B21, B11, newSize), newSize);
    vector<vector<int>> t = matrixMulti(matrixAdd(A11, A12, newSize), B22, newSize);
    vector<vector<int>> u = matrixMulti(matrixSubtract(A21, A11, newSize), matrixAdd(B11, B12, newSize), newSize);
    vector<vector<int>> v = matrixMulti(matrixSubtract(A12, A22, newSize), matrixAdd(B21, B22, newSize), newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            c[i][j] = p[i][j] + s[i][j] - t[i][j] + v[i][j];
            c[i][j + newSize] = r[i][j] + t[i][j];
            c[i + newSize][j] = q[i][j] + s[i][j];
            c[i + newSize][j + newSize] = p[i][j] + r[i][j] - q[i][j] + u[i][j];
        }
    }

    return c;
}



int main() {
    int n;
    cout << "Enter the order of the matrices (it should be in the power  of two ): ";
    cin >> n;

    if ( (n & (n - 1)) != 0) { 
        cout << "n must be power of two 2^x and the x>1 " << endl;
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
