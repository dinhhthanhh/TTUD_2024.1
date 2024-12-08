/*Given a sequence of positive integers a = a1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). 
The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input
Line 1: contains two positive integers n and Q (1 <= n <= 10^6, 1 <= Q <= 100000)
Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).
Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4 
Output
5*/
#include <bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 5;
int res = 0, s=0;
    int n, Q;
    int a[N];
    
void input(){
    cin >> n >>Q;
    for(int i = 1; i<=n;i++){
        cin >> a[i];
    }
}

void solve(){
    int L = 1;
    for(int R = 1; R<=n; R++){
        s+=a[R];
        while(s>Q){
            s -=a[L]; L++;
        }
        res = max(res, R - L + 1);
    }
    cout << res;
}

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    solve();
    return 0;
}
