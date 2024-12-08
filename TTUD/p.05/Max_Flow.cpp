/*Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10^4, 1 <= M <= 10^6)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of ith arc
Output
  Write the value of the max-flow found
Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_N = 10000; 

int capacity[MAX_N][MAX_N]; 
int parent[MAX_N]; 

bool bfs(int s, int t, int n) {
    bool visited[MAX_N];
    memset(visited, false, sizeof(visited));
    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && capacity[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t) {
                    return true;
                }
            }
        }
    }
    return false;
}

int edmondsKarp(int s, int t, int n) {
    int max_flow = 0;
    
    while (bfs(s, t, n)) {
        int path_flow = INF;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= path_flow;
            capacity[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    
    return max_flow;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    memset(capacity, 0, sizeof(capacity)); 

    int s, t;
    cin >> s >> t; 

    for (int i = 0; i < M; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        capacity[u - 1][v - 1] += cap; 
    }

    cout << edmondsKarp(s - 1, t - 1, N) << endl;

    return 0;
}
