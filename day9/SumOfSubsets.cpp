#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; 
vector<int> w; 
vector<int> x; 

void sumOfSubsets(int S, int k, int r) {
    x[k] = 1; 

    if (S + w[k] == m) {
       
        for (int i = 0; i <= k; i++)
            if (x[i] == 1) cout << w[i] << " ";
        cout << endl;
    }
    else if (S + w[k] + w[k + 1] <= m)
        sumOfSubsets(S + w[k], k + 1, r - w[k]);

 
    if ((S + r - w[k] >= m) && (k + 1 < n) && (S + w[k + 1] <= m)) {
        x[k] = 0;
        sumOfSubsets(S, k + 1, r - w[k]);
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;
    
    w.resize(n);
    x.resize(n, 0);

    cout << "Enter the weights:\n";
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << "Enter the target sum: ";
    cin >> m;

  
    sort(w.begin(), w.end());

    
    int r = 0;
    for (int i = 0; i < n; i++) r += w[i];

    cout << "Subsets with sum " << m << ":\n";
    sumOfSubsets(0, 0, r);

    return 0;
}
