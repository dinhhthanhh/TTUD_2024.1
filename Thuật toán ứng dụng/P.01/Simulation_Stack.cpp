#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    vector<string> results; 
    string command;
    
    while (true) {
        cin >> command;
        if (command == "PUSH") {
            int value;
            cin >> value;
            s.push(value);
        } 
        else if (command == "POP") {
            if (!s.empty()) {
                results.push_back(to_string(s.top())); 
                s.pop();
            } else {
                results.push_back("NULL");
            }
        } 
        else if (command == "#") {
            break; // Gặp dấu # thì dừng vòng lặp
        }
    }
    
    // In ra tất cả kết quả sau khi gặp #
    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}
