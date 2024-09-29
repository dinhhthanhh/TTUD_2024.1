#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Hàm kiểm tra xem một ký tự có phải là ký tự từ (a-z, A-Z, 0-9) hay không
bool isWordChar(char c) {
    return isalnum(c);  // Kiểm tra xem ký tự có phải là chữ số hoặc ký tự chữ hay không
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<string, int> wordCount;
    string line;

    // Đọc đầu vào cho đến khi gặp dòng trống (Enter mà không nhập gì)
    while (getline(cin, line)) {
        if (line.empty()) {  // Kiểm tra nếu dòng trống
            break;  // Dừng nhập
        }
        
        stringstream ss(line);
        string word;
        
        // Trích xuất các từ từ dòng
        while (ss >> word) {
            string cleanWord;

            // Xây dựng từ chỉ từ các ký tự hợp lệ (alphanumeric)
            for (char c : word) {
                if (isWordChar(c)) {
                    cleanWord += c;
                } else if (!cleanWord.empty()) {
                    wordCount[cleanWord]++;  // Tăng số đếm cho từ
                    cleanWord.clear();
                }
            }

            // Nếu từ còn lại không rỗng, thêm vào đếm
            if (!cleanWord.empty()) {
                wordCount[cleanWord]++;
            }
        }
    }

    // In ra các từ và số lần xuất hiện theo thứ tự từ điển
    for (const auto& entry : wordCount) {
        cout << entry.first << " " << entry.second << endl;
    }
    
    return 0;
}
