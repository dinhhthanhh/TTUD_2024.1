/*Given a sequence of integers a1, a2, ..., an. A pair (i, j) is call an inversion if i < j and ai > aj. Compute the number Q of inversions
Input
Line 1: contains a positive integer n (1 <= n <= 10
6
)
Line 2: contains a
1
, a
2
, ..., a
n
 (0 <= a
i
<= 10
6
)
Output
Write the value Q modulo 10
9
+7

Example
Input
6
3 2 4 5 6 1
Output
6*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    long long invCount = 0;

    // Merging the two halves and counting inversions
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            invCount = (invCount + leftArr.size() - i) % MOD;
        }
    }

    // Copy remaining elements of leftArr, if any
    while (i < leftArr.size()) {
        arr[k++] = leftArr[i++];
    }

    // Copy remaining elements of rightArr, if any
    while (j < rightArr.size()) {
        arr[k++] = rightArr[j++];
    }

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    
    int mid = left + (right - left) / 2;
    long long invCount = 0;

    invCount = (invCount + mergeSortAndCount(arr, left, mid)) % MOD;
    invCount = (invCount + mergeSortAndCount(arr, mid + 1, right)) % MOD;
    invCount = (invCount + mergeAndCount(arr, left, mid, right)) % MOD;

    return invCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long result = mergeSortAndCount(arr, 0, n - 1);
    cout << result << endl;

    return 0;
}
