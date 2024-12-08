/*Given a table of n rows (1, 2, ..., n) and m columns (1, 2, ..., m). Each cell (i,j) has a non-negative integer a(i,j).
Perform a sequence of queries (r1, c1, r2, c2) which returns the sum of elements of the sub-table from row r1 to row r2 and from column c1 to column c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m).

Input
Line 1: contains n and m (1 <= n, m <= 1000)
Line i+1(i = 1, 2, ..., n): contains the elements on row i of the table 
Line n+2: contains a positive integer Q (1 <= Q <= 100000) which is the number of queries 
Line q+n+2 (q = 1, 2, ..., Q): contains r1, c1, r2, c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m)

Output
Write in each line the result of the corresponding query read from the input

Example
Input
3 4
1 1 0 1 
1 1 1 0 
0 1 0 0 
3
2 3 3 4
1 3 3 4
2 2 3 4

Output 
1
2
3*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)); // Ma trận a bắt đầu từ chỉ số 1
    vector<vector<int>> prefix_sum(n + 1, vector<int>(m + 1, 0)); // Ma trận tích lũy
    vector<int> results; // Lưu kết quả các truy vấn

    // Nhập bảng giá trị a
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    // Xây dựng mảng prefix_sum
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix_sum[i][j] = a[i][j] 
                             + prefix_sum[i-1][j] 
                             + prefix_sum[i][j-1] 
                             - prefix_sum[i-1][j-1];
        }
    }

    int Q;
    cin >> Q; // Số lượng truy vấn

    // Xử lý các truy vấn và lưu kết quả vào vector
    for (int q = 0; q < Q; ++q) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        // Tính tổng các phần tử trong vùng (r1, c1) đến (r2, c2)
        int result = prefix_sum[r2][c2] 
                   - prefix_sum[r1-1][c2] 
                   - prefix_sum[r2][c1-1] 
                   + prefix_sum[r1-1][c1-1];
        
        results.push_back(result); // Lưu kết quả vào vector
    }

    // Sau khi xử lý xong tất cả truy vấn, in ra kết quả
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
