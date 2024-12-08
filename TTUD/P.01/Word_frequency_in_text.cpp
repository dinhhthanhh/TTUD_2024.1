/*Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

Example
Input
abc  def abc 
abc abcd def 

Output 
abc 3
abcd 1
def 2*/
#include <bits/stdc++.h>

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
