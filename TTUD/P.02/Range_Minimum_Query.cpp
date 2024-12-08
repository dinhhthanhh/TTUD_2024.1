/*Given a sequence of n integers a0,. . .,an-1. We denote rmq(i,j) the minimum element of the sequence ai, ai+1, . . .,aj.
Given m pairs (i1, j1),. . .,(im, jm), compute the sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
Input
Line 1: n (1 <=  n <= 10^6)
Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 10^6)
line 3: m (1  <= m <= 106)
Line k+3 (k=1, . . ., m): ik, jk  (0  <=  ik < jk < n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
const int LOG = 20; // log2(1000000) ~ 20

int sparseTable[MAXN][LOG];
int logTable[MAXN + 1];

// Hàm tiền xử lý Sparse Table
void buildSparseTable(const vector<int> &arr, int n) {
    // Bước 1: Xây dựng mảng logTable để tối ưu việc tính log
    logTable[1] = 0;
    for (int i = 2; i <= n; i++) {
        logTable[i] = logTable[i / 2] + 1;
    }

    // Bước 2: Xây dựng Sparse Table
    for (int i = 0; i < n; i++) {
        sparseTable[i][0] = arr[i]; // Mỗi phần tử tự là đoạn có độ dài 1.
    }

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Hàm truy vấn giá trị nhỏ nhất trong khoảng [L, R] trong O(1)
int query(int L, int R) {
    int j = logTable[R - L + 1];
    return min(sparseTable[L][j], sparseTable[R - (1 << j) + 1][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cin.tie(0);
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    buildSparseTable(arr, n);

    int m;
    cin >> m;

    int sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        sum += query(l, r); // Truy vấn giá trị nhỏ nhất từ l đến r
    }

    // Xuất ra tổng của các giá trị nhỏ nhất trong các truy vấn.
    cout << sum << endl;

    return 0;
}
