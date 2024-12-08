/*Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
Input
Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
Output
Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

Example
Input
6 6
10 2
30 1
50 1
20 3
30 1
20 1
1 2
1 3
1 5
2 4
2 5
4 6
Output
30

Giải thích: 
-Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
-Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
Tổng cộng mất 10 + 20 = 30 đồng*/
#include <bits/stdc++.h>

using namespace std;

struct State {
    int city; // Thành phố hiện tại
    int cost; // Chi phí để đến thành phố này
    
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> C(n + 1), D(n + 1); // C: giá vé, D: số thành phố tối đa buýt có thể đi
    vector<vector<int>> adj(n + 1); // adj: danh sách kề các con đường
    
    for (int i = 1; i <= n; ++i) {
        cin >> C[i] >> D[i]; // Nhập giá vé và số thành phố tối đa mà buýt có thể đi
    }
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Đường kết nối giữa thành phố u và v
    }
    
    // Mảng lưu chi phí nhỏ nhất khi đến mỗi thành phố
    vector<int> minCost(n + 1, INT_MAX);
    minCost[1] = 0; // Chi phí khởi điểm từ thành phố 1 là 0
    
    // Hàng đợi ưu tiên để tìm kiếm chi phí nhỏ nhất
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({1, 0}); // Bắt đầu từ thành phố 1 với chi phí 0
    
    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();
        
        int currentCity = current.city;
        int currentCost = current.cost;
        
        // Nếu đã đến thành phố n, in ra chi phí và kết thúc
        if (currentCity == n) {
            cout << currentCost << endl;
            return 0;
        }
        
        // Nếu chi phí hiện tại lớn hơn chi phí nhỏ nhất thì bỏ qua
        if (currentCost > minCost[currentCity]) continue;
        
        // Bắt đầu hành trình từ thành phố hiện tại
        int busCost = C[currentCity];  // Chi phí lên buýt
        int maxDistance = D[currentCity];  // Số thành phố tối đa mà buýt có thể đi
        
        // Duyệt qua các thành phố có thể đi từ thành phố hiện tại
        queue<int> q;
        vector<int> distance(n + 1, INT_MAX); // Khoảng cách từ thành phố hiện tại
        q.push(currentCity);
        distance[currentCity] = 0;
        
        while (!q.empty()) {
            int city = q.front();
            q.pop();
            
            for (int nextCity : adj[city]) {
                if (distance[city] + 1 <= maxDistance && distance[nextCity] > distance[city] + 1) {
                    distance[nextCity] = distance[city] + 1;
                    q.push(nextCity);
                }
            }
        }
        
        // Cập nhật chi phí đến các thành phố có thể đến được
        for (int i = 1; i <= n; ++i) {
            if (distance[i] <= maxDistance) {
                int newCost = currentCost + busCost;
                if (newCost < minCost[i]) {
                    minCost[i] = newCost;
                    pq.push({i, newCost});
                }
            }
        }
    }
    
    // Nếu không tìm được đường đi đến thành phố n
    cout << -1 << endl;
    return 0;
}
