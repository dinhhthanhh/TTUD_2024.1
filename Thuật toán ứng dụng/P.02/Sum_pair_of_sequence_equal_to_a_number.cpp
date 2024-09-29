#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    unordered_set<int> setA;
    for (int i = 0; i < n; ++i) {
        setA.insert(a[i]);
    }
    
    int Q = 0;
    for (int i = 0; i < n; ++i) {
        int needed = M - a[i];
        if (setA.find(needed) != setA.end() && needed != a[i] && needed > a[i]) {
            Q++;
        }
    }
    
    cout << Q << endl;
    
    return 0;
}
