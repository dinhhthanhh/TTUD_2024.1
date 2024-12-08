/*Given a directed graph G=(V,E) where V={1,. . ., N} is the number of nodes and the set E has M arcs. Compute number of strongly connected components of G
Input
Line 1: two positive integers N and M (1 <= N <= 10^5, 1 <= M <= 10^6)
Line i+1 (i=1,. . ., M\): contains two positive integers u and v which are endpoints of ith arc
Output
Write the number of strongly connected components of G
Example
Input
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Output
3*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000000;

int N, M;
int adj[MAX_N + 1][100];
int adjT[MAX_N + 1][100]; 
int adjCount[MAX_N + 1]; 
int adjTCount[MAX_N + 1];
bool visited[MAX_N + 1];
stack<int> Stack;

void addEdge(int u, int v) {
    adj[u][adjCount[u]++] = v;
}

void addEdgeTransposed(int u, int v) {
    adjT[u][adjTCount[u]++] = v;
}

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < adjCount[u]; ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    Stack.push(u);
}

void dfsTranspose(int u) {
    visited[u] = true;
    for (int i = 0; i < adjTCount[u]; ++i) {
        int v = adjT[u][i];
        if (!visited[v]) {
            dfsTranspose(v);
        }
    }
}

int findSCCs() {
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int u = 1; u <= N; ++u) {
        for (int i = 0; i < adjCount[u]; ++i) {
            int v = adj[u][i];
            addEdgeTransposed(v, u);
        }
    }

    memset(visited, false, sizeof(visited));
    int sccCount = 0;
    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();
        if (!visited[u]) {
            dfsTranspose(u);
            ++sccCount;
        }
    }

    return sccCount;
}

int main() {
    cin >> N >> M;

    memset(adjCount, 0, sizeof(adjCount));
    memset(adjTCount, 0, sizeof(adjTCount));

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }

    cout << findSCCs() << endl;
    return 0;
}
