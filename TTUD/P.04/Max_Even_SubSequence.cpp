/*Given a sequence of n integers a=a1, . . ., an. A subsequence of a consists of contiguous elements of a (for example, ai, ai+1, . . . ,aj). The weight of a subsequence is defined to be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. Find the even-subsequence of a having largest weight.
Input
Line 1: contains a positive integer n (1 <= n <= 10^6)
Line 2: contains a1, . . ., an (-10^6 <= ai <= 10^6)
Output
The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.
Example
Input
4
1  2  -3  4
Output
4*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const long long INF = 1e18;
int n;
long long a[MAXN];

long long findLargestEvenSubsequence() {
    long long maxEven = -INF;
    long long sum = 0;
    long long minOddPrefix = INF;
    long long minEvenPrefix = 0;
    
    // Với mỗi vị trí kết thúc j, tìm prefix tốt nhất để trừ
    for(int j = 0; j < n; j++) {
        sum += a[j];
        
        // Nếu tổng hiện tại chẵn
        if(sum % 2 == 0) {
            maxEven = max(maxEven, sum);
        }
        
        // Cập nhật prefix nhỏ nhất theo tính chất chẵn/lẻ
        if(sum % 2 == 0) {
            maxEven = max(maxEven, sum - minEvenPrefix);
        } else {
            if(minOddPrefix != INF) {
                maxEven = max(maxEven, sum - minOddPrefix);
            }
        }
        
        // Cập nhật prefix nhỏ nhất
        if(sum % 2 == 0) {
            minEvenPrefix = min(minEvenPrefix, sum);
        } else {
            minOddPrefix = min(minOddPrefix, sum);
        }
    }
    
    return maxEven;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Đọc input
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Tìm kết quả
    long long result = findLargestEvenSubsequence();
    
    // In kết quả
    if(result == -INF) {
        cout << "NOT_FOUND\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}
