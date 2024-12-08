/*Given a sequence of n positive integers a1, a2, ..., an. Perform a sequence of queries of type:
next k: return the smallest element of the given sequence that is greater than k. Return -1 if no such element is found.

Input
Line 1: contains n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 1000000)
Each subsequent line contains a query of format above. The input is terminated with a line containing #

Output
Write in each line the result of the corresponding query.
 
Example
Input
5
4 8 2 3 7 
next 2
next 7
next 9
next 6
next 1
#

Output 
3
8
-1
7
2*/
#include <bits/stdc++.h>

using namespace std;

// Hàm tìm phần tử nhỏ nhất lớn hơn X sử dụng tìm kiếm nhị phân
int upperBound(const vector<int>& arr, int x) {
    auto it = upper_bound(arr.begin(), arr.end(), x);  // Tìm upper bound
    if (it == arr.end()) {
        return -1;  // Không tìm thấy phần tử nào lớn hơn x
    }
    return *it;  // Trả về phần tử nhỏ nhất lớn hơn x
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    // Đọc chuỗi số
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Sắp xếp mảng để có thể tìm upper bound dễ dàng
    sort(arr.begin(), arr.end());
    
    queue<string> queries;  // Hàng đợi để lưu các truy vấn
    string query;
    
    // Đọc tất cả các truy vấn cho đến khi gặp dấu #
    while (cin >> query && query != "#") {
        queries.push(query);  // Thêm truy vấn vào hàng đợi
        if (query == "next") {
            int x;
            cin >> x;  // Đọc giá trị của truy vấn
            queries.push(to_string(x));  // Thêm giá trị của truy vấn vào hàng đợi
        }
    }
    
    // Xử lý từng truy vấn trong hàng đợi
    while (!queries.empty()) {
        string currentQuery = queries.front();
        queries.pop();
        
        if (currentQuery == "next") {
            int x = stoi(queries.front());  // Lấy giá trị tiếp theo trong hàng đợi
            queries.pop();
            cout << upperBound(arr, x) << endl;  // In ra kết quả cho truy vấn "next X"
        }
    }
    
    return 0;
}
