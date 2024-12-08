/*Given a undirected tree $G = (V, E)$ in which $V = \{1,…,N\}$ is the set of nodes. Each edge $(u,v) \in E$ has weight $w(u,v)$. The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on $G$.
Input
Line 1: positive integer $N$ ($1 \leq N \leq 10^5$)
Line $i + 1$ ($i = 1,…,N-1$): positive integers $u, v, w$ in which $w$ is the weight of edge $(u,v)$ (1 ≤ w ≤ 100)
Output
The weight of the longest path on the given tree
Example
Input
6 
1 3 3
 1 6 2 
2 6 5 
4 5 2
 4 6 1
Output
10*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXE = 200005;

int head[MAXN];          
int to[MAXE];            
int weight[MAXE];        
int nxt[MAXE];           
bool visited[MAXN];      
int maxDist, farthestNode;
int edgeCount = 0;

void addEdge(int u, int v, int w) {
    to[edgeCount] = v;             
    weight[edgeCount] = w;         
    nxt[edgeCount] = head[u];      
    head[u] = edgeCount++;         
}

void dfs(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }

    for (int i = head[node]; i != -1; i = nxt[i]) {
        int nextNode = to[i];
        int edgeWeight = weight[i];

        if (!visited[nextNode]) {
            dfs(nextNode, dist + edgeWeight);
        }
    }
}

int main() {
    int N;
    cin >> N;

    memset(head, -1, sizeof(head));

    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w); 
    }

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDist = 0;
    dfs(farthestNode, 0);

    cout << maxDist << endl;

    return 0;
}
