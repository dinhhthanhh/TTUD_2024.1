#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>

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
