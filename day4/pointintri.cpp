// basic using area 
// #include <iostream>
// #include<math.h>
// using namespace std;

// double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
//     return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
// }

// bool isPointInsideTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
//     double A = triangleArea(x1, y1, x2, y2, x3, y3);
//     double A1 = triangleArea(x, y, x2, y2, x3, y3);
//     double A2 = triangleArea(x1, y1, x, y, x3, y3);
//     double A3 = triangleArea(x1, y1, x2, y2, x, y);
//     return (A == A1 + A2 + A3);
// }

// int main() {
//     double x1, y1, x2, y2, x3, y3, x, y;
//     cout << "Enter the coordinates of the first vertex (x1, y1): ";
//     cin >> x1 >> y1;
//     cout << "Enter the coordinates of the second vertex (x2, y2): ";
//     cin >> x2 >> y2;
//     cout << "Enter the coordinates of the third vertex (x3, y3): ";
//     cin >> x3 >> y3;
//     cout << "Enter the point to check (x, y): ";
//     cin >> x >> y;

//     if (isPointInsideTriangle(x1, y1, x2, y2, x3, y3, x, y))
//         cout << "The point lies INSIDE the triangle.\n";
//     else
//         cout << "The point lies OUTSIDE the triangle.\n";

//     return 0;
// }

// using the cross product --

#include <iostream>
using namespace std;

double crossProduct(double x1, double y1, double x2, double y2, double x, double y) {
    return (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
}

bool isPointInsideTriangle(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y) {
    double cross1 = crossProduct(x1, y1, x2, y2, x, y);
    double cross2 = crossProduct(x2, y2, x3, y3, x, y);
    double cross3 = crossProduct(x3, y3, x1, y1, x, y);
    return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) || (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
}

int main() {
    double x1, y1, x2, y2, x3, y3, x, y;
    cout << "Enter the coordinates of the first vertex (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second vertex (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter the coordinates of the third vertex (x3, y3): ";
    cin >> x3 >> y3;
    cout << "Enter the point to check (x, y): ";
    cin >> x >> y;

    if (isPointInsideTriangle(x1, y1, x2, y2, x3, y3, x, y))
        cout << "The point lies INSIDE the triangle.\n";
    else
        cout << "The point lies OUTSIDE the triangle.\n";

    return 0;
}

