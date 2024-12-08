/*A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate i and has following informationai : amount of goodsti : pickup time duration for taking goods
The route of the truck is a sequence of stations x1 < x2 < . . . < xk (1 ≤ xj ≤ N, j = 1,…, k). Due to technical constraints, the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.
Input
Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
Line 2: a1
,. . ., a
N
 (1 <= a
i
 <= 10)
Line 3: t
1
, . . ., t
N
 (1 <=  t
i
 <= 10)
Output
Write the total amount of goods that the truck picks up in the route.
Example
Input
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2

Output
24*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000;
const int MAX_T = 100;

int N, T, D;
int a[MAX_N], t[MAX_N];
int dp[MAX_N][MAX_T + 1]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> T >> D;

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < N; ++i) {
        fill(dp[i], dp[i] + T + 1, -1);
    }

    for (int i = 0; i < N; ++i) {
        if (t[i] <= T) {
            dp[i][t[i]] = a[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int timeUsed = 0; timeUsed <= T; ++timeUsed) {
            if (dp[i][timeUsed] == -1) continue;
            
            for (int k = i + 1; k < N && k - i <= D; ++k) {
                if (timeUsed + t[k] <= T) {
                    dp[k][timeUsed + t[k]] = max(dp[k][timeUsed + t[k]], dp[i][timeUsed] + a[k]);
                }
            }
        }
    }

    int maxGoods = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= T; ++j) {
            maxGoods = max(maxGoods, dp[i][j]);
        }
    }

    cout << maxGoods << endl;

    return 0;
}
