/*Given a set S of n integers a1, a2, ..., an. Perform a sequence of operations below:
min_greater_equal v: return a minimum element of S which is greater or equal to v, and return NULL if no such element exists
min_greater v: return a minimum element of S which is greater than v, and return NULL if no such element exists
insert v: insert v into S
remove v: remove v from S

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, ..., an (1 <= ai <= 100000)
Each subsequent line contains an operations described above.
The input is terminated with a line containing #

Output
Write the result of each operation min_greater or min_greater_equal.

Example
Input
5
3 2 4 5 9 
min_greater_equal 10
min_greater 7
min_greater_equal 7
min_greater_equal 4
insert 5
insert 5
min_greater 8
min_greater 1
min_greater_equal 6
min_greater_equal 8
#

Output 
NULL
9
9
4
9
2
9
9*/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  
    set<int> S;

    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        S.insert(ai);
    }

    string command;
    while (cin >> command) {
        if (command == "#") break; 

        if (command == "min_greater_equal") {
            int v;
            cin >> v;
            auto it = S.lower_bound(v); 
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (command == "min_greater") {
            int v;
            cin >> v;
            auto it = S.upper_bound(v);
            if (it != S.end()) {
                cout << *it << endl;
            } else {
                cout << "NULL" << endl;
            }
        } else if (command == "insert") {
            int v;
            cin >> v;
            S.insert(v);
        } else if (command == "remove") {
            int v;
            cin >> v;
            S.erase(v); 
        }
    }

    return 0;
}
