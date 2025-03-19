#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};


int findSide(Point A, Point B, Point P) {          // it tells the point  p is which side of the line made by the point A and B
    int val = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    return (val > 0) ? 1 : ((val < 0) ? -1 : 0); 
}


int distance(Point A, Point B, Point P) {           // function that find the distance of the point p from AB line 
    return abs((B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x));
}


void findHull(vector<Point> &S, Point P, Point Q, vector<Point> &hull) {
    if (S.empty()) return;

 
    int maxDist = 0;
    Point C;
    int index = -1;
 
    for (int i = 0; i < S.size(); i++) {  
        int d = distance(P, Q, S[i]);
        if (d > maxDist) {
            maxDist = d;
            C = S[i];
            index = i;
        }
    }

   
    hull.push_back(C);

    
    vector<Point> S1, S2;
    for (int i = 0; i < S.size(); i++) {
        if (i == index) continue;
        if (findSide(P, C, S[i]) == 1) S1.push_back(S[i]); // Right of PC
        else if (findSide(C, Q, S[i]) == 1) S2.push_back(S[i]); // Right of CQ
    }

  
    findHull(S1, P, C, hull);
    findHull(S2, C, Q, hull);
}


vector<Point> quickHull(vector<Point> &points) {
    vector<Point> hull;
    if (points.size() < 3) return hull;

    // Find leftmost and rightmost points A and B
    Point A = points[0], B = points[0];
    for (auto p : points) {
        if (p.x < A.x) A = p;
        if (p.x > B.x) B = p;
    }

 
    vector<Point> S1, S2;
    for (auto p : points) {
        int side = findSide(A, B, p);
        if (side == 1) S1.push_back(p);
        else if (side == -1) S2.push_back(p);
    }

  
    hull.push_back(A);
    hull.push_back(B);

  
    findHull(S1, A, B, hull);
    findHull(S2, B, A, hull);

    return hull;
}


int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the points (x y): \n";
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    vector<Point> hull = quickHull(points);

    cout << "Convex Hull Points:\n";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ")\n";

    return 0;
}
