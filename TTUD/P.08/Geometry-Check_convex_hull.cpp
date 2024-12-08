/*Given a sequence of n points on the plane (each point has an integer coordinate) P1(x1, y1), P2(x2,y2), . . ., Pn(xn,yn). Write a program to check if the given points form a convex hull.

Input
Line 1: contains a positive integer T which is the number of test case (1 <= T <= 20)
Subsequent lines are testcase, each testcase has the folowwing format:
Line 1: contains a positive integer n (3 <= n <= 500)
Line i+1 (i = 1, 2, ..., n): contains 2 integers xi, yi (-1000 <= xi,yi <= 1000) 

Output
Line t (t = 1, 2, ..., T): contains 1 if the answer of the tth testcase is YES and contains 0, otherwise.


Example
Input 
2
5
5 6
2 5
3 7
5 3
8 7
4
2 5
5 3
8 7
3 7

Output 
0
1*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
}

bool isConvex(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) return false; 
    
    int initialOrientation = 0;
    for (int i = 0; i < n; ++i) {
        int cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cp != 0) {
            initialOrientation = cp;
            break;
        }
    }
    
    if (initialOrientation == 0) return false;

    for (int i = 0; i < n; ++i) {
        int cp = crossProduct(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (cp != 0 && (cp > 0) != (initialOrientation > 0)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int T;
    cin >> T;
    int res[20]; 
    
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<Point> points(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        
        if (isConvex(points)) {
            res[t] = 1;
        } else {
            res[t] = 0;
        }
    }

    for (int t = 0; t < T; ++t) {
        cout << res[t] << endl;
    }
    
    return 0;
}
