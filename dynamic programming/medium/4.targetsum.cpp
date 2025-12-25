#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int totalSum = 0;
    for (int x : nums) totalSum += x;

    // Edge cases
    if (totalSum < abs(target) || (totalSum + target) % 2 != 0)
        return 0;

    int P = (totalSum + target) / 2;

    vector<int> dp(P + 1, 0);
    dp[0] = 1; // one way to make sum 0

    for (int num : nums) {
        for (int j = P; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[P];
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Number of ways: "
         << findTargetSumWays(nums, target) << endl;

    return 0;
}
