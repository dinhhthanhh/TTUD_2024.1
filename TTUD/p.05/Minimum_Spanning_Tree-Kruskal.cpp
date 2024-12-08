/*Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
Input
Line 1: N and M (1≤N,M≤10^5) in which NN is the number of nodes and MM is the number of edges.
Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
Output
Write the weight of the minimum spanning tree found.
Example
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int u, v;
    int w;
};

const int MAXN = 1e5 + 5; // Set this based on problem constraints, e.g., 10^5 if n <= 10^5
int n, m;
int parent[MAXN], sz[MAXN];
vector<edge> canh;

void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge e;
        e.u = x; e.v = y; e.w = w;
        canh.push_back(e);
    }
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal() {
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (int i = 0; i < m; i++) {
        if (mst.size() == n - 1) break;
        edge e = canh[i];
        if (Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() != n - 1) {
        cout << "Error" << endl;
    } else {
        cout << d << endl;
    }
}

int main() {
    input();
    make_set();
    kruskal();
}
