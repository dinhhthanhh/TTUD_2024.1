/*There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
 Line i+1 (i=1,2,…,2n+1) contains the (i−1)
th
 line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25*/
#include<bits/stdc++.h>

using namespace std;

const int N = 50;
const int oo = 1e9;
int n, K, cmin = oo;
int C[2*N + 1][2*N + 1], x[2*N + 1], xOpt[2*N+1];
int fCur = 0, load = 0, fOpt = oo;
bool visited[2*N+1];

bool check(int v, int k){
    if(visited[v]) return false;

    if(v>n){
        if(!visited[v - n]) return false;
    }else{
        if(load == K) return false;
    }
    return true;
}

void updateSol(){
    if(fCur + C[x[2*n]][0] < fOpt){
        fOpt = fCur + C[x[2*n]][0];
        for(int i = 0; i < 2*n; i++){
            xOpt[i] = x[i];
        }
    }
}

void TRY(int k){
    for(int v = 1; v <= 2*n; v++){
        if(check(v,n)){
            x[k] = v;
            visited[v] = true;
            fCur += C[x[k-1]][v];
            load += (v > n? -1:1);
            if(k==2*n) updateSol();
            else{
                if(fCur + (2*n + 1 - k) * cmin < fOpt){
                    TRY(k+1);
                }
            }
            visited[v] = false;
            fCur -= C[x[k-1]][v];
            load -= (v > n ? -1:1);
        }
    }
}

void input(){
    cin >> n >> K;
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >>  C[i][j];
            if(i!=j) cmin = min(cmin,C[i][j]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    x[0] = 0; visited[0] = true;
    TRY(1);
    cout << fOpt <<endl;
    return 0;
}

/*
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 11;
int n, k;
int c[2 * MAX_N + 1][2 * MAX_N + 1];
int dp[1 << (2 * MAX_N + 1)][2 * MAX_N + 1];

int solve(int mask, int pos, int passengers) {
    if (mask == (1 << (2 * n + 1)) - 1) {
        return c[pos][0]; // Return to start
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int result = INT_MAX;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!(mask & (1 << i))) {
            if (i <= n && passengers < k) { // Pick up passenger
                result = min(result, c[pos][i] + solve(mask | (1 << i), i, passengers + 1));
            } else if (i > n && (mask & (1 << (i - n)))) { // Drop off passenger
                result = min(result, c[pos][i] + solve(mask | (1 << i), i, passengers - 1));
            }
        }
    }

    dp[mask][pos] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= 2 * n; ++j) {
            cin >> c[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), -1);

    cout << solve(1, 0, 0) << endl;

    return 0;
}*/
