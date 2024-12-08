/*There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
Input
Line 1: a positive integer n (1 <= n <= 20)
Linr i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21; // Giới hạn n <= 20
const int INF = INT_MAX;

int n;
int dist[MAXN][MAXN];
int bestPath[MAXN];
int currentPath[MAXN];
bool visited[MAXN];
int bestCost;

void branchAndBound(int pos, int currentCost) {
    if (pos == n) {
        // Thêm chi phí quay về thành phố 1
        int totalCost = currentCost + dist[currentPath[pos-1]-1][0];
        if (totalCost < bestCost) {
            bestCost = totalCost;
            for(int i = 0; i < n; i++) {
                bestPath[i] = currentPath[i];
            }
        }
        return;
    }
    
    for(int i = 1; i < n; i++) {  // bắt đầu từ 1 vì 0 là thành phố xuất phát
        if (!visited[i]) {
            int newCost = currentCost + dist[currentPath[pos-1]-1][i];
            if (newCost < bestCost) {  // Cắt nhánh
                visited[i] = true;
                currentPath[pos] = i + 1;
                branchAndBound(pos + 1, newCost);
                visited[i] = false;
            }
        }
    }
}

void solveTSP() {
    // Khởi tạo các biến
    memset(visited, false, sizeof(visited));
    bestCost = INF;
    
    // Bắt đầu từ thành phố 1
    visited[0] = true;
    currentPath[0] = 1;
    branchAndBound(1, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Đọc input
    cin >> n;
    
    // Đọc ma trận khoảng cách
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    
    // Giải bài toán
    solveTSP();
    
    // In kết quả - chỉ in tổng chi phí đường đi tối ưu
    cout << bestCost << "\n";
    
    return 0;
}
