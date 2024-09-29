#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    set<int> s;
    vector<string> results;  // To store results for output after processing all input
    string line;

    // Read the number of initial elements
    getline(cin, line);
    int n = stoi(line);
    
    // Read the initial elements
    getline(cin, line);
    istringstream iss(line);
    int value;
    while (iss >> value) {
        s.insert(value);
    }
    
    // Process operations
    while (getline(cin, line)) {
        if (line == "#") break;  // Stop processing when encountering '#'
        
        istringstream iss(line);
        string command;
        iss >> command;
        
        if (command == "min_greater_equal") {
            int v;
            iss >> v;
            auto it = s.lower_bound(v);
            if (it != s.end()) {
                results.push_back(to_string(*it));
            } else {
                results.push_back("NULL");
            }
        } else if (command == "min_greater") {
            int v;
            iss >> v;
            auto it = s.upper_bound(v);
            if (it != s.end()) {
                results.push_back(to_string(*it));
            } else {
                results.push_back("NULL");
            }
        } else if (command == "insert") {
            int v;
            iss >> v;
            s.insert(v);
        } else if (command == "remove") {
            int v;
            iss >> v;
            s.erase(v);
        }
    }

    // Print all results at the end
    for (const string& result : results) {
        cout << result << endl;
    }
    
    return 0;
}
