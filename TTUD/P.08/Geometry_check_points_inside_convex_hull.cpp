/*Given a sequence of points P1, P2, ...,  Pn. Given K point T1, T2, ..., Tk. Write a program to check if P1, P2, . . ., Pn form a convex hull C and the points Ti (i = 1,...,K) is inside the convex hull C.

Input
Line 1: contains a positive integer n (3 <= n <= 10000)
Line i+1 (i = 1, 2, ..., n): contains 2 integer xi, yi which are x,y-coordinate of point Pi (-1000 <= xi,yi <= 1000)
Line n+2: contains apositive integer K (1 <= K <= 100000)
Line k+n+2 (k= 1, 2, ..., K): contains 2 integer xk, yk which are x,y-coordiate of Tk (-1000 <= xk, yk <= 1000)

Output
Line k writes 1 if P1, ..., Pn forms a convex hull and point Tk is  inside that convex hull, and writes 0, otherwise. 

Example
Input 
4
5 6
3 7
2 5
5 3
4
8 7
4 5
3 7
0 0 

Output 
0
1
1
0*/
#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Cross product of vector AB and vector AC
int cross(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Function to find the convex hull using the Monotone Chain algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    sort(points.begin(), points.end());

    vector<Point> hull;
    // Lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    // Upper hull
    int t = hull.size() + 1;
    for (int i = n - 1; i >= 0; --i) {
        while (hull.size() >= t && cross(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
    hull.pop_back(); // Remove redundant last point
    return hull;
}

// Function to check if a point is inside the convex polygon
bool isInsideConvexPolygon(const vector<Point>& hull, const Point& p) {
    int n = hull.size();
    for (int i = 0; i < n; ++i) {
        if (cross(hull[i], hull[(i + 1) % n], p) < 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // Calculate the convex hull
    vector<Point> hull = convexHull(points);

    // Check if the given points form a convex hull
    if (hull.size() != n) {
        cout << "0" << endl; // Not a convex hull
        return 0;
    }

    int k;
    cin >> k;
    vector<int> res(k);
    for (int i = 0; i < k; ++i) {
        Point testPoint;
        cin >> testPoint.x >> testPoint.y;
        if (isInsideConvexPolygon(hull, testPoint))
            res[i] = 1;
        else
            res[i] = 0;
    }
    
    for(int i = 0; i < k; i++){
        cout << res[i] << endl;
    }
    return 0;
}
