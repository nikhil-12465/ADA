#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int a, b, c;
    int p = -1;
};

void heapify(vector<edge> &myarr, int size, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < size && myarr[left].c < myarr[smallest].c) {
        smallest = left;
    }
    if (right < size && myarr[right].c < myarr[smallest].c) {
        smallest = right;
    }

    if (smallest != i) {
        swap(myarr[i], myarr[smallest]);
        heapify(myarr, size, smallest);
    }
}

void buildminheap(vector<edge> &myarr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(myarr, size, i);
    }
}

void deletion(vector<edge> &myarr) {
    if (myarr.empty()) return;

    myarr[0] = myarr.back();
    myarr.pop_back();
    heapify(myarr, myarr.size(), 0);
}

int find(vector<edge> &myarr, int a) {
    while (myarr[a].p >= 0) {
        a = myarr[a].p;
    }
    return a;
}

void addition(vector<edge> &myarr, int a, int b) {
    int rootA = find(myarr, a);
    int rootB = find(myarr, b);

    if (rootA != rootB) {
        myarr[rootB].p = rootA;
    }
}

pair<int, int> kruskal(vector<edge> &myarr, int n, vector<vector<int>> &t) {
    int size = myarr.size();

    buildminheap(myarr, size);

    vector<edge> edges(n + 1, {-1, -1, -1, -1});
    int mcost = 0;
    int i = 0;

    while (i < n - 1 && !myarr.empty()) {
        edge e = myarr[0];
        deletion(myarr);

        int j = find(edges, e.a);
        int k = find(edges, e.b);

        if (j != k) {
            addition(edges, j, k);
            t[i][0] = e.a;
            t[i][1] = e.b;
            mcost += e.c;
            i++;
        }
    }

    return make_pair(i, mcost);  
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<edge> myarr = {
        {1, 2, 5}, {1, 3, 6}, {2, 3, 2}, {2, 5, 2},
        {3, 4, 5}, {4, 2, 3}, {4, 5, 1}
    };

    vector<vector<int>> t(n - 1, vector<int>(2));

   
    pair<int, int> result = kruskal(myarr, n, t);
    int i = result.first;
    int mcost = result.second;

    if (i != n - 1) {
        cout << "The graph is disconnected. MST cannot be formed." << endl;
    } else {
        cout << "Minimum Cost: " << mcost << endl;
        cout << "Edges in MST:\n";
        for (int i = 0; i < n - 1; i++) {
            cout << t[i][0] << " - " << t[i][1] << endl;
        }
    }

    return 0;
}
