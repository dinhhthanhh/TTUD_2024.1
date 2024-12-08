/*Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

Input
Line 1 contains a positive integer n (2 <= n <= 10^5)
Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)
Output
Write the value max{f(1), . . , f(n}.

Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
long long ans = 0;  // Use long long for large sums
int n;

struct Edge {
    int to, next;
    long long weight;
} edges[MAXN * 2];  // Double for undirected edges

int head[MAXN], cnt = 0;
long long subtreeSize[MAXN];  // Size of subtree rooted at each node
long long sumDist[MAXN];      // Sum of distances to all nodes in subtree

void init() {
    cnt = 0;
    for(int i = 0; i <= n; i++) {
        head[i] = 0;
        subtreeSize[i] = 0;
        sumDist[i] = 0;
    }
}

void addEdge(int u, int v, long long w) {
    cnt++;
    edges[cnt].to = v;
    edges[cnt].weight = w;
    edges[cnt].next = head[u];
    head[u] = cnt;
}

// First DFS to calculate subtree sizes and initial distances
void dfs1(int u, int parent) {
    subtreeSize[u] = 1;
    
    for(int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if(v != parent) {
            dfs1(v, u);
            subtreeSize[u] += subtreeSize[v];
            sumDist[u] += sumDist[v] + subtreeSize[v] * edges[i].weight;
        }
    }
}

// Second DFS to calculate final answer
void dfs2(int u, int parent, long long parentContribution) {
    // Calculate total sum for current node
    long long totalSum = sumDist[u] + parentContribution;
    ans = max(ans, totalSum);
    
    // Calculate contribution for children
    for(int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if(v != parent) {
            long long newParentContribution = totalSum - (sumDist[v] + subtreeSize[v] * edges[i].weight)
                                           + (n - subtreeSize[v]) * edges[i].weight;
            dfs2(v, u, newParentContribution);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    init();
    
    // Read edges
    for(int i = 1; i < n; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    
    // Run DFS twice
    dfs1(1, 0);  // Calculate subtree sizes and initial distances
    dfs2(1, 0, 0);  // Calculate final answer
    
    cout << ans << endl;
    
    return 0;
}
