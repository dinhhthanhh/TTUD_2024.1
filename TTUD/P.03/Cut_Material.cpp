/*Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1*/
#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra khả năng cắt hình chữ nhật
bool canFit(int H, int W, vector<pair<int, int>> &rectangles, vector<bool> &used) {
    // Nếu không còn hình nào cần xếp
    bool allUsed = true;
    for (bool u : used) {
        if (!u) {
            allUsed = false;
            break;
        }
    }
    if (allUsed) return true;

    // Thử đặt từng hình chữ nhật con chưa được sử dụng
    for (int i = 0; i < rectangles.size(); i++) {
        if (used[i]) continue;

        int h = rectangles[i].first;
        int w = rectangles[i].second;

        // Thử đặt hình chữ nhật vào vị trí còn trống (không xoay)
        if (h <= H && w <= W) {
            used[i] = true;
            if (canFit(H - h, W, rectangles, used) || canFit(H, W - w, rectangles, used)) {
                return true;
            }
            used[i] = false;
        }

        // Thử đặt hình chữ nhật vào vị trí còn trống (xoay)
        if (w <= H && h <= W) {
            used[i] = true;
            if (canFit(H - w, W, rectangles, used) || canFit(H, W - h, rectangles, used)) {
                return true;
            }
            used[i] = false;
        }
    }

    // Nếu không thể xếp được
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int H, W;
    cin >> H >> W;  // Nhập chiều cao và chiều rộng của hình chữ nhật lớn

    int n;
    cin >> n;  // Nhập số lượng hình chữ nhật con

    vector<pair<int, int>> rectangles(n);
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;  // Nhập chiều cao và chiều rộng của mỗi hình chữ nhật con
        rectangles[i] = {h, w};
    }

    // Biến lưu trữ trạng thái đã sử dụng hình chữ nhật con hay chưa
    vector<bool> used(n, false);

    // Kiểm tra nếu có thể xếp được các hình chữ nhật con vào hình lớn
    if (canFit(H, W, rectangles, used)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

