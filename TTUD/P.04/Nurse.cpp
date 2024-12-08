/*The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest. A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse must work and the length of the working period is the number of consecutive days of that working period. The hospital imposes two constraints:
Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
The length of each working period must be greater or equal to K1 and less than or equal to K2 (2) 
The director of the hospital want to know how many possible working plans satisfying above constraint?	
Input
 The input consists of one line which contains 3 positive integers N, K
1
, K
2
 (2 <= N <=  1000, K
1 
< K
2
 <= 400)
Output
The output consists of only one single integer M modulo 10^9+7 where M is the total working plans satisfying the above constraints.

Example
Input
6 2 3
Output
4*/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    vector<vector<long long>> f(N + 1, vector<long long>(2, 0));

    f[0][0] = 1;  
    f[0][1] = 1; 

    for (int i = 1; i <= N; ++i) {
        f[i][0] = f[i - 1][1];

        for (int j = K1; j <= K2; ++j) {
            if (i - j >= 0) {
                f[i][1] = (f[i][1] + f[i - j][0]) % MOD;
            }
        }
    }

    long long result = (f[N][0] + f[N][1]) % MOD;
    cout << result << endl;

    return 0;
}
