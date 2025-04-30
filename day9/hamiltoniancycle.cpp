#include <iostream>
using namespace std;

#define MAX 20

int x[MAX], G[MAX][MAX], n;

void NextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % (n + 1); 
        if (x[k] == 0) return; 

        if (G[x[k - 1]][x[k]] != 0) {
            int j;
            for (j = 1; j < k; j++) {
                if (x[j] == x[k]) break; 
            }
            if (j == k) { 
                if ((k < n) || (k == n && G[x[n]][x[1]] != 0)) {
                    return;
                }
            }
        }
    }
}

void Hamiltonian(int k) {
    while (true) {
        NextValue(k);
        if (x[k] == 0) return; 
        if (k == n) {
            
            for (int i = 1; i <= n; i++)
                cout << x[i] << " ";
            cout << x[1] << " (Cycle Complete)" << endl;
        } else {
            Hamiltonian(k + 1); 
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(i == j){
                G[i][j]=0;
            }
            else{
            cin >> G[i][j];
            }
        }
    }
    for (int i = 0; i < MAX; i++) x[i] = 0;

    x[1] = 1; 
    Hamiltonian(2); 

    return 0;
}
