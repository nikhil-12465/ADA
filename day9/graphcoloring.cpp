#include <iostream>
using namespace std;

const int INF = 9999;
int x[100], G[100][100], n, m;
bool solutionFound = false;

void NextVal(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;

        int i;
        for (i = 1; i <= n; i++) {
            if (G[k][i] != 0 && G[k][i] != INF && x[k] == x[i])
                break;
        }

        if (i == n + 1)
            return;

    } while (true);
}


void mColor(int k) {
    do {
        NextVal(k);
        if (x[k] == 0) {
            return; 
        }

        if (k == n) {

            solutionFound = true;
            cout << "Yes, the graph is colorable with " << m << " colors.\n";
            cout << "One valid coloring is:\n";

            for (int i = 1; i <= n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        } else {
            mColor(k + 1); 
        }

    } while (true);
}

int main() {
  
   
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of colors: ";
    cin >> m;

 
    for (int i = 1; i <= n; i++) {
        x[i] = 0;
    }

    
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j ){
                 G[i][j] =0 ;
            }
            else {
            cin >> G[i][j];
            }
        }
    }

    
    mColor(1);

    if (!solutionFound) {
        cout << "No, the graph is NOT colorable with " << m << " colors.\n";
    }

    return 0;
}
