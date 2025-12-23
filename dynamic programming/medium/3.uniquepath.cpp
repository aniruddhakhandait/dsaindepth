#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);  // First row all 1s

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[n - 1];
}

int main() {
    int m = 3, n = 7;

    cout << "Grid size: " << m << " x " << n << endl;

    int result = uniquePaths(m, n);

    cout << "Number of unique paths: " << result << endl;

    return 0;
}
