/*Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xN (0≤ xi ≤1,000,000,000).
The distance of a subset of N elements is defined to be the minimum distance between two elements.
Find the subset of N given elements containing exactly C elements such that the distance is maximal.
Input
The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
Subsequent lines are T test cases with the following format:
Line 1: Two space-separated integers: N and C
Lines 2: contains  x1, x
2
, . . . , x
N

Output
For each test case output one integer: the distance of the subset found.

Example
input
1
5 3
1 2 8 4 9
output
3

Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.*/
#include <bits/stdc++.h>

using namespace std;

bool canPlaceCows(const vector<int>& positions, int N, int C, int minDist) {
    int count = 1;
    int lastPosition = positions[0];

    for (int i = 1; i < N; ++i) {
        if (positions[i] - lastPosition >= minDist) {
            count++;
            lastPosition = positions[i];
        }
        if (count >= C) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;
        vector<int> positions(N);

        for (int i = 0; i < N; ++i) {
            cin >> positions[i];
        }

        sort(positions.begin(), positions.end());

        int left = 0;
        int right = positions[N - 1] - positions[0];
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceCows(positions, N, C, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}
