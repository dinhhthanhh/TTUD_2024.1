/*Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
Input
Each line contains a command (operration) of type 
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
3
2
5*/
#include <bits/stdc++.h>
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
