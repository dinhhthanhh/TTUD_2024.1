#include <iostream>
#include <string>
#include <algorithm>

using namespace std; // Sử dụng namespace std

// Hàm tính tổng hai chuỗi số lớn
string addLargeNumbers(const string& num1, const string& num2) {
    string result = "";
    
    // Đảo ngược hai chuỗi để bắt đầu cộng từ bên phải sang trái
    string n1 = num1, n2 = num2;
    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    // Tìm độ dài lớn hơn giữa hai chuỗi
    int length = max(n1.size(), n2.size());

    // Thêm các số 0 vào chuỗi ngắn hơn để có độ dài bằng nhau
    n1.append(length - n1.size(), '0');
    n2.append(length - n2.size(), '0');

    int carry = 0; // Biến lưu giữ phần dư khi cộng

    // Thực hiện cộng từng chữ số
    for (int i = 0; i < length; ++i) {
        int sum = (n1[i] - '0') + (n2[i] - '0') + carry;
        result.push_back(sum % 10 + '0'); // Lưu phần kết quả của phép cộng
        carry = sum / 10; // Lưu phần dư (nếu có)
    }

    // Nếu còn dư (carry) sau phép cộng cuối cùng
    if (carry > 0) {
        result.push_back(carry + '0');
    }

    // Đảo ngược kết quả lại để trả về đúng thứ tự
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string num1, num2;

    cin >> num1;

    cin >> num2;

    // Tính tổng và in ra kết quả
    string sum = addLargeNumbers(num1, num2);
    cout << sum << endl;

    return 0;
}
