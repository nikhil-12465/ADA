#include <iostream>
#include <vector>
#include <cstdlib>
#include<cmath>
using namespace std;

void print(vector<float> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void print(vector<vector<float>> &a, int n) {
    cout << "Profit: ";
    for (int j = 0; j < n; j++) {
        cout << a[0][j] << "     ";
    }
    cout << endl;

    cout << "Weight: ";
    for (int j = 0; j < n; j++) {
        cout << a[1][j] << "     ";
    }
    cout << endl;

    cout << "p/w    :";
    for (int j = 0; j < n; j++) {
        cout << a[2][j] << "    ";
    }
    cout << endl;
}


void sorting_on_profit(vector<vector<float>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[0][j] < a[0][j + 1]) {
                swap(a[0][j], a[0][j + 1]);
                swap(a[1][j], a[1][j + 1]);
                swap(a[2][j], a[2][j + 1]);
            }
        }
    }
}


void sorting_on_weight(vector<vector<float>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[1][j] > a[1][j + 1]) {
                swap(a[0][j], a[0][j + 1]);
                swap(a[1][j], a[1][j + 1]);
                swap(a[2][j], a[2][j + 1]);
            }
        }
    }
}


void sorting_on_profit_per_weight(vector<vector<float>> &a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[2][j] < a[2][j + 1]) {
                swap(a[0][j], a[0][j + 1]);
                swap(a[1][j], a[1][j + 1]);
                swap(a[2][j], a[2][j + 1]);
            }
        }
    }
}


vector<float> find_list(vector<vector<float>> &a, int n, int c) {
    vector<float> x(n, 0);
    for (int j = 0; j < n; j++) {
        if (a[1][j] <= c) {
            x[j] = 1;
            c -= a[1][j];
        } else {
            x[j] = (c * 1.0) / a[1][j];
            break;
        }
    }
    return x;
}


float calculate_profit(vector<vector<float>> &b, vector<float> &x, int n) {
    float total_profit = 0;
    for (int i = 0; i < n; i++) {
        total_profit += x[i] * b[0][i];
    }
    return total_profit;
}


float calculate_profit1(vector<vector<float>> &b, vector<float> &x, int n) {
    float total_profit = 0;
    for (int i = 0; i < n; i++) {
        total_profit += x[i] * b[0][i];
    }
    return total_profit;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<vector<float>> a(3, vector<float>(n));

    
    for (int j = 0; j < n; j++) {
        a[0][j] = rand() % 50 + 1;  
        a[1][j] = rand() % 20 + 1; 
        a[2][j] = round((a[0][j] / a[1][j]) * 10) / 10.0;
 
    }

    vector<vector<float>> b = a, d = a, f = a;

    cout << "Original Data:" << endl;
    print(a, n);

    int c;
    cout << "Enter total capacity of the knapsack: ";
    cin >> c;

    
    sorting_on_profit(a, n);
    cout << "After Sorting on Profit:" << endl;
    print(a, n);

    vector<float> list_profit = find_list(a, n, c);
    cout << "Selected items (profit sorting): ";
    print(list_profit);

    float profit_gain = calculate_profit(b, list_profit, n);
    cout << "Profit by profit order: " << profit_gain << endl;

   
    sorting_on_weight(d, n);
    cout << "After Sorting on Weight:" << endl;
    print(d, n);

    vector<float> list_weight = find_list(d, n, c);
    cout << "Selected items (weight sorting): ";
    print(list_weight);

    float profit_by_weight_order = calculate_profit(b, list_weight, n);
    cout << "Profit by weight order: " << profit_by_weight_order << endl;


    sorting_on_profit_per_weight(f, n);
    cout << "After Sorting on Profit per Unit Weight:" << endl;
    print(f, n);

    vector<float> list_per_weight = find_list(f, n, c);
    cout << "Selected items (profit per weight sorting): ";
    print(list_per_weight);

    float profit_by_profit_per_weight_order = calculate_profit1(f, list_per_weight, n);
    cout << "Profit by profit per unit weight order: " << profit_by_profit_per_weight_order << endl;
    cout << "Profit by weight order: " << profit_by_weight_order << endl;
    cout << "Profit by profit order: " << profit_gain << endl;

    return 0;
}
