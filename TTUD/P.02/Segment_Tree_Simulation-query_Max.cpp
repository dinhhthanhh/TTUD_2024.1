/*Given a sequence of positive integers a1, a2, . . ., an. Perform a sequence of actions of following types:
update  i  v : assign ai = v
get-max  i  j : return the maximum value of the subsequence ai, ai+1, . . ., aj

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;  // Nhập số lượng phần tử
    vector<int> a(n);  // Khởi tạo mảng để lưu các số

    // Nhập các phần tử của mảng
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;  // Nhập số lượng hành động

    // Dọn dẹp bộ nhớ đệm
    cin.ignore();  // Để bỏ qua ký tự newline còn sót lại sau khi nhập số m

    queue<string> actions;  // Khởi tạo hàng đợi để lưu các hành động

    // Thực hiện các hành động
    string line;
    while (getline(cin, line)) {
        if (line.empty()) {  // Kiểm tra nếu dòng trống
            break;  // Dừng nhập
        }
        actions.push(line);  // Lưu hành động vào hàng đợi
    }

    // Xử lý các hành động từ hàng đợi
    while (!actions.empty()) {
        string action = actions.front();
        actions.pop();  // Lấy hành động ra khỏi hàng đợi

        stringstream ss(action);
        string cmd;
        ss >> cmd;

        if (cmd == "get-max") {
            int i, j;
            ss >> i >> j;
            int maxVal = *max_element(a.begin() + (i - 1), a.begin() + j);  // Tìm giá trị lớn nhất từ a[i] đến a[j]
            cout << maxVal << endl;  // In kết quả
        } else if (cmd == "update") {
            int idx, v;
            ss >> idx >> v;
            a[idx - 1] = v;  // Cập nhật a[i] = v
        }
    }

    return 0;
}
